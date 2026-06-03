#include "Iterator.hpp"
#include "Vector.hpp"
#include "doctest.h"
#include "test_utils.hpp"

TEST_CASE("Constructors test") {
    Vector<int> vec;

    for (size_t i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    CHECK(vec.get_size() == 5);

    CHECK(tovector(vec) == std::vector<int>{0, 1, 2, 3, 4});

    vec.pop_back();
    CHECK(tovector(vec) == std::vector<int>{0, 1, 2, 3});

    CHECK(vec.get_size() == 4);

    Vector<int> vec2(5);
    CHECK(vec2.get_size() == 5);

    Vector<int> vec3(5, 99);
    CHECK(vec3.get_size() == 5);

    Vector<int> vec4(6, 77);
    CHECK(vec4.get_size() == 6);

    Vector<int> vec5(vec);
    CHECK(vec.get_size() == 4);
}

TEST_CASE("Operators test") {
    Vector<int> vec(3, 55);
    Vector<int> vec2 = vec;

    vec2.pop_back();

    CHECK(vec.get_size() == 3);
    CHECK(vec2.get_size() == 2);

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(9);

    CHECK(vec[0] == 55);
    CHECK(vec[3] == 1);
    CHECK(vec.front() == 55);
    CHECK(vec.back() == 9);
}

TEST_CASE("Iterator test") {
    Vector<int> vec;
    for (size_t i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    size_t i = 0;
    for (Iterator<int> it = vec.begin(); it != vec.end(); it++) {
        CHECK(*it == vec[i++]);
    }

    // Vector<int> vec2(vec.begin(), vec.end());
}
