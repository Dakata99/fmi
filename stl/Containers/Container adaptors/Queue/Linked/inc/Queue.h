#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cassert>
#include <iostream>

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& = T(), Node* = nullptr);
    };

    Node *head, *tail;

private:
    void clear(void);
    void copy(const Queue<T>&);

public:
    /* constructors/desctructors */
    Queue();
    Queue(const Queue<T>&);
    ~Queue();

    Queue<T>& operator=(const Queue<T>&);

    /* */
    bool empty(void) const;
    const size_t get_size(void) const;
    const T& front(void) const;
    const T& back(void) const;
    void push(const T&);
    void emplace(const T&);
    void pop(void);
    void swap(Queue<T>&);

    /* relational operators */
    bool operator==(const Queue<T>&) const;
    bool operator!=(const Queue<T>&) const;
    /* TODO: operators for <=, <, >=, > */

    /* */
    template <class E>
    friend void swap(Queue<E>&, Queue<E>&);

    /* */
    template <class E>
    friend std::ostream& operator<<(std::ostream&, const Queue<T>&);
};

#endif
