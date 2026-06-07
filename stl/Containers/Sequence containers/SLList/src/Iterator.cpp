#include <cassert>

#include "Iterator.h"
#include "SLList.h"

template <class T>
Iterator<T>::Iterator(typename SLList<T>::Node* ptr) : iter(ptr) {}

template <class T>
Iterator<T>& Iterator<T>::operator++(void) {
    assert(iter != nullptr);

    iter = iter->next;
    return (*this);
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
    assert(iter != nullptr);

    iter = iter->next;
    return (*this);
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return iter == other.iter;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return iter != other.iter;
}

template <class T>
const T& Iterator<T>::operator*(void) const {
    return iter->data;
}
