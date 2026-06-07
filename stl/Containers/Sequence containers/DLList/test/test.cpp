#include "DLList.hpp"
#include "Iterator.hpp"
#include "doctest.h"
#include "test_utils.hpp"

DLList<int> list;

TEST_CASE("Constructors tests") {
    CHECK(list.empty() == true);

    for (int i = 10; i < 21; i++) {
        list.push_back(i);
    }

    CHECK(tolist(list) ==
          std::list<int>{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});

    for (int i = 9; i >= 0; i--) {
        list.push_front(i);
    }

    CHECK(tolist(list) == std::list<int>{0,  1,  2,  3,  4,  5,  6,
                                         7,  8,  9,  10, 11, 12, 13,
                                         14, 15, 16, 17, 18, 19, 20});

    CHECK(list.empty() == false);
    CHECK(list.front() == 0);
    CHECK(list.back() == 20);

    list.pop_front();
    list.pop_back();
    CHECK(tolist(list) == std::list<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                         13, 14, 15, 16, 17, 18, 19});

    DLList<int> l2(list);
    CHECK(tolist(l2) == std::list<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                       13, 14, 15, 16, 17, 18, 19});

    for (size_t i = 1; i <= 19; i++) {
        list.pop_back();
    }

    CHECK(tolist(list) == std::list<int>{});
    CHECK(list.empty() == true);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    CHECK(list.empty() == false);

    CHECK(tolist(list) == std::list<int>{1, 2, 3});
}

TEST_CASE("Iterator tests") {
    Iterator<int> it;
    for (it = list.begin(); it != list.end(); it++) {
        CHECK(*it == list.front());
        list.pop_front();
    }

    // std::cout << *it << std::endl;

    for (it = list.end(); it != list.begin(); it--) {
        CHECK(*it == list.back());
        list.pop_back();
    }

    // std::cout << *it << std::endl;
}
