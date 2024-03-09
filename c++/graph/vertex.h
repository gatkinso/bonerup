#pragma once

#include <string>
#include <set>

using namespace std;

namespace graph {

    class Vertex {
    public:
        typedef set<string> neighbor_t;

        Vertex() = delete;
        Vertex(const string id)
        : id_(id) {}

        bool AddNeighbor(const string &id);
        bool DelNeighbor(const string &id);

        const string& GetId() const { return id_; }
        const neighbor_t& GetNeighborsSafe() const { return neighbors_; };

    private:
        string id_;
        neighbor_t neighbors_;
    };
}