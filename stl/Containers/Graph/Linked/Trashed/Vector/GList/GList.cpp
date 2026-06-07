#include "GList.h"

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_oriented_weighted_edge(const Vertex& v1,
                                                     const Vertex& v2,
                                                     const Edge& edge_value) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].first == v1) {
            vertices[i].second.push_back({v2, edge_value});
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
        if (vertices[i].first == v1) {
            vertices[i].second.push_back({v2, Edge()});
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
        if (vertices[i].first == v1) {
            vertices[i].second.push_back({v2, edge_value});
        } else if (vertices[i].first == v2) {
            vertices[i].second.push_back({v1, edge_value});
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
        if (vertices[i].first == v1) {
            vertices[i].second.push_back({v2, Edge()});
        } else if (vertices[i].first == v2) {
            vertices[i].second.push_back({v1, Edge()});
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_weighted(void) const {
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "Vertex (" << vertices[i].first << ") ---> Childs: [ ";
        std::list<std::pair<Vertex, Edge>> list = vertices[i].second;
        typename std::list<std::pair<Vertex, Edge>>::iterator it = list.begin();

        for (; it != list.end(); it++) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }

        std::cout << "]\n";
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_non_weighted(void) const {
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "Vertex (" << vertices[i].first << ") ---> Childs: [ ";

        std::list<std::pair<Vertex, Edge>> list = vertices[i].second;
        typename std::list<std::pair<Vertex, Edge>>::iterator it = list.begin();

        for (; it != list.end(); it++) {
            std::cout << '(' << it->first << ") ";
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
        remove_edge(vertices[i].first, vertex);
    }

    typedef typename std::vector<pairs>::iterator iterator;
    iterator it = vertices.begin();

    for (; it != vertices.end(); it++) {
        if (it->first == vertex) {
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
            iterator it = vertices[i].second.begin();

            if (vertices[i].first == v1) {
                for (; it != vertices[i].second.end(); it++) {
                    if (it->first == v2) {
                        vertices[i].second.erase(it);
                        break;
                    }
                }
            }
        }
    } else /* non-oriented graph => remove the edge from v1 to v2 and from v2 to
              v1 */
    {
        for (size_t i = 0; i < vertices.size(); i++) {
            iterator it = vertices[i].second.begin();

            if (vertices[i].first == v1) {
                for (; it != vertices[i].second.end(); it++) {
                    if (it->first == v2) {
                        vertices[i].second.erase(it);
                        break;
                    }
                }
            }

            if (vertices[i].first == v2) {
                for (; it != vertices[i].second.end(); it++) {
                    if (it->first == v1) {
                        vertices[i].second.erase(it);
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
        if (vertices[i].first == vertex) {
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
            list l = vertices[i].second;

            if (vertices[i].first == v1) {
                for (const pair& p : l) {
                    if (p.first == v2) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        list l = vertices[i].second;

        if (vertices[i].first == v1 || vertices[i].first == v2) {
            for (const pair& p : l) {
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
void GList<Vertex, Edge>::BFS(const Vertex& vertex) const {
    if (vertices.size() == 0 || !has_vertex(vertex)) {
        return;
    }

    size_t level = 1;
    std::cout << "Level " << level++ << ": " << vertex << std::endl;

    std::map<Vertex, bool> printed;

    for (size_t i = 0; i < vertices.size(); i++) {
        printed[vertices[i].first] = false;
    }

    printed[vertex] = true;

    std::queue<Vertex> verts;
    verts.push(vertex);

    while (!verts.empty()) {
        size_t size = verts.size();

        Vertex v = verts.front();
        verts.pop();

        for (size_t j = 0; j < verts.size(); j++) {
            for (size_t i = 0; i < vertices.size(); i++) {
                if (vertices[i].first == v && !vertices[i].second.empty()) {
                    std::cout << "Level " << level++ << ": ";
                    for (const pair& p : vertices[i].second) {
                        if (printed[p.first] == false) {
                            std::cout << p.first << ' ';
                            printed[p.first] = true;
                            verts.push(p.first);
                        }
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::DFS(const Vertex& vertex) const {}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print(void) const {
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
