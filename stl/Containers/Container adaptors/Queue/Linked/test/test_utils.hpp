#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <vector>

#include "Queue.h"

template <class T>
std::vector<T> tovector(Queue<T> q) {
    std::vector<T> res;

    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }

    return res;
}

#endif
