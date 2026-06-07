#include "GEList.h"

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
    } else if (has_vertex(v1) && v2 == Vertex() && edge_value == Edge()) {
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
    } else if (has_vertex(v1) && v2 == Vertex()) {
        set(v1, v2, edge_value);
        return;
    } else if (has_vertex(v1) && has_vertex(v2) && edge_value == Edge()) {
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
    } else if (has_vertex(v1) && v2 == Vertex()) {
        set(v1, v2, Edge());
        return;
    }

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

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList() : Graph<Vertex, Edge>(), edges() {}

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

template <class Vertex, class Edge>
GEList<Vertex, Edge>::~GEList() {}

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
        std::list<Node> temp;
        for (auto it = edges.begin(); it != edges.end(); it++) {
        }
    } else {
        std::set<Vertex> vertices;
        for (auto it = edges.begin(); it != edges.end(); it++) {
            vertices.insert(it->vertex1);
        }

        vertices.erase(vertices.find(vertex));

        // std::list<Node> temp;
        // for(auto it = edges.begin(); it != edges.end(); it++)
        // {
        //     //if(it->vertex1 == vertex) remove(edges, *it);
        //     //else if(it->vertex2 == vertex)
        //         //if(has_edge(it->vertex1, it->vertex2))
        //         //it->vertex2 = Vertex();

        //     if(it->vertex1 == vertex) remove_edge(it->vertex1, it->vertex2);
        //     else if(it->vertex2 == vertex) remove_edge(it->vertex1,
        //     it->vertex2);
        //     //if(it->vertex1 != vertex && it->vertex2 != vertex)
        //     temp.push_back(*it);
        //     //else if(it->vertex2 == vertex) it->vertex2 = Vertex();
        // }

        // edges = temp;

        // for(auto it = edges.begin(); it != edges.end(); it++)
        // {    Vertex v = it->vertex1;
        //     if(it->vertex1 == vertex)
        //         edges.erase(it); /* why erase doesnt work ??? */
        //     else if(it->vertex2 == vertex)
        //         it->vertex2 = Vertex(); }
    }
}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove_edge(const Vertex& v1, const Vertex& v2) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    if (this->oriented) {
        std::list<Node> temp;
        for (auto it = edges.begin(); it != edges.end(); it++) {
        }
    } else {
        std::list<Node> temp;
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (!((it->vertex1 == v1 && it->vertex2 == v2) ||
                  (it->vertex1 == v2 && it->vertex2 == v1))) {
                temp.push_back(*it);
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

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_way(const Vertex&, const Vertex&) const {
    return false;
}

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
