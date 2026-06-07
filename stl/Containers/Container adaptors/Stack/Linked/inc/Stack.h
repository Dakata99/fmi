#ifndef _STACK_H_
#define _STACK_H_

#include <ostream>

template <class T>
class Stack {
private:
    struct StackBox {
        T data;
        StackBox* next;
        StackBox(const T& = T(), StackBox* = nullptr);
    };

    StackBox* top_ptr;

private:
    void copy(const Stack<T>&);
    void clear(void);

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
    friend std::ostream& operator<<(std::ostream&, const Stack<T>&);
};

#endif
