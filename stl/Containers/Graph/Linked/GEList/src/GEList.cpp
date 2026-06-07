#include "GEList.h"

#if 1 /* additional helper functions */

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::Node::operator==(const Node& node) const {
    return vertex1 == node.vertex1 && vertex2 == node.vertex2 &&
           edge_weight == node.edge_weight;
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_oriented_weighted_edge(const Vertex& v1,
                                                      const Vertex& v2,
                                                      const Edge& edge_value) {
    if (has_edge(v1, v2)) {
        return;
    } else if (isolated(v1)) {
        set(v1, v2, edge_value);
        return;
    } else if (has_vertex(v1) && has_vertex(v2) && edge_value == Edge()) {
        set(v1, v2, edge_value);
        return;
    }

    Node node = {v1, v2, edge_value};
    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (*it == node) {
            return;
        }
    }

    edges.push_back(node);
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_oriented_non_weighted_edge(const Vertex& v1,
                                                          const Vertex& v2) {
    if (has_edge(v1, v2)) {
        return;
    } else if (has_vertex(v1) && v2 == Vertex()) {
        set(v1, v2, Edge());
        return;
    }

    Node node = {v1, v2, Edge()};
    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (*it == node) {
            return;
        }
    }

    edges.push_back(node);
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_non_oriented_weighted_edge(
    const Vertex& v1, const Vertex& v2, const Edge& edge_value) {
    if (has_edge(v1, v2)) {
        return;
    } else if (isolated(v1)) {
        set(v1, v2, edge_value);
        return;
    }
    // else if(has_vertex(v1) && v2 == Vertex()) { set(v1, v2, edge_value);
    // return ;}
    else if (has_vertex(v1) && has_vertex(v2) && edge_value == Edge()) {
        set(v1, v2, Edge());
        return;
    }

    Node node1 = {v1, v2, edge_value}, node2 = {v2, v1, edge_value};

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (*it == node1 || *it == node2) {
            return;
        }
    }

    edges.push_back(node1);
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_non_oriented_non_weighted_edge(
    const Vertex& v1, const Vertex& v2) {
    if (has_edge(v1, v2)) {
        return;
    } else if (isolated(v1)) {
        set(v1, v2, Edge());
        return;
    }
    // else if(has_vertex(v1) && v2 == Vertex()) { set(v1, v2, Edge()); return
    // ;}

    Node node1 = {v1, v2, Edge()}, node2 = {v2, v1, Edge()};

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (*it == node1 || *it == node2) {
            return;
        }
    }

    edges.push_back(node1);
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::print_weighted(void) const {
    std::cout << "Edge list: \n[\n";
    for (auto it = edges.begin(); it != edges.end(); it++) {
        std::cout << "\t(" << it->vertex1;
        if (it->vertex2 == Vertex()) {
            std::cout << ")\n";
            continue;
        }
        std::cout << ", " << it->vertex2 << ", " << it->edge_weight << ")\n";
    }

    std::cout << "]\n";
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::print_non_weighted(void) const {
    std::cout << "Edge list: \n[\n";
    for (auto it = edges.begin(); it != edges.end(); it++) {
        std::cout << "\t(" << it->vertex1;
        if (it->vertex2 == "") {
            std::cout << ")\n";
            continue;
        }
        std::cout << ", " << it->vertex2 << ")\n";
    }

    std::cout << "]\n";
}

#endif

#if 1 /* some constructors/operators */

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList(const bool orientation, const bool weight)
    : Graph<Vertex, Edge>(orientation, weight) {}

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList(const size_t size, const bool orientation,
                             const bool weight)
    : Graph<Vertex, Edge>(orientation, weight), edges() {}

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList(const GEList& other) {
    edges = other.edges;
}

template <class Vertex, class Edge>
GEList<Vertex, Edge>& GEList<Vertex, Edge>::operator=(const GEList& other) {
    if (this != &other) {
        edges.clear();
        edges = other.edges;
    }
    return *this;
}

#endif

#if 1 /* basic operations - adding/removing/checking vertex/edge */

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_vertex(const Vertex& vertex) {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add(const Vertex& v1, const Vertex& v2,
                               const Edge& edge_value) {
    if (has_edge(v1, v2)) {
        return;
    }

    if (this->oriented && this->weighted) {
        add_oriented_weighted_edge(v1, v2, edge_value);
    } else if (this->oriented && !this->weighted) {
        add_oriented_non_weighted_edge(v1, v2);
    } else if (!this->oriented && this->weighted) {
        add_non_oriented_weighted_edge(v1, v2, edge_value);
    } else {
        add_oriented_non_weighted_edge(v1, v2);
    }
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::set(const Vertex& v1, const Vertex& v2,
                               const Edge& edge_value) {
    if (!has_vertex(v1)) {
        return;
    }

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->vertex1 == v1) {
            it->vertex2 = v2;
            it->edge_weight = edge_value;
            break;
        }
    }
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_edge(const Vertex& v1, const Vertex& v2,
                                    const Edge& edge_value) {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove(std::list<Node>& list, Node n) {
    std::list<Node> temp = list;
    temp.remove(n);
    list = temp;
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove_vertex(const Vertex& vertex) {
    if (!has_vertex(vertex)) {
        return;
    }

    if (this->oriented) {
        /* remove_edge(vertex, ?) and remove_edge(?, vertex) */

        std::vector<Node> temp;
        for (auto it = edges.begin(); it != edges.end(); it++) {
            temp.push_back(*it);
        }

        // for(size_t i = 0; i < temp.size(); i++)
        // std::cout << temp[i].vertex1 << " - " << temp[i].vertex2 <<
        // std::endl;

        for (iter = edges.begin(); iter != edges.end(); iter++) {
            Vertex v1 = iter->vertex1, v2 = iter->vertex2;
            if (iter->vertex1 == vertex) {
                remove_edge(vertex, iter->vertex2);
            } else if (iter->vertex2 == vertex) {
                remove_edge(iter->vertex1, vertex);
            }
        }
    } else {
    }
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove_edge(const Vertex& v1, const Vertex& v2) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    if (this->oriented) {
        bool isolateV1 = exit_degree(v1) == 1 && enter_degree(v1) == 0;
        bool isolateV2 = exit_degree(v2) == 0 && enter_degree(v2) == 1;

        if (isolateV1) {
            edges.push_back({v1, Vertex(), Edge()});
        }
        if (isolateV2) {
            edges.push_back({v2, Vertex(), Edge()});
        }

        std::list<Node> temp = edges;
        for (auto iter = temp.begin(); iter != temp.end(); iter++) {
            if (iter->vertex1 == v1 && iter->vertex2 == v2) {
                temp.erase(iter);
                break;
            }
        }

        edges = temp;
    } else {
        std::list<Node> temp;
        for (; iter != edges.end(); iter++) {
            if (!((iter->vertex1 == v1 && iter->vertex2 == v2) ||
                  (iter->vertex1 == v2 && iter->vertex2 == v1))) {
                temp.push_back(*iter);
            }
        }

        edges = temp;
    }
}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_vertex(const Vertex& vertex) const {
    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->vertex1 == vertex || it->vertex2 == vertex) {
            return true;
        }
    }

    return false;
}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_edge(const Vertex& v1, const Vertex& v2) const {
    if (this->oriented) {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (it->vertex1 == v1 && it->vertex2 == v2) {
                return true;
            }
        }
    } else {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (it->vertex1 == v1 && it->vertex2 == v2) {
                return true;
            } else if (it->vertex1 == v2 && it->vertex2 == v1) {
                return true;
            }
        }
    }

    return false;
}

#endif

#if 1 /* a vertex's entering and exiting degree */

template <class Vertex, class Edge>
int GEList<Vertex, Edge>::enter_degree(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return -1;
    }

    int counter = 0;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->vertex1 != Vertex() && it->vertex2 == vertex) {
            counter++;
        }
    }

    return counter;
}

