#include "Iterator.h"

#include <cassert>

template <class T>
Iterator<T>::Iterator(typename DLList<T>::Node* ptr) : iter(ptr) {}

template <class T>
Iterator<T>& Iterator<T>::operator++() {
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
Iterator<T>& Iterator<T>::operator--() {
    assert(iter != nullptr);

    iter = iter->previous;
    return (*this);
}

template <class T>
Iterator<T> Iterator<T>::operator--(int) {
    assert(iter != nullptr);

    iter = iter->previous;
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
T& Iterator<T>::operator*() const {
    return iter->data;
}
