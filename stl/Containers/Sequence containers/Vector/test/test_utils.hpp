#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <vector>

#include "Vector.h"

template <class T>
std::vector<T> tovector(Vector<T> vec) {
    std::vector<T> res;

    for (size_t i = 0; i < vec.get_size(); i++) {
        res.push_back(vec[i]);
    }

    return res;
}

#endif
