#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "DLList.h"

template <class T>
class Iterator {
private:
    typename DLList<T>::Node* iter;

public:
    Iterator(typename DLList<T>::Node* = nullptr);

    Iterator<T>& operator++(void);
    Iterator<T> operator++(int);
    Iterator<T>& operator--(void);
    Iterator<T> operator--(int);

    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

    T& operator*(void) const;
};

#endif
