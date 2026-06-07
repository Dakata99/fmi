#include <iostream>

#include "../GEList/GEList.h"
#include "../GList/GList.h"
#include "Algorithms.h"

void tests(void) {
    GList<int, int> g(true, false);
    for (size_t i = 1; i <= 12; i++) {
        g.add_vertex(i);
    }

#if 1
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    g.add_edge(4, 7);
    g.add_edge(5, 8);
    g.add_edge(5, 9);
    g.add_edge(6, 7);
    g.add_edge(6, 10);
    g.add_edge(6, 11);
    g.add_edge(7, 8);
    g.add_edge(10, 11);
    g.add_edge(11, 12);
#endif

    // for(int i = 1; i <= 12; i++) { g.BFS(i); BFS(g, i); }
    // for(int i = 1; i <= 12; i++) { g.DFS(i); DFS(g, i); }
}

int main(void) {
    tests();

    return 0;
}
