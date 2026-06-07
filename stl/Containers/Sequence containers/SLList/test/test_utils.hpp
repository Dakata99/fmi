#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <vector>

#include "SLList.h"

template <class T>
std::vector<T> tovector(SLList<T> list) {
    std::vector<T> res;
    while (!list.empty()) {
        res.push_back(list.front());
        list.pop_front();
    }

    return res;
}

#endif
