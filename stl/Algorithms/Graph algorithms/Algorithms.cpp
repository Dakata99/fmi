/*
TODO: simplify, cause of too complex solution
TODO: check how it will be for non-oriented graphs
*/

template <class Vertex, class Edge>
void BFS(const Graph<Vertex, Edge> &g, const Vertex &vertex) {
    if (!g.has_vertex(vertex)) {
        return;
    }

    std::cout << "========== BFS ==========\n";

    std::map<Vertex, bool> visited;
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

            std::list<Vertex> list = g.get_successors(current);
            for (typename std::list<Vertex>::iterator it = list.begin();
                 it != list.end(); it++) {
                if (visited[*it] == false) {
                    actual.push(*it);
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

/* TODO: CHECK IF IT WILL BE THE SAME FOR NON-ORIENTED GRAPHS */
template <class Vertex, class Edge>
void DFS(const Graph<Vertex, Edge> &graph, const Vertex &vertex) {
    if (!graph.has_vertex(vertex)) {
        return;
    }

    std::cout << "=== DFS : ";

    enum Color { white = 0, grey = 1, black = 2 };

    std::map<Vertex, bool> printable;
    std::map<Vertex, int> visited;

    visited[vertex] = white;
    printable[vertex] = true;

    std::stack<Vertex> actual;
    actual.push(vertex);

    while (!actual.empty()) {
        Vertex curr = actual.top();
        if (printable[curr]) {
            std::cout << curr << ", ";
        }

        bool has_unvisited = false;

        std::list<Vertex> list = graph.get_successors(curr);
        Vertex next;
        for (typename std::list<Vertex>::iterator it = list.begin();
             it != list.end(); it++) {
            if (visited[*it] == white) {
                has_unvisited = true;
                next = *it;
                printable[next] = true;
                break;
            }
        }

        if (!has_unvisited) {
            visited[curr] = black;
            actual.pop();
        } else {
            actual.push(next);
            visited[next] = grey;
            printable[curr] = false;
        }
    }
    std::cout << std::endl;
}

template <class Vertex, class Edge>
bool is_connected(const Graph<Vertex, Edge> &graph) {
    return false;
}

template <class Vertex, class Edge>
bool contains_path(const Graph<Vertex, Edge> &graph, const Vertex &from,
                   const Vertex &to) {
    return false;
}

template <class Vertex, class Edge>
bool contains_cycle(const Graph<Vertex, Edge> &graph) {
    return false;
}

template <class Vertex, class Edge>
Edge Prim(const Graph<Vertex, Edge> &graph) {
    return Edge();
}

template <class Vertex, class Edge>
Edge Kruskal(const Graph<Vertex, Edge> &graph) {
    return Edge();
}

template <class Vertex, class Edge>
Edge Dijkstra(const Graph<Vertex, Edge> &graph) {
    return Edge();
}

template <class Vertex, class Edge>
void topological_sorting(const Graph<Vertex, Edge> &graph) {}
