#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

template <class T>
class Stack {
private:
    T* data;
    size_t top_index, size;

    void copy(const Stack<T>&);
    void clear(void);
    void resize(const size_t&);

public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();

    Stack& operator=(const Stack<T>&);

    void push(const T&);
    void pop(void);
    bool empty(void) const;
    const T& top(void) const;

    template <class E>
    friend std::ostream& operator<<(std::ostream&, const Stack<E>&);
};

#endif
