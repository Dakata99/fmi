#ifndef _GRAPH_ALGS_H_
#define _GRAPH_ALGS_H_

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>

#include "../Graph.h"

/* TODO: simplify, cause of too complex solution */
template <class Vertex, class Edge>
void BFS(const Graph<Vertex, Edge>&, const Vertex&);

/* TO CHECK IF IT WILL BE THE SAME FOR NON-ORIENTED GRAPHS */
template <class Vertex, class Edge>
void DFS(const Graph<Vertex, Edge>&, const Vertex&);

template <class Vertex, class Edge>
bool is_connected(const Graph<Vertex, Edge>&);

template <class Vertex, class Edge>
bool contains_path(const Graph<Vertex, Edge>&, const Vertex&, const Vertex&);

template <class Vertex, class Edge>
bool contains_cycle(const Graph<Vertex, Edge>&);

template <class Vertex, class Edge>
Edge Prim(const Graph<Vertex, Edge>&);

template <class Vertex, class Edge>
Edge Kruskal(const Graph<Vertex, Edge>&);

template <class Vertex, class Edge>
Edge Dijkstra(const Graph<Vertex, Edge>&);

template <class Vertex, class Edge>
void topological_sorting(const Graph<Vertex, Edge>&);

#include "Algorithms.cpp"

#endif
