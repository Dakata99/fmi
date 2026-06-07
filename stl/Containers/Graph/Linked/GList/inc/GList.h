#ifndef _GLIST_H_
#define _GLIST_H_

#include <list>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#include "Base/Graph.hpp"

/* Graph representation with adjacency list */

template <class Vertex, class Edge>
class GList : public Graph<Vertex, Edge> {
private:
    typedef typename std::pair<Vertex, Edge>
        gpair;                               /* pair of vertex and edge value */
    typedef typename std::list<gpair> glist; /* list of pairs */

    std::map<Vertex, glist> set;

    typedef typename std::list<gpair>::iterator list_iterator;
    typedef typename std::map<Vertex, glist>::iterator map_iterator;

private:
    /* additional helper functions */
    void print_weighted(void) const override;
    void print_non_weighted(void) const override;

public:
    /* some constructors/operators */
    GList();
    GList(const bool = false, const bool = false);
    GList(const GList&);

    GList& operator=(const GList&);

    /* basic operations - adding/removing/checking vertex/edge */
    void add_vertex(const Vertex&) override;
    void add_edge(const Vertex&, const Vertex&, const Edge& = Edge()) override;

    void remove_vertex(const Vertex&) override;
    void remove_edge(const Vertex&, const Vertex&) override;

    bool has_vertex(const Vertex&) const override;
    bool has_edge(const Vertex&, const Vertex&) const override;

    /* a vertex's entering and exiting degree */
    int enter_degree(const Vertex&) const override;
    int exit_degree(const Vertex&) const override;

    void print_degrees(void) const override;

    bool has_way(const Vertex&, const Vertex&)
        const override; /* check for a way from one vertex to another */
    bool isolated(
        const Vertex&) const override; /* check if a vertex is isolated */

    /* a vertex's predecessors/successors */
    std::list<Vertex> get_predecessors(const Vertex&) const override;
    std::list<Vertex> get_successors(const Vertex&) const override;

    void print_predecessors(const Vertex&) const;
    void print_successors(const Vertex&) const;

    size_t count_of_vertices(
        void) const; /* total number of vertices in the graph */
    size_t count_of_edges(void) const; /* total number of edges in the graph */

    void BFS(const Vertex&) const override; /* Breadth-First Search */
    void DFS(const Vertex&) const override; /* Depth-First Search */

    void print(void) const override;
};

#endif
