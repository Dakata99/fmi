#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <list>

#include "DLList.h"

template <class T>
std::list<T> tolist(DLList<T> list) {
    std::list<T> res;

    while (!list.empty()) {
        res.push_back(list.front());
        list.pop_front();
    }

    return res;
}

#endif
