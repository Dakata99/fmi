#ifndef _SLLIST_H_
#define _SLLIST_H_

#include <ostream>

template <class T>
class Iterator;

template <class T>
class SLList {
private:
    friend Iterator<T>;

    struct Node {
        T data;
        Node* next;
        Node(const T& = T(), Node* = nullptr);
    };

    Node* head;

private:
    void copy(const SLList<T>&);
    void clear(void);

public:
    SLList();
    SLList(const SLList<T>&);
    ~SLList();

    SLList& operator=(const SLList<T>&);

    bool empty(void) const;

    void push_front(const T&);
    void pop_front(void);

    const T& front(void) const;
    void reverse(void);

    template <class E>
    friend std::ostream& operator<<(std::ostream&, const SLList<E>&);

    Iterator<T> begin(void);
    Iterator<T> end(void);
};

#endif
