#include "SLList.h"

#include <cassert>
#include <iostream>

template <class T>
SLList<T>::Node::Node(const T& _data, Node* _next) : data(_data), next(_next) {}

template <class T>
void SLList<T>::copy(const SLList<T>& other) {
    Node* other_curr = other.head;

    if (other_curr == nullptr) {
        return;
    }

    head = new Node(other_curr->data, nullptr);
    other_curr = other_curr->next;
    Node* curr = head;

    while (other_curr != nullptr) {
        curr->next = new Node(other_curr->data, nullptr);
        other_curr = other_curr->next;
        curr = curr->next;
    }
}

template <class T>
void SLList<T>::clear(void) {
    Node* curr = head;
    while (head != nullptr) {
        head = head->next;
        delete curr;
        curr = head;
    }
}

template <class T>
SLList<T>::SLList() : head(nullptr) {}

template <class T>
SLList<T>::SLList(const SLList<T>& other) : head(nullptr) {
    copy(other);
}

template <class T>
SLList<T>::~SLList() {
    clear();
}

template <class T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
bool SLList<T>::empty(void) const {
    return head == nullptr;
}

template <class T>
void SLList<T>::push_front(const T& element) {
    if (head == nullptr) {
        head = new Node(element, nullptr);
    } else {
        Node* new_node = new Node(element, head);
        head = new_node;
    }
}

template <class T>
void SLList<T>::pop_front(void) {
    assert(head != nullptr);

    Node* curr = head;
    head = head->next;
    delete curr;
}

template <class T>
const T& SLList<T>::front(void) const {
    assert(head != nullptr);
    return head->data;
}

template <class T>
void SLList<T>::reverse(void) {
    if (head == nullptr) {
        return;
    }

    Node *prev = nullptr, *curr, *curr_head = head;
    while (curr_head != nullptr) {
        curr = curr_head;
        curr_head = curr_head->next;
        curr->next = prev;
        prev = curr;
    }
    head = curr;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const SLList<T>& list) {
    SLList<T> tmp(list);

    os << "[ ";
    while (!tmp.empty()) {
        os << tmp.front() << ' ';
        tmp.pop_front();
    }
    os << "]\n";

    return os;
}

template <class T>
Iterator<T> SLList<T>::begin(void) {
    return Iterator<T>(head);
}

template <class T>
Iterator<T> SLList<T>::end(void) {
    return Iterator<T>();
}
