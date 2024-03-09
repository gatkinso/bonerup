#include "vertex.h"
#include <unordered_map>

namespace graph {
    class Graph {
    public:
       typedef std::unordered_map<string, Vertex> verticies_t;

        Graph() {}

        verticies_t::const_iterator FindSafe(const string p);
        verticies_t::iterator Find(const string p);

        bool Insert(const string id);
        bool Delete(const string id);

        bool Adjacent(const string p, const string q);
        bool Link(const string p, const string q);
        bool Unlink(const string p, const string q);

        void DFT() {}
        void BFT() {}

        void Dump(ostream& s) const;
        
    private:
        int pruneNeighbors(const string &id);

        verticies_t verticies_;
    };
}