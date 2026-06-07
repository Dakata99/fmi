#pragma once
#include <iostream>

template <class Vertex, class Edge>
class Graph {
protected:
    bool oriented, weighted;

    virtual void add_oriented_weighted_edge(const Vertex&, const Vertex&,
                                            const Edge& = Edge()) = 0;
    virtual void add_oriented_non_weighted_edge(const Vertex&,
                                                const Vertex&) = 0;

    virtual void add_non_oriented_weighted_edge(const Vertex&, const Vertex&,
                                                const Edge& = Edge()) = 0;
    virtual void add_non_oriented_non_weighted_edge(const Vertex&,
                                                    const Vertex&) = 0;

    virtual void print_weighted(void) const = 0;
    virtual void print_non_weighted(void) const = 0;

public:
    Graph(const bool = false, const bool = false);

    virtual void add_vertex(const Vertex&) = 0;
    virtual void add_edge(const Vertex&, const Vertex&,
                          const Edge& = Edge()) = 0;

    virtual void remove_vertex(const Vertex&) = 0;
    virtual void remove_edge(const Vertex&, const Vertex&) = 0;

    virtual bool has_vertex(const Vertex&) const = 0;
    virtual bool has_edge(const Vertex&, const Vertex&) const = 0;
    virtual bool has_way(const Vertex&, const Vertex&) const = 0;

    virtual void BFS(const Vertex&) const = 0;
    virtual void DFS(const Vertex&) const = 0;

    virtual void print(void) const = 0;
};

#include "Graph.cpp"
