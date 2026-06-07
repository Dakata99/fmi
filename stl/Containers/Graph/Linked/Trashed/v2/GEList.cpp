#include "GEList.h"

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList() : Graph<Vertex, Edge>(), edges() {}

template <class Vertex, class Edge>
GEList<Vertex, Edge>::GEList(const GEList&);

template <class Vertex, class Edge>
GEList<Vertex, Edge>& GEList<Vertex, Edge>::operator=(const GEList& other) {}

template <class Vertex, class Edge>
GEList<Vertex, Edge>::~GEList() {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_vertex(const Vertex&) {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::add_edge(const Vertex&, const Vertex&,
                                    const Edge& = Edge()) {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove_vertex(const Vertex&) {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::remove_edge(const Vertex&, const Vertex&) {}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_vertex(const Vertex&) const {}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_edge(const Vertex&, const Vertex&) const {}

template <class Vertex, class Edge>
bool GEList<Vertex, Edge>::has_way(const Vertex&, const Vertex&) const {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::BFS(void) const {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::DFS(void) const {}

template <class Vertex, class Edge>
void GEList<Vertex, Edge>::print(void) const {}
