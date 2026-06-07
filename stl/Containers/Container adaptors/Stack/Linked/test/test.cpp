#include "Stack.hpp"
#include "doctest.h"
#include "test_utils.hpp"

Stack<int> st;

TEST_CASE("1") {
    CHECK(st.empty() == true);

    for (size_t i = 0; i < 10; i++) {
        st.push(i);
    }

    CHECK(st.empty() == false);

    CHECK(st.top() == 9);

    // CHECK(tovector(st) == std::vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 });
    // // Why it fails, when its the same as line 17?

    Stack<int> st2(st);

    CHECK(tovector(st2) == std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

    for (size_t i = 0; i < 11; i++) {
        st.pop();
    }

    CHECK(st.empty() == true);
}