template <class Vertex, class Edge>
int GEList<Vertex, Edge>::exit_degree(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return -1;
    }

    int counter = 0;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->vertex1 == vertex && it->vertex2 != Vertex()) {
            counter++;
        }
    }

    return counter;
}

#endif

#if 1 /* check for a way from one vertex to another and check if a vertex is \
         isolated */

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_way(const Vertex&, const Vertex&) const {
    return false;
}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::isolated(const Vertex& vertex) const {
    return has_vertex(vertex) && enter_degree(vertex) == 0 &&
           exit_degree(vertex) == 0;
}

#endif

#if 1 /* a vertex's predecessors/successors */

template <class Vertex, class Edge>
std::list<Vertex> GEList<Vertex, Edge>::get_predecessors(
    const Vertex& vertex) const {
    return std::list<Vertex>();
}

template <class Vertex, class Edge>
std::list<Vertex> GEList<Vertex, Edge>::get_successors(
    const Vertex& vertex) const {
    return std::list<Vertex>();
}

#endif

#if 1 /* total number of vertices/edges in the graph */

template <class Vertex, class Edge>
size_t GEList<Vertex, Edge>::count_of_vertices(void) const {
    return 0;
}

template <class Vertex, class Edge>
size_t GEList<Vertex, Edge>::count_of_edges(void) const {
    return 0;
}

#endif

#if 1 /* BFS, DFS, print, print_degrees functions */

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::BFS(const Vertex& vertex) const {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::DFS(const Vertex& vertex) const {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::print(void) const {
    std::cout << "\n*************************************************\n";
    if (this->oriented) {
        std::cout << "----- ORIENTED ";
    } else {
        std::cout << "----- NON-ORIENTED ";
    }

    if (this->weighted) {
        std::cout << "WEIGHTED GRAPH INFO -----\n";
        print_weighted();
    } else {
        std::cout << "NON-WEIGHTED GRAPH INFO -----\n";
        print_non_weighted();
    }

    std::cout << "*************************************************\n\n";
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::print_degrees(void) const {
    std::unordered_map<Vertex, bool> visited;
    for (auto iter = edges.begin(); iter != edges.end(); iter++) {
        visited[iter->vertex1] = false;
    }

    for (typename std::unordered_map<Vertex, bool>::iterator it =
             visited.begin();
         it != visited.end(); it++) {
        Vertex current = it->first;
        std::cout << "The entry degree of " << current
                  << " is: " << enter_degree(current) << std::endl;
        std::cout << "The exit degree of " << current
                  << " is: " << exit_degree(current) << std::endl;
    }
}

#endif
