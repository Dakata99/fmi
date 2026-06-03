#include "GList.h"

/* TODO: find out why i need auto and why without it the iterator brokes up */

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_oriented_weighted_edge(const Vertex& v1,
                                                     const Vertex& v2,
                                                     const Edge& edge_value) {}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_oriented_non_weighted_edge(const Vertex& v1,
                                                         const Vertex& v2) {}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_non_oriented_weighted_edge(
    const Vertex& v1, const Vertex& v2, const Edge& edge_value) {}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_non_oriented_non_weighted_edge(const Vertex& v1,
                                                             const Vertex& v2) {
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_weighted(void) const {
    for (auto it = set.begin(); it != set.end(); it++) {
        std::cout << "Vertex (" << it->first << ") ---> Childs: [ ";
        list l = set.at(it->first);
        auto iter = l.begin();

        for (; iter != l.end(); iter++) {
            std::cout << "(" << iter->first << ", " << iter->second << ") ";
        }

        std::cout << "]\n";
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_non_weighted(void) const {
    for (auto it = set.begin(); it != set.end(); it++) {
        std::cout << "Vertex (" << it->first << ") ---> Childs: [ ";
        list l = set.at(it->first);
        auto iter = l.begin();

        for (; iter != l.end(); iter++) {
            std::cout << "(" << iter->first << ") ";
        }

        std::cout << "]\n";
    }
}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList() : Graph<Vertex, Edge>(), set() {}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList(const bool oriented, const bool weight)
    : Graph<Vertex, Edge>(oriented, weight) {}

template <class Vertex, class Edge>
GList<Vertex, Edge>::GList(const GList& other) {
    set = other.set;
}

template <class Vertex, class Edge>
GList<Vertex, Edge>::~GList() {}

template <class Vertex, class Edge>
GList<Vertex, Edge>& GList<Vertex, Edge>::operator=(const GList& other) {
    if (this != &other) {
        set.clear();
        set = other.set();
    }
    return *this;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_vertex(const Vertex& vertex) {
    if (has_vertex(vertex)) {
        return;
    }

    set.insert({vertex, list()});
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_edge(const Vertex& v1, const Vertex& v2,
                                   const Edge& edge_value) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    if (this->oriented && this->weighted) {
        set[v1].push_back({v2, edge_value});
    } else if (this->oriented && !this->weighted) {
        set[v1].push_back({v2, Edge()});
    } else if (!this->oriented && this->weighted) {
        set[v1].push_back({v2, edge_value});
        set[v2].push_back({v1, edge_value});
    } else {
        set[v1].push_back({v2, Edge()});
        set[v2].push_back({v1, Edge()});
    }
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::remove_vertex(const Vertex& vertex) {
    if (!has_vertex(vertex)) {
        return;
    }

    for (auto it = set.begin(); it != set.end(); it++) {
        remove_edge(it->first, vertex);
        remove_edge(vertex, it->first);
    }

    set.erase(set.find(vertex));
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::remove_edge(const Vertex& v1, const Vertex& v2) {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return;
    }

    list_iterator it = set[v1].begin();

    if (this->oriented) {
        for (; it != set[v1].end(); it++) {
            if (it->first == v2) {
                set[v1].erase(it);
                break;
            }
        }
    } else {
        for (; it != set[v1].end(); it++) {
            if (it->first == v2) {
                set[v1].erase(it);
                break;
            }
        }

        for (it = set[v2].begin(); it != set[v2].end(); it++) {
            if (it->first == v1) {
                set[v2].erase(it);
                break;
            }
        }
    }
}

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_vertex(const Vertex& vertex) const {
    for (auto it = set.begin(); it != set.end(); it++) {
        if (it->first == vertex) {
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

    list l = set.at(v1);

    if (this->oriented) {
        for (const pair& p : l) {
            if (p.first == v2) {
                return true;
            }
        }

        return false;
    }

    for (const pair& p : l) {
        if (p.first == v2) {
            return true;
        }
    }

    return false;
}

/* TODO */
template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_way(const Vertex& v1, const Vertex& v2) const {
    return false;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::BFS(const Vertex& vertex)
    const /* TODO: simplify, cause of too complex solution */
{
    /* this is for oriented graphs, need to check how it will be to non-oriented
     * ones */
    if (!has_vertex(vertex)) {
        return;
    }

    std::cout << "========== BFS ==========\n";

    std::map<Vertex, bool> visited;
    for (auto it = set.begin(); it != set.end(); it++) {
        visited[it->first] = false;
    }

    visited[vertex] = true;

    std::queue<Vertex> actual, temporary;
    actual.push(vertex);

    size_t level = 1;
    std::cout << "Level " << level++ << ": " << vertex << std::endl;
    while (!actual.empty()) {
        temporary = actual;
        Vertex current;
        while (!temporary.empty()) {
            current = temporary.front();
            temporary.pop();
            actual.pop();

            for (auto it = set.at(current).begin(); it != set.at(current).end();
                 it++) {
                if (visited[it->first] == false) {
                    actual.push(it->first);
                }
            }
        }

        if (!actual.empty()) {
            temporary = actual;
            std::cout << "Level " << level++ << ": ";
            while (!temporary.empty()) {
                current = temporary.front();
                if (visited[current] == false) {
                    std::cout << current << ' ';
                    visited[current] = true;
                }

                temporary.pop();
            }
            std::cout << std::endl;
        }
    }
    std::cout << "=========================\n";
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::DFS(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return;
    }

    std::map<Vertex, bool> visited;
    for (auto it = set.begin(); it != set.end(); it++) {
        visited[it->first] = false;
    }

    visited[vertex] = true;

    std::stack<Vertex> actual;
}
/* TODO */

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
