#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <list>

template <class Vertex, class Edge>
class Graph {
protected:
    bool oriented, weighted;

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

    virtual int enter_degree(const Vertex&) const = 0;
    virtual int exit_degree(const Vertex&) const = 0;

    virtual bool has_way(const Vertex&, const Vertex&) const = 0;
    virtual bool isolated(const Vertex&) const = 0;

    virtual std::list<Vertex> get_predecessors(const Vertex&) const = 0;
    virtual std::list<Vertex> get_successors(const Vertex&) const = 0;

    virtual size_t count_of_vertices(void) const = 0;
    virtual size_t count_of_edges(void) const = 0;

    virtual void BFS(const Vertex&) const = 0;
    virtual void DFS(const Vertex&) const = 0;

    virtual void print(void) const = 0;
    virtual void print_degrees(void) const = 0;
};

#endif
