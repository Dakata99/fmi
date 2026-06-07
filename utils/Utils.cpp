#include <iostream>
#include <vector>

#include "PQueue.h"

template <class T>
std::vector<T> tovector(PQueue<T> q) {
    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
    std::vector<T> res;

    while (!q.empty()) {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}
