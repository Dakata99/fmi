#ifndef _POSITION_H_
#define _POSITION_H_

#include "../../Containers/Graph/Trees/Binary/Linked/inc/BTree.h"

template <class T>
class Position {
private:
    typedef typename BTree<T>::Node BTNode;
    BTNode*& current;

public:
    Position(BTNode*&);

    Position left(void) const;
    Position right(void) const;

    const T& operator*(void) const;

    bool empty(void) const;

    const T& get(void) const;
    void set(const T&);
};

#include "Position.cpp"

#endif
