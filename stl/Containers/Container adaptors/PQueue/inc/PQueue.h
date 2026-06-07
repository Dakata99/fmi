#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <cassert>
#include <iostream>

template <class T>
class PQueue {
private: /* Members */
    struct Node {
        T data;
        size_t priority;
        Node* next;
        Node(const T& = T(), const size_t = 0, Node* = nullptr);
    };

    Node *head, *tail;
    size_t max_priority;

private: /* Methods */
    void clear(void);
    void copy(const PQueue<T>&);
    void sort_by_priority(void);

public:
    /* constructors/desctructors */
    PQueue(const size_t = 0);
    PQueue(const PQueue<T>&);
    ~PQueue();

    PQueue<T>& operator=(const PQueue<T>&);

    bool empty(void) const;
    size_t size(void) const;
    const T& top(void) const;
    void push(const T&, const size_t = 0);
    void emplace(const T&);
    void pop(void);
    void swap(PQueue<T>&);

    template <class E>
    friend void swap(PQueue<E>&, PQueue<E>&);

    template <class E>
    friend std::ostream& operator<<(std::ostream&, const PQueue<E>&);
};

#endif /* _PQUEUE_H_ */
