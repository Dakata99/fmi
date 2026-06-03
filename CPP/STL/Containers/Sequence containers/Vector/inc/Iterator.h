#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <cassert>

template <class T>
class Iterator {
private:
    T* pointer;

public:
    Iterator(T* = nullptr);

    Iterator& operator++(void);
    Iterator& operator--(void);
    Iterator& operator++(int);
    Iterator& operator--(int);

    template <class E>
    friend bool operator==(const Iterator<E>&, const Iterator<E>&);

    template <class E>
    friend bool operator!=(const Iterator<E>&, const Iterator<E>&);

    bool operator==(const Iterator&);
    bool operator!=(const Iterator&);
    T& operator*(void) const;
};

#endif
