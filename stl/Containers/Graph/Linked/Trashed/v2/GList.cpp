#include "GList.h"

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_oriented_weighted_edge(const Vertex& v1,
                                                     const Vertex& v2,
                                                     const Edge& edge_value) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].vertex == v1) {
            vertices[i].childs.push_back({v2, edge_value});
            break;
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_oriented_non_weighted_edge(const Vertex& v1,
                                                         const Vertex& v2) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].vertex == v1) {
            vertices[i].childs.push_back({v2, Edge()});
            break;
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_non_oriented_weighted_edge(
    const Vertex& v1, const Vertex& v2, const Edge& edge_value) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].vertex == v1) {
            vertices[i].childs.push_back({v2, edge_value});
        } else if (vertices[i].vertex == v2) {
            vertices[i].childs.push_back({v1, edge_value});
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_non_oriented_non_weighted_edge(const Vertex& v1,
                                                             const Vertex& v2) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].vertex == v1) {
            vertices[i].childs.push_back({v2, Edge()});
        } else if (vertices[i].vertex == v2) {
            vertices[i].childs.push_back({v1, Edge()});
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_weighted(void) const {
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "Vertex (" << vertices[i].vertex << ") ---> Childs: [ ";
        std::list<std::pair<Vertex, Edge>> list = vertices[i].childs;
        typename std::list<std::pair<Vertex, Edge>>::iterator it = list.begin();

        for (; it != list.end(); it++) {
            std::cout << "(" << (*it).first << ", " << it->second << ") ";
        }

        std::cout << "]\n";
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_non_weighted(void) const {
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "Vertex (" << vertices[i].vertex << ") ---> Childs: [ ";

        std::list<std::pair<Vertex, Edge>> list = vertices[i].childs;
        typename std::list<std::pair<Vertex, Edge>>::iterator it = list.begin();

        for (; it != list.end(); it++) {
            std::cout << it->first << ", ";
        }

        std::cout << "]\n";
    }
}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList() : Graph<Vertex, Edge>(false, false), vertices() {}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList(const size_t size, const bool orientation,
                           const bool weight)
    : Graph<Vertex, Edge>(orientation, weight) {}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList(const GList<Vertex, Edge>& other) {
    vertices = other.vertices;
}

template <class Vertex, class Edge>
GList<Vertex, Edge>::~GList() {}

template <class Vertex, class Edge>
GList<Vertex, Edge>& GList<Vertex, Edge>::operator=(
    const GList<Vertex, Edge>& other) {
    if (this != &other) {
        vertices.clear();
        vertices = other.vertices;
    }
    return *this;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_vertex(const Vertex& vertex) {
    if (has_vertex(vertex)) {
        return;
    }

    vertices.push_back({vertex, std::list<std::pair<Vertex, Edge>>()});
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_edge(const Vertex& v1, const Vertex& v2,
                                   const Edge& value) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    if (this->oriented && this->weighted) {
        add_oriented_weighted_edge(v1, v2, value);
    } else if (this->oriented && !this->weighted) {
        add_oriented_non_weighted_edge(v1, v2);
    } else if (!this->oriented && this->weighted) {
        add_non_oriented_weighted_edge(v1, v2, value);
    } else {
        add_non_oriented_non_weighted_edge(v1, v2);
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::remove_vertex(const Vertex& vertex) {
    if (!has_vertex(vertex)) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        remove_edge(vertices[i].vertex, vertex);
    }

    typedef typename std::vector<Cell>::iterator iterator;
    iterator it = vertices.begin();

    for (; it != vertices.end(); it++) {
        if (it->vertex == vertex) {
            vertices.erase(it);
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::remove_edge(const Vertex& v1, const Vertex& v2) {
    if (!has_edge(v1, v2)) {
        return;
    }

    typedef typename list::iterator iterator;

    if (this->oriented) /* oriented graph => remove the edge from v1 to v2 */
    {
        for (size_t i = 0; i < vertices.size(); i++) {
            iterator it = vertices[i].childs.begin();

            if (vertices[i].vertex == v1) {
                for (; it != vertices[i].childs.end(); it++) {
                    if (it->first == v2) {
                        vertices[i].childs.erase(it);
                        break;
                    }
                }
            }
        }
    } else /* non-oriented graph => remove the edge from v1 to v2 and from v2 to
              v1 */
    {
        for (size_t i = 0; i < vertices.size(); i++) {
            iterator it = vertices[i].childs.begin();

            if (vertices[i].vertex == v1) {
                for (; it != vertices[i].childs.end(); it++) {
                    if (it->first == v2) {
                        vertices[i].childs.erase(it);
                        break;
                    }
                }
            }

            if (vertices[i].vertex == v2) {
                for (; it != vertices[i].childs.end(); it++) {
                    if (it->first == v1) {
                        vertices[i].childs.erase(it);
                        break;
                    }
                }
            }
        }
    }
}

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_vertex(const Vertex& vertex) const {
    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].vertex == vertex) {
            return true;
        }
    }

    return false;
}

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_edge(const Vertex& v1, const Vertex& v2) const {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return false;
    }

    if (this->oriented) {
        for (size_t i = 0; i < vertices.size(); i++) {
            list l = vertices[i].childs;

            if (vertices[i].vertex == v1) {
                for (const std::pair<Vertex, Edge>& p : l) {
                    if (p.first == v2) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        list l = vertices[i].childs;

        if (vertices[i].vertex == v1 || vertices[i].vertex == v2) {
            for (const std::pair<Vertex, Edge>& p : l) {
                if (p.first == v1 || p.first == v2) {
                    return true;
                }
            }
        }
    }

    return false;
}

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_way(const Vertex& v1, const Vertex& v2) const {
    return false;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::BFS(void) const {
    if (vertices.size() == 0) {
        return;
    }

    std::queue<Vertex> verts;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::DFS(void) const {}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print(void) const {
    std::cout << "-------------------------- INFO --------------------------\n";
    if (this->weighted) {
        print_weighted();
    } else {
        print_non_weighted();
    }
    std::cout << "----------------------------------------------------------\n";
}
