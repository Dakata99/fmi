#include "GList.h"

/*
TODO: find out why i need auto and why without it the iterator brokes up

NOTE:
    If you make some functions constant, then you need to use auto for the
iterators(cause you are changing them) Otherwise should remove constant
functions(like print) and use the defined typedef-ed map/list iterator for
shortcut
*/

#if 1 /* additional helper functions */

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_weighted(void) const {
    typedef typename std::map<Vertex, glist>::iterator map_iterator;
    for (auto it = set.begin(); it != set.end(); it++) {
        std::cout << "Vertex (" << it->first << ") ---> Childs: [ ";

        glist l = set.at(it->first);
        list_iterator iter = l.begin();

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

        glist l = set.at(it->first);
        list_iterator iter = l.begin();

        for (; iter != l.end(); iter++) {
            std::cout << "(" << iter->first << ") ";
        }

        std::cout << "]\n";
    }
}

#endif

#if 1 /* some constructors/operators */

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
GList<Vertex, Edge>& GList<Vertex, Edge>::operator=(const GList& other) {
    if (this != &other) {
        set.clear();
        set = other.set();
    }
    return *this;
}

/* some constructors/operators */
#endif

#if 1 /* basic operations - adding/removing/checking vertex/edge */

template <class Vertex, class Edge>
void GList<Vertex, Edge>::add_vertex(const Vertex& vertex) {
    if (has_vertex(vertex)) {
        return;
    }

    set.insert({vertex, glist()});
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

    for (map_iterator it = set.begin(); it != set.end(); it++) {
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

    glist l = set.at(v1);

    if (this->oriented) {
        for (const gpair& p : l) {
            if (p.first == v2) {
                return true;
            }
        }

        return false;
    }

    for (const gpair& p : l) {
        if (p.first == v2) {
            return true;
        }
    }

    return false;
}

#endif

#if 1 /* a vertex's entering and exiting degree */

template <class Vertex, class Edge>
int GList<Vertex, Edge>::enter_degree(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return -1;
    }

    int counter = 0;

    for (auto it = set.begin(); it != set.end(); it++) {
        for (const gpair& pair : it->second) {
            if (pair.first == vertex) {
                counter++;
            }
        }
    }

    return counter;
}

template <class Vertex, class Edge>
int GList<Vertex, Edge>::exit_degree(const Vertex& vertex) const {
    return (!has_vertex(vertex)) ? -1 : set.at(vertex).size();
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_degrees(void) const {
    for (auto it = set.begin(); it != set.end(); it++) {
        std::cout << "The entry degree of " << it->first
                  << " is: " << enter_degree(it->first) << std::endl;
        std::cout << "The exit degree of " << it->first
                  << " is: " << exit_degree(it->first) << std::endl;
    }
}

#endif

#if 1 /* check for a way from one vertex to another and check if a vertex is \
         isolated */

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::has_way(const Vertex& v1, const Vertex& v2) const {
    if (!(has_vertex(v1) && has_vertex(v2))) {
        return false;
    }

    enum Color { white = 0, grey = 1, black = 2 };

    std::map<Vertex, int> visited;
    for (auto it = set.begin(); it != set.end(); it++) {
        visited[it->first] = white;
    }

    std::stack<Vertex> vertices;
    vertices.push(v1);

    while (!vertices.empty()) {
        Vertex current = vertices.top();
        if (current == v2) {
            return true;
        }

        bool has_unvisited = false;

        glist list = set.at(current);
        Vertex
            next; /* TODO: to choose random vertex, not the first or last one */
        for (list_iterator it = list.begin(); it != list.end();
             it++) { /* check if there is a way */
            if (visited[it->first] == white) {
                has_unvisited = true;
                next = it->first;
                break;
            }
        }

        if (!has_unvisited) {
            visited[current] = black;
            vertices.pop();
        } else {
            vertices.push(next);
            visited[next] = grey;
        }
    }
    return false;
}

template <class Vertex, class Edge>
bool GList<Vertex, Edge>::isolated(const Vertex& vertex) const {
    return has_vertex(vertex) && enter_degree(vertex) == 0 &&
           exit_degree(vertex) == 0;
}

#endif

#if 1 /* a vertex's predecessors/successors */

/* NOTE: for non-oriented graphs the predecessors and successors will be the
 * same vertices */

template <class Vertex, class Edge>
std::list<Vertex> GList<Vertex, Edge>::get_predecessors(
    const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return std::list<Vertex>();
    }

    std::list<Vertex> result;
    for (auto it = set.begin(); it != set.end(); it++) {
        glist list = it->second;
        for (list_iterator iter = list.begin(); iter != list.end(); iter++) {
            if (iter->first == vertex) {
                result.push_back(it->first);
            }
        }
    }

    return result;
}

