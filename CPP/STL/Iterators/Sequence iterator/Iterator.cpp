#include "Iterator.h"

template <class T>
Iterator<T>::Iterator(T* data) : ptr(data) {}

template <class T>
const T& Iterator<T>::operator*(void) const {
    assert(ptr != nullptr);
    return *ptr;
}

template <class T>
Iterator<T>& Iterator<T>::operator++(void) {
    return Iterator(++ptr);
}
