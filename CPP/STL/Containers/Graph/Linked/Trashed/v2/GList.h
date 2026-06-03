#pragma once
#include <list>
#include <queue>
#include <vector>

#include "Graph.h"

/* Graph representation with adjacency list */

template <class Vertex, class Edge>
class GList : public Graph<Vertex, Edge> {
private:
    typedef typename std::pair<Vertex, Edge> pair;
    typedef typename std::list<pair> list;

    struct Cell {
        Vertex vertex;
        list childs;
    };

    std::vector<Cell> vertices;

private:
    void add_oriented_weighted_edge(const Vertex&, const Vertex&,
                                    const Edge& = Edge()) override;
    void add_oriented_non_weighted_edge(const Vertex&, const Vertex&) override;
    void add_non_oriented_weighted_edge(const Vertex&, const Vertex&,
                                        const Edge& = Edge()) override;
    void add_non_oriented_non_weighted_edge(const Vertex&,
                                            const Vertex&) override;

    void print_weighted(void) const override;
    void print_non_weighted(void) const override;

public:
    GList();
    GList(const size_t, const bool = false, const bool = false);
    GList(const GList&);
    ~GList();

    GList& operator=(const GList&);

    void add_vertex(const Vertex&) override;
    void add_edge(const Vertex&, const Vertex&, const Edge& = Edge()) override;

    void remove_vertex(const Vertex&) override;
    void remove_edge(const Vertex&, const Vertex&) override;

    bool has_vertex(const Vertex&) const override;
    bool has_edge(const Vertex&, const Vertex&) const override;
    bool has_way(const Vertex&, const Vertex&) const override;

    void BFS(void) const override;
    void DFS(void) const override;

    void print(void) const override;
};

#include "GList.cpp"