template <class Vertex, class Edge>
std::list<Vertex> GList<Vertex, Edge>::get_successors(
    const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return std::list<Vertex>();
    }

    std::list<Vertex> result;
    for (auto it = set.at(vertex).begin(); it != set.at(vertex).end(); it++) {
        result.push_back(it->first);
    }

    return result;
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_predecessors(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return;
    }

    std::list<Vertex> list = get_predecessors(vertex);

    std::cout << "Predecessors of (" << vertex << ") are: [ ";
    for (typename std::list<Vertex>::iterator it = list.begin();
         it != list.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << "]\n";
}

template <class Vertex, class Edge>
void GList<Vertex, Edge>::print_successors(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return;
    }

    std::list<Vertex> list = get_successors(vertex);

    std::cout << "Successors of (" << vertex << ") are: [ ";
    for (typename std::list<Vertex>::iterator it = list.begin();
         it != list.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << "]\n";
}

#endif

#if 1 /* total number of vertices/edges in the graph */

template <class Vertex, class Edge>
size_t GList<Vertex, Edge>::count_of_vertices(void) const {
    return set.size();
}

template <class Vertex, class Edge>
size_t GList<Vertex, Edge>::count_of_edges(void) const {
    size_t edges = 0;

    for (auto it = set.begin(); it != set.end(); it++) {
        edges += it->second.size();
    }

    return edges;
}

#endif

#if 1 /* BFS, DFS, print functions */

/* TODO: simplify, cause of too complex solution */
/* Works for both oriented and non-oriented graphs */
template <class Vertex, class Edge>
void GList<Vertex, Edge>::BFS(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return;
    }

    std::cout << "========== BFS ==========\n";

    std::map<Vertex, bool> visited;
    for (auto it = set.begin(); it != set.end(); it++) {
        visited[it->first] = false;
    }

    visited[vertex] = true;

    std::queue<Vertex> actual_vertices, temp_vertices;
    actual_vertices.push(vertex);

    size_t level = 1;
    std::cout << "Level " << level++ << ": " << vertex << std::endl;
    while (!actual_vertices.empty()) {
        temp_vertices = actual_vertices;
        Vertex current;
        while (!temp_vertices.empty()) {
            current = temp_vertices.front();
            temp_vertices.pop();
            actual_vertices.pop();

            for (auto it = set.at(current).begin(); it != set.at(current).end();
                 it++) {
                if (visited[it->first] == false) {
                    actual_vertices.push(it->first);
                }
            }
        }

        if (!actual_vertices.empty()) {
            temp_vertices = actual_vertices;
            std::cout << "Level " << level++ << ": ";
            while (!temp_vertices.empty()) {
                current = temp_vertices.front();
                if (visited[current] == false) {
                    std::cout << current << ' ';
                    visited[current] = true;
                }

                temp_vertices.pop();
            }
            std::cout << std::endl;
        }
    }
    std::cout << "=========================\n";
}

/* Works for both oriented and non-oriented graphs */
template <class Vertex, class Edge>
void GList<Vertex, Edge>::DFS(const Vertex& vertex) const {
    if (!has_vertex(vertex)) {
        return;
    }

    std::cout << "=== DFS : ";

    enum Color { white = 0, grey = 1, black = 2 };

    std::map<Vertex, bool> printable;
    std::map<Vertex, int> visited;

    for (auto it = set.begin(); it != set.end(); it++) {
        visited[it->first] = white;
        printable[it->first] = true;
    }

    std::stack<Vertex> vertices;
    vertices.push(vertex);

    while (!vertices.empty()) {
        Vertex current = vertices.top();
        if (printable[current] == true) {
            std::cout << current << ", ";
        }

        bool has_unvisited = false;

        glist list = set.at(current);
        Vertex
            next; /* TODO: to choose random vertex, not the first or last one */
        for (list_iterator it = list.begin(); it != list.end();
             it++) /* check if there is a way */
        {
            if (visited[it->first] == white) {
                has_unvisited = true;
                next = it->first;
                break; /* it can be missed, but it will always take the last
                          unvisited vertex */
            }
        }

        if (!has_unvisited) {
            visited[current] = black;
            vertices.pop();
        } else {
            vertices.push(next);
            visited[next] = grey;
            printable[current] = false;
        }
    }
    std::cout << std::endl;
}

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

#endif
