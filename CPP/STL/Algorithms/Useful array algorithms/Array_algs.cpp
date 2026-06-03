#include "Array_algs.h"

template <class InputIterator, class UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
    while (first != last) {
        if (!pred(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}

template <class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first)) {
            return true;
        }
        ++first;
    }
    return false;
}
