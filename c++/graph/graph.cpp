#include "graph.h"
#include <utility>
#include <iostream>

namespace graph {

using namespace std;

Graph::verticies_t::const_iterator Graph::FindSafe(const string p) {
    return verticies_.find(p);
}

Graph::verticies_t::iterator Graph::Find(const string p) {
    return verticies_.find(p);
}

bool Graph::Insert(const string id) {
    try {
        auto iter = FindSafe(id);
        if(iter == verticies_.end()) {
            verticies_.emplace(std::make_pair(id, Vertex(id)));
            return true;
        }
    } catch(exception&) {
        return false;
    }
    return false;
}

bool Graph::Delete(const string id) {
    try {
        auto iter = FindSafe(id);
        if(iter != verticies_.end()) {
            verticies_.erase(id);
            pruneNeighbors(id);
            return true;
        }
    } catch(exception&) {
        return false;
    }
    return false;
}

bool Graph::Adjacent(const string p, const string q) {
    if(p.size() == q.size() && p == q)
        return false;

    auto piter = FindSafe(p);
    auto qiter = FindSafe(q);

    if(piter == verticies_.end() || qiter == verticies_.end())
        return false;

    for(const auto &neighbor : qiter->second.GetNeighborsSafe()) {
        if(p.size() == neighbor.size() && p == neighbor)
            return true;
    }

    return false;
}

bool Graph::Link(const string p, const string q) {
    if(p.size() == q.size() && p == q)
        return false;

    auto piter = Find(p);
    auto qiter = Find(q);

    if(piter == verticies_.end() || qiter == verticies_.end())
        return false;

    piter->second.AddNeighbor(q);
    qiter->second.AddNeighbor(p);

    return true;
}

bool Graph::Unlink(const string p, const string q) {
    if(p.size() == q.size() && p == q)
        return false;

    auto piter = Find(p);
    auto qiter = Find(q);

    if(piter == verticies_.end() || qiter == verticies_.end())
        return false;

    piter->second.DelNeighbor(q);
    qiter->second.DelNeighbor(p);

    return true;
}

int Graph::pruneNeighbors(const string &id) {
    int i = 0;
    for(auto& v : verticies_) {
        v.second.DelNeighbor(id);
        i++;
    }
    return 0;
}

void Graph::Dump(ostream& s) const {
    for(auto& v : verticies_) {
        s << "[" << v.second.GetId() << "]";
        for(const auto &n : v.second.GetNeighborsSafe()) {
            s << " -> " << n;
        }
        s << endl;
    }
    s << endl;
}

}
