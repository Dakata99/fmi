#include "PQueue.hpp"
#include "doctest.h"
// #include "test_utils.hpp"
#include <iostream>
#include <vector>

#include "Utils.hpp"

TEST_CASE("1") {
    std::cout << DOCTEST_VERSION_MAJOR << std::endl;

    PQueue<char> q(4);  // 4 priorities - 0, 1, 2 и 3.
    std::cout << "AAAA = " << q.top() << std::endl;
    // std::vector<char> v = tovector(q);
    // for (int i = 0; i < v.size(); i++) {
    // 	std::cout << "AA = " << v[i] << std::endl;
    // }
}

TEST_CASE("2") {
    PQueue<char> q(4);  // 4 priorities - 0, 1, 2 и 3.

    q.push('A', 0);  // adds A with lowest priority: 0
    q.push('B', 3);
    q.push('C', 2);
    q.push('D', 2);
    q.push('E', 1);

    // q.push('F', 5); //error! No such priority!

    std::cout << "Q = " << q;

    PQueue<char> q2(4);

    q2.push('F', 0);
    q2.push('G', 3);
    q2.push('H', 2);
    q2.push('J', 2);
    q2.push('K', 1);

    std::cout << "Q2 = " << q2 << std::endl;

    q.swap(q2);

    std::cout << "Q = " << q << "Q2 = " << q2 << std::endl;

    swap(q, q2);
    std::cout << "Q = " << q << "Q2 = " << q2;

    // q.pop(); // B
    // q.pop(); // C
    // q.pop(); // D
    // q.pop(); // E
    // q.pop(); // A

    /*
    PQueue<char> q3(15);
    q3.push('a', 0);
    q3.push('m', 1);
    q3.push('y', 2);
    q3.push('q', 3);
    q3.push('e', 4);
    q3.push('f', 5);
    q3.push('g', 6);
    q3.push('h', 7);
    q3.push('r', 8);
    q3.push('f', 9);
    q3.push('j', 10);
    q3.push('i', 11);
    q3.push('y', 12);
    q3.push('e', 13);
    q3.push('s', 14);
    q3.push('p', 15);

    std::cout << q3;
    */
}
