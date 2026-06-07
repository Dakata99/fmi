#define DOCTEST_CONFIG_IMPLEMENT

#include "../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../Iterators/Trees iterators/Position.h"
#include "../../test_utils.hpp"
#include "AVL.hpp"
#include "doctest.h"

TEST_CASE("AVL trees tests") {
    AVL<int> t1;

    t1.insert_rec(50);
    t1.insert_rec(10);
    t1.insert_rec(20);

    CHECK(tovector_in_order(t1) == std::vector<int>{10, 20, 50});

    t1.insert_rec(20);
    t1.insert_rec(30);
    t1.insert_rec(15);
    t1.insert_rec(10);
    t1.insert_rec(5);
    t1.insert_rec(25);
    t1.insert_rec(42);
    t1.insert_rec(55);
    t1.insert_rec(33);
    t1.insert_rec(28);

    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 28, 30, 33, 42, 50, 55});

    t1.remove(28);
    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 30, 33, 42, 50, 55});

    t1.remove(30);
    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 33, 42, 50, 55});

    t1.remove(20);
    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 25, 33, 42, 50, 55});
}
