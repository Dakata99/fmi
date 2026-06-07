#pragma once
#include <tuple>
#include <vector>

#include "Graph.h"

template <class Vertex, class Edge>
class GEList : public Graph<Vertex, Edge> {
private:
    std::vector<std::tuple<Vertex, Vertex, Edge>> edges;

public:
    GEList();
    GEList(const GEList&);
    GEList& operator=(const GEList&);
    ~GEList();

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

#include "GEList.cpp"
