#include "../../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../../Iterators/Trees iterators/Position.h"
#include "../../../test_utils.hpp"
#include "BTree.hpp"
#include "doctest.h"

TEST_CASE("Binary tree/Position tests") {
    BTree<int> t1;
    t1.root_position().set(1);
    t1.root_position().left().set(2);
    t1.root_position().right().set(5);
    t1.root_position().left().left().set(3);
    t1.root_position().left().right().set(4);
    t1.root_position().right().right().set(6);

    CHECK(tovector_in_order(t1) == std::vector<int>{3, 2, 4, 1, 5, 6});

    BTree<int> t2 = t1;
    CHECK(tovector_in_order(t2) == std::vector<int>{3, 2, 4, 1, 5, 6});

    BTree<int> t3(t2);
    CHECK(tovector_in_order(t3) == std::vector<int>{3, 2, 4, 1, 5, 6});

    CHECK(tovector_pre_order(t1) == std::vector<int>{1, 2, 3, 4, 5, 6});
    CHECK(tovector_in_order(t2) == std::vector<int>{3, 2, 4, 1, 5, 6});
    CHECK(tovector_post_order(t3) == std::vector<int>{3, 4, 2, 6, 5, 1});

    CHECK(t1.search(6) == true);
    CHECK(t2.height() == 2);

    BTree<int> t(t1);

    CHECK((*t.root_position()) == 1);
    t.root_position().set(10);
    t.root_position().left().set(20);
    t.root_position().right().set(30);
    t.root_position().left().left().set(-1000);

    CHECK(tovector_in_order(t) == std::vector<int>{-1000, 20, 4, 10, 30, 6});

    BTree<int> t4;
    std::vector<int> vec = {-12, 24, -3, 43, 53, 16, -75, 81, 94, 120};
    t4.create(vec);
    CHECK(tovector_in_order(t4) == vec);
}

TEST_CASE("Iterator tests") {}
