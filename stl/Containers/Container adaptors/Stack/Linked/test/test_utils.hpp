#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <vector>

#include "Stack.h"

template <class T>
std::vector<T> tovector(Stack<T> st) {
    std::vector<T> res;

    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

#endif
