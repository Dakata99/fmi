#include "GMatrix.h"

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::print_weighted(void) const {}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::print_non_weighted(void) const {}

template <class Vertex, class Edge>
GMatrix<Vertex, Edge>::GMatrix() {}

template <class Vertex, class Edge>
GMatrix<Vertex, Edge>::GMatrix(const bool orientation, const bool weight)
    : Graph<Vertex, Edge>(orientation, weight) {}

template <class Vertex, class Edge>
GMatrix<Vertex, Edge>::GMatrix(const GMatrix& other) {
    matrix = other.matrix;
}

template <class Vertex, class Edge>
GMatrix<Vertex, Edge>::~GMatrix() {}

template <class Vertex, class Edge>
GMatrix<Vertex, Edge>& GMatrix<Vertex, Edge>::operator=(const GMatrix& other) {
    if (this != &other) {
        matrix.clear();
        matrix = other.matrix;
    }
    return *this;
}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::add_vertex(const Vertex& vertex) {
    if (has_vertex(vertex)) {
        return;
    }

    matrix.insert({{vertex, Vertex()}, Edge()});
}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::add_edge(const Vertex& v1, const Vertex& v2,
                                     const Edge& edge_weight) {
    if (!(has_vertex(v1) && has_vertex(v2)) || has_edge(v1, v2)) {
        return;
    }
}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::remove_vertex(const Vertex& vertex) {}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::remove_edge(const Vertex& v1, const Vertex& v2) {}

template <class Vertex, class Edge>
bool GMatrix<Vertex, Edge>::has_vertex(const Vertex& vertex) const {
    for (auto it = matrix.begin(); it != matrix.end(); it++) {
        if (it->first.first == vertex || it->first.second == vertex) {
            return true;
        }
    }

    return false;
}

template <class Vertex, class Edge>
bool GMatrix<Vertex, Edge>::has_edge(const Vertex&, const Vertex&) const {
    return false;
}

template <class Vertex, class Edge>
int GMatrix<Vertex, Edge>::enter_degree(const Vertex&) const {
    return 0;
}

template <class Vertex, class Edge>
int GMatrix<Vertex, Edge>::exit_degree(const Vertex&) const {
    return 0;
}

template <class Vertex, class Edge>
bool GMatrix<Vertex, Edge>::has_way(const Vertex&, const Vertex&) const {
    return false;
}

template <class Vertex, class Edge>
bool GMatrix<Vertex, Edge>::isolated(const Vertex&) const {
    return false;
}

template <class Vertex, class Edge>
std::list<Vertex> GMatrix<Vertex, Edge>::get_predecessors(const Vertex&) const {
    return std::list<Vertex>();
}

template <class Vertex, class Edge>
std::list<Vertex> GMatrix<Vertex, Edge>::get_successors(const Vertex&) const {
    return std::list<Vertex>();
}

template <class Vertex, class Edge>
size_t GMatrix<Vertex, Edge>::count_of_vertices(void) const {
    return 0;
}

template <class Vertex, class Edge>
size_t GMatrix<Vertex, Edge>::count_of_edges(void) const {
    return 0;
}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::BFS(const Vertex&) const {}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::DFS(const Vertex&) const {}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::print(void) const {}

template <class Vertex, class Edge>
void GMatrix<Vertex, Edge>::print_degrees(void) const {}
