#include "Graph.h"

template <class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(const bool orientation, const bool weight)
    : oriented(orientation), weighted(weight) {}
