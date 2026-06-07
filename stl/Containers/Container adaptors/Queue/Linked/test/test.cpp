#include "Queue.hpp"
#include "doctest.h"
#include "test_utils.hpp"

TEST_CASE("1") {
    Queue<int> q;

    CHECK(q.get_size() == 0);
    CHECK(q.empty() == true);

    for (size_t i = 0; i < 10; i++) {
        q.push(i);
    }

    CHECK(q.empty() == false);

    CHECK(q.get_size() == 10);
    CHECK(q.front() == 0);
    CHECK(q.back() == 9);

    Queue<int> q2(q);

    CHECK(q2.get_size() == 10);
    CHECK(q2.front() == 0);
    CHECK(q2.back() == 9);

    q.pop();

    Queue<int> q3 = q;
    CHECK(q3.get_size() == 9);
    CHECK(q3.front() == 1);
    CHECK(q3.back() == 9);

    Queue<std::string> myqueue;

    myqueue.emplace("First sentence");
    myqueue.emplace("Second sentence");

    CHECK(tovector(myqueue) ==
          std::vector<std::string>{"First sentence", "Second sentence"});

    Queue<int> q4;

    for (size_t i = 10; i < 20; i++) {
        q4.push(i);
    }

    CHECK(tovector(q3) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
    CHECK(tovector(q4) ==
          std::vector<int>{10, 11, 12, 13, 14, 15, 16, 17, 18, 19});

    swap(q3, q4);

    CHECK(tovector(q3) ==
          std::vector<int>{10, 11, 12, 13, 14, 15, 16, 17, 18, 19});
    CHECK(tovector(q4) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});

    q3.swap(q4);

    CHECK(tovector(q3) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
    CHECK(tovector(q4) ==
          std::vector<int>{10, 11, 12, 13, 14, 15, 16, 17, 18, 19});

    CHECK((q3 == q4) == false);
    CHECK((q3 != q4) == true);
}
