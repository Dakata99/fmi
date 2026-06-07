#include <iostream>
#include <vector>

#include "Array_algs.h"

void tests(void) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    (all_of(v.begin(), v.end(), [](int x) { return x > 0; }))
        ? std::cout << "All elements are positive!\n"
        : std::cout << "NO!\n";

    (any_of(v.begin(), v.end(), [](int x) { return x < 0; }))
        ? std::cout << "There is a negative element!\n"
        : std::cout << "NO!\n";

    v = {1, 2, -3, 4, 5};

    (all_of(v.begin(), v.end(), [](int x) { return x > 0; }))
        ? std::cout << "All elements are positive!\n"
        : std::cout << "NO!\n";

    (any_of(v.begin(), v.end(), [](int x) { return x < 0; }))
        ? std::cout << "There is a negative element!\n"
        : std::cout << "NO!\n";
}

int main(void) {
    tests();

    return 0;
}
