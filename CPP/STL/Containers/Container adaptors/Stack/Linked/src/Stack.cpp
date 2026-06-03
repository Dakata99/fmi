#include "Stack.h"

#include <cassert>
#include <vector>

template <class T>
Stack<T>::StackBox::StackBox(const T& _data, typename Stack<T>::StackBox* _next)
    : data(_data), next(_next) {}

template <class T>
void Stack<T>::copy(const Stack<T>& other) {
    StackBox* other_top = other.top_ptr;

    if (other_top == nullptr) {
        return;
    }

    std::vector<T> values;
    while (other_top != nullptr) {
        values.push_back(other_top->data);
        other_top = other_top->next;
    }

    for (size_t i = 0; i < values.size(); i++) {
        StackBox* new_box = new StackBox(values[i], top_ptr);
        top_ptr = new_box;
    }
}

template <class T>
void Stack<T>::clear(void) {
    if (top_ptr == nullptr) {
        return;
    }

    StackBox* tmp = top_ptr;
    top_ptr = top_ptr->next;
    delete tmp;
}

template <class T>
Stack<T>::Stack() : top_ptr(nullptr) {}

template <class T>
Stack<T>::Stack(const Stack<T>& other) : top_ptr(nullptr) {
    copy(other);
}

template <class T>
Stack<T>::~Stack() {}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
void Stack<T>::push(const T& element) {
    StackBox* new_el = new StackBox(element, nullptr);
    new_el->next = top_ptr;
    top_ptr = new_el;
}

template <class T>
void Stack<T>::pop(void) {
    if (top_ptr == nullptr) {
        return;
    }

    StackBox* tmp = top_ptr;
    top_ptr = top_ptr->next;
    delete tmp;
}

template <class T>
bool Stack<T>::empty(void) const {
    return top_ptr == nullptr;
}

template <class T>
const T& Stack<T>::top(void) const {
    assert(top_ptr != nullptr);
    return top_ptr->data;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& st) {
    Stack<T> tmp(st);

    os << "[ ";
    while (!tmp.empty()) {
        os << tmp.top() << ' ';
        tmp.pop();
    }
    os << "]\n";

    return os;
}
