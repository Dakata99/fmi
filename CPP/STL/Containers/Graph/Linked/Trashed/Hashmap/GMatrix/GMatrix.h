#pragma once
#include <vector>

#include "Graph.h"

/* Graph representation with adjacency matrix */

template <class T>
class GMatrix {
private:
    std::vector<std::vector<T>> matrix;

public:
    GMatrix();
};

#include "GMatrix.cpp"
