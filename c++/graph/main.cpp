#include <iostream>
#include "graph.h"

using namespace graph;

int main() {
    Graph g;

    g.Insert("a");
    g.Dump(cout);

    g.Insert("b");
    g.Link("a", "b");
    g.Dump(cout);

    g.Insert("c");
    g.Link("b", "c");
    g.Dump(cout);
    
    g.Insert("d");
    g.Link("d", "b");
    g.Dump(cout);
    
    g.Insert("e");
    g.Unlink("b", "c");
    g.Dump(cout);
    
    g.Insert("a");
    g.Dump(cout);

    return 0;
}
