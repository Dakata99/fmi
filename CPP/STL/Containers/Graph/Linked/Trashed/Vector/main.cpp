#include <iostream>
#include <string>

#include "GEList.h"
#include "GList.h"
#include "GMatrix.h"
#include "Graph.h"

typedef void (*fp_t)(void);

// #include "GListTests.cpp"
#include "GEListTests.cpp"
// #include "GMatrixTests.cpp"

int main(void) {
    // glist_tests();
    gelist_tests();

    return 0;
}
