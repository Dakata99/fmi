#include <iostream>

#include "Tree.hpp"
#include "doctest.h"

TEST_CASE("1") {
    Tree<int> t1;
    t1.create();
    t1.print2D();

    std::cout << std::endl;

    Tree<int> t2 = t1;
    t2.print2D();

    Tree<int> t3(t2);
    t3.print2D();

    t1.pre_order();
    t2.in_order();
    t3.post_order();

    // std::cout << std::boolalpha << t1.search(6) << std::endl;
    // std::cout << t2.height() << std::endl;
}
