#include "DLList.h"

#include <cassert>

template <class T>
DLList<T>::Node::Node(Node* _previous, const T _data, Node* _next)
    : data(_data), previous(_previous), next(_next) {}

template <class T>
void DLList<T>::copy(const DLList<T>& other) {
    Node* iter = other.head;

    if (iter == nullptr) {
        return;
    }

    Node* curr = new Node(nullptr, iter->data, nullptr);
    iter = iter->next;
    head = curr;
    while (iter != other.tail->next) {
        curr->next = new Node(curr, iter->data, nullptr);
        curr = curr->next;
        iter = iter->next;
    }
    tail = curr;
}

template <class T>
void DLList<T>::clear(void) {
    Node *curr = head, *save = nullptr;
    while (curr != nullptr) {
        save = curr;
        curr = curr->next;
        delete save;
    }
    head = tail = curr;
}

template <class T>
DLList<T>::DLList(void) : head(nullptr), tail(nullptr) {}

template <class T>
DLList<T>::DLList(const DLList<T>& other) : head(nullptr), tail(nullptr) {
    copy(other);
}

template <class T>
DLList<T>::~DLList(void) {
    clear();
}

template <class T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
bool DLList<T>::empty(void) const {
    return head == nullptr;
}  // && tail == nullptr

template <class T>
const T& DLList<T>::front(void) const {
    assert(head != nullptr);
    return head->data;
}

template <class T>
const T& DLList<T>::back(void) const {
    assert(tail != nullptr);
    return tail->data;
}

template <class T>
void DLList<T>::push_front(const T& element) {
    if (head == nullptr) {
        head = new Node(nullptr, element, nullptr);
        tail = head;
    } else {
        head->previous = new Node(nullptr, element, head);
        head = head->previous;
    }
}

template <class T>
void DLList<T>::pop_front(void) {
    assert(head != nullptr);

    Node* curr = head;
    head = head->next;
    if (head != nullptr) {
        head->previous = nullptr;
    } else {
        tail = head;
    }

    delete curr;
}

template <class T>
void DLList<T>::push_back(const T& element) {
    if (head == nullptr) {
        head = new Node(nullptr, element, nullptr);
        tail = head;
    } else {
        tail->next = new Node(tail, element, nullptr);
        tail = tail->next;
    }
}

template <class T>
void DLList<T>::pop_back(void) {
    assert(tail != nullptr);

    Node* curr = tail;
    tail = tail->previous;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = tail;
    }

    delete curr;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const DLList<T>& list) {
    DLList<T> tmp(list);

    os << "[ ";
    while (!tmp.empty()) {
        os << tmp.front() << ' ';
        tmp.pop_front();
    }
    return os;
}

template <class T>
Iterator<T> DLList<T>::begin(void) {
    return Iterator<T>(head);
}

template <class T>
Iterator<T> DLList<T>::end(void) {
    return Iterator<T>(tail);
}
