#include <iostream>

#include "TreeAlgorithms.h"

int main(void) {
    BTree<int> t;
    t.create();
    pre_order(t);

    std::cout << height(t) << std::endl;

    return 0;
}
