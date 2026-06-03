#include "doctest.h"
#include "test_utils.hpp"

#include "Iterator.hpp"
#include "SLList.hpp"

SLList<int> list;

TEST_CASE("Constructors tests") {
    CHECK(list.empty() == true);

    for (size_t i = 0; i < 10; i++) {
        list.push_front(i); /* elements: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 */
    }

    CHECK(tovector(list) == std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

    list.reverse();

    CHECK(tovector(list) == std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    CHECK(list.front() == 0);
    CHECK(list.empty() != true);

    list.pop_front();
    list.pop_front();
    list.pop_front();

    CHECK(tovector(list) == std::vector<int>{3, 4, 5, 6, 7, 8, 9});

    SLList<int> l2(list);

    CHECK(tovector(l2) == std::vector<int>{3, 4, 5, 6, 7, 8, 9});
    CHECK(tovector(list) == std::vector<int>{3, 4, 5, 6, 7, 8, 9});

    for (size_t i = 0; i < 7; i++) {
        list.pop_front();
    }

    CHECK(tovector(list) == std::vector<int>{});
    CHECK(list.empty() == true);
}

TEST_CASE("Iterator tests") {
    for (Iterator<int> it = list.begin(); it != list.end(); it++) {
        CHECK(*it == list.front());
        list.pop_front();
    }
}
