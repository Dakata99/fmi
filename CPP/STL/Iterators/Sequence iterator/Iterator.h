#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <cassert>

template <class T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* = nullptr);

    const T& operator*(void) const;
    Iterator& operator++(void);
};

#include "Iterator.cpp"

#endif
