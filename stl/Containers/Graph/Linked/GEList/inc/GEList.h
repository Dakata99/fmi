#ifndef _GELIST_H_
#define _GELIST_H_

#include <list>
#include <set>
#include <unordered_map>
#include <vector>

#include "Base/Graph.hpp"

template <class Vertex, class Edge>
class GEList : public Graph<Vertex, Edge> {
private:
    struct Node {
        Vertex vertex1, vertex2;
        Edge edge_weight;
        bool operator==(const Node&) const;
    };

    std::list<Node> edges;

private:
    typedef typename std::list<Node>::iterator list_iterator;
    list_iterator iter;

    void remove(std::list<Node>&, Node);

private:
    void add_oriented_weighted_edge(const Vertex&, const Vertex&,
                                    const Edge& = Edge());
    void add_oriented_non_weighted_edge(const Vertex&, const Vertex&);

    void add_non_oriented_weighted_edge(const Vertex&, const Vertex&,
                                        const Edge& = Edge());
    void add_non_oriented_non_weighted_edge(const Vertex&, const Vertex&);

    void print_weighted(void) const override;
    void print_non_weighted(void) const override;

    virtual void add_vertex(const Vertex&);
    virtual void add_edge(const Vertex& = Vertex(), const Vertex& = Vertex(),
                          const Edge& = Edge());

public:
    GEList(const bool = false, const bool = false);
    GEList(const size_t, const bool = false, const bool = false);
    GEList(const GEList&);
    GEList& operator=(const GEList&);

    void add(const Vertex& = Vertex(), const Vertex& = Vertex(),
             const Edge& = Edge());
    void set(const Vertex& = Vertex(), const Vertex& = Vertex(),
             const Edge& = Edge());

    void remove_vertex(const Vertex&) override;
    void remove_edge(const Vertex&, const Vertex&) override;

    bool has_vertex(const Vertex&) const override;
    bool has_edge(const Vertex&, const Vertex&) const override;

    int enter_degree(const Vertex&) const;
    int exit_degree(const Vertex&) const;

    bool has_way(const Vertex&, const Vertex&) const override;
    bool isolated(const Vertex&) const;

    std::list<Vertex> get_predecessors(const Vertex&) const override;
    std::list<Vertex> get_successors(const Vertex&) const override;

    size_t count_of_vertices(void) const override;
    size_t count_of_edges(void) const override;

    void BFS(const Vertex&) const override;
    void DFS(const Vertex&) const override;

    void print(void) const override;
    void print_degrees(void) const override;
};

#endif
