#include "vertex.h"

namespace graph {

bool Vertex::AddNeighbor(const string &id) {
    try {
        neighbors_.insert(id);
    } catch (exception&) {
        return false;
    }
    return true;
}

bool Vertex::DelNeighbor(const string &id) {
    try {
        neighbors_.erase(id);
    } catch (exception&) {
        return false;
    }
    return true;
}

}
