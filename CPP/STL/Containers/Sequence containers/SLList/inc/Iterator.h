#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class Iterator {
private:
    typename SLList<T>::Node* iter;

public:
    Iterator(typename SLList<T>::Node* = nullptr);

    Iterator& operator++(void);
    Iterator operator++(int);

    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

    const T& operator*(void) const;
};

#endif
