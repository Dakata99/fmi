#pragma once
#include <list>
#include <set>

#include "../Graph.h"

template <class Vertex, class Edge>
class GEList : public Graph<Vertex, Edge> {
private:
    struct Node {
        Vertex vertex1, vertex2;
        Edge edge_weight;
        bool operator==(const Node&) const;
    };

    std::list<Node> edges;
    void remove(std::list<Node>& list, Node n);

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

    virtual void add_vertex(const Vertex&);
    virtual void add_edge(const Vertex& = Vertex(), const Vertex& = Vertex(),
                          const Edge& = Edge());

public:
    GEList();
    GEList(const size_t, const bool = false, const bool = false);
    GEList(const GEList&);
    GEList& operator=(const GEList&);
    ~GEList();

    void add(const Vertex& = Vertex(), const Vertex& = Vertex(),
             const Edge& = Edge());
    void set(const Vertex& = Vertex(), const Vertex& = Vertex(),
             const Edge& = Edge());

    void remove_vertex(const Vertex&) override;
    void remove_edge(const Vertex&, const Vertex&) override;

    bool has_vertex(const Vertex&) const override;
    bool has_edge(const Vertex&, const Vertex&) const override;
    bool has_way(const Vertex&, const Vertex&) const override;

    void BFS(const Vertex&) const override;
    void DFS(const Vertex&) const override;

    void print(void) const override;
};

#include "GEList.cpp"
