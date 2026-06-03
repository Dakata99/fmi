#include <iostream>

#include "Stack.hpp"
#include "doctest.h"
#include "test_utils.hpp"

TEST_CASE("[CONTIGUOUS STACK]") {
    std::cout << DOCTEST_VERSION_MAJOR << std::endl;
}

TEST_CASE("Test 1") {
    Stack<int> st;

    CHECK(st.empty() == true);

    st.push(1);

    CHECK(st.top() == 1);
    CHECK(st.empty() == false);

    for (int i = 11; i <= 20; i++) {
        st.push(i);
    }

    // CHECK(tovector(st) == std::vector<int> {});

    CHECK(st.top() == 20);
    st.pop();

    CHECK(st.top() == 19);
    st.pop();

    CHECK(st.top() == 18);
    st.pop();

    CHECK(st.top() == 17);
    st.pop();

    CHECK(st.top() == 16);
    st.pop();

    CHECK(st.top() == 15);
    st.pop();

    CHECK(st.top() == 14);
    st.pop();

    CHECK(st.top() == 13);
    st.pop();

    CHECK(st.top() == 12);
    st.pop();

    CHECK(st.top() == 11);
    st.pop();

    CHECK(st.top() == 1);
    st.pop();

    CHECK(st.empty() == true);
}
