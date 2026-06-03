#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <stack>

#include "../../Containers/Graph/Trees/Binary/Linked/inc/BTree.h"
#include "Position.h"

template <class T>
class Iterator {
private:
    friend Position<T>;
    std::stack<Position<T>> st;

public:
    Iterator(Position<T>, bool);
    T operator*(void) const;
    Iterator& operator++(void);
    bool operator!=(const Iterator&) const;
};

#include "Iterator.cpp"

#endif
