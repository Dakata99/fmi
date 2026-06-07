#ifndef _DLLIST_H_
#define _DLLIST_H_

#include <ostream>

template <class T>
class Iterator;

template <class T>
class DLList {
private:
    friend class Iterator<T>;
    struct Node {
        T data;
        Node *previous, *next;
        Node(Node* = nullptr, const T = T(), Node* = nullptr);
    };

    Node *head, *tail;

private:
    void copy(const DLList<T>&);
    void clear();

public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();

    DLList& operator=(const DLList<T>&);

    bool empty(void) const;

    const T& front(void) const;
    const T& back(void) const;

    void push_front(const T&);
    void pop_front(void);
    void push_back(const T&);
    void pop_back(void);

    template <class E>
    friend std::ostream& operator<<(std::ostream&, const DLList<E>&);

    Iterator<T> begin(void);
    Iterator<T> end(void);
};

#endif
