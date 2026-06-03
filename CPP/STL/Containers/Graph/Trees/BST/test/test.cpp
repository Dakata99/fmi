#define DOCTEST_CONFIG_IMPLEMENT

#include "../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../Iterators/Trees iterators/Position.h"
#include "../../test_utils.hpp"
#include "BST.hpp"
#include "doctest.h"

TEST_CASE("Binary search tree tests") {
    BST<int> t1;

    t1.insert_rec(20);
    t1.insert_rec(30);
    t1.insert_rec(15);
    t1.insert_rec(10);
    t1.insert_rec(5);
    t1.insert_rec(25);
    t1.insert_rec(42);

    t1.insert_iter(55);
    t1.insert_iter(33);
    t1.insert_iter(28);

    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 28, 30, 33, 42, 55});

    t1.remove(28);
    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 30, 33, 42, 55});

    t1.remove(30);
    CHECK(tovector_in_order(t1) ==
          std::vector<int>{5, 10, 15, 20, 25, 33, 42, 55});

    t1.remove(20);
    CHECK(tovector_in_order(t1) == std::vector<int>{5, 10, 15, 25, 33, 42, 55});

    std::vector<int> vec = {36, 52, 7, 4, 3, 59, 0, 1, 8, 45, -1, 124, -1};
    BST<int> t2;
    t2.create(vec);
    CHECK(tovector_in_order(t2) ==
          std::vector<int>{-1, 0, 1, 3, 4, 7, 8, 36, 45, 52, 59, 124});

    BTree<int> t3 = t1;
    CHECK(tovector_in_order(t3) == std::vector<int>{5, 10, 15, 25, 33, 42, 55});

    BTree<int> t4(t2);
    CHECK(tovector_in_order(t4) ==
          std::vector<int>{-1, 0, 1, 3, 4, 7, 8, 36, 45, 52, 59, 124});

    CHECK(tovector_pre_order(t1) ==
          std::vector<int>{25, 15, 10, 5, 33, 42, 55});
    CHECK(tovector_in_order(t2) ==
          std::vector<int>{-1, 0, 1, 3, 4, 7, 8, 36, 45, 52, 59, 124});
    CHECK(tovector_post_order(t3) ==
          std::vector<int>{5, 10, 15, 55, 42, 33, 25});

    CHECK(t1.search(6) == false);
    CHECK(t2.height() == 3);

    // NOT CORRECT - TODO
    BTree<int> t(t1);

    CHECK((*t.root_position()) == 25);
    t.root_position().set(10);
    t.root_position().left().set(20);
    t.root_position().right().set(30);
    t.root_position().left().left().set(-1000);

    CHECK(tovector_in_order(t) ==
          std::vector<int>{5, -1000, 20, 10, 30, 42, 55});
    // NOT CORRECT - TODO
}
