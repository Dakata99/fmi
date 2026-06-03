#include "Queue.h"

template <class T>
Queue<T>::Node::Node(const T& elem, Node* _next) : data(elem), next(_next) {}

template <class T>
void Queue<T>::clear(void) {
    Node* tmp = head;

    while (head != nullptr) {
        head = head->next;
        delete tmp;
        tmp = head;
    }

    head = tail = nullptr;
}

template <class T>
void Queue<T>::copy(const Queue<T>& other) {
    Node* move = other.head;

    assert(move != nullptr);

    Node* new_head = new Node(move->data, nullptr);
    Node* curr = new_head;
    move = move->next;

    while (move != nullptr) {
        curr->next = new Node(move->data, nullptr);
        curr = curr->next;
        tail = move;
        move = move->next;
    }

    head = new_head;
}

template <class T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template <class T>
Queue<T>::Queue(const Queue<T>& other) : head(nullptr), tail(nullptr) {
    copy(other);
}

template <class T>
Queue<T>::~Queue() {
    clear();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
bool Queue<T>::empty(void) const {
    return head == nullptr;
}

template <class T>
const size_t Queue<T>::get_size(void) const {
    if (head == nullptr) {
        return 0;
    }

    size_t counter = 1;
    Node* tmp = head;

    while (tmp = tmp->next) {
        counter++;
    }

    return counter;
}

template <class T>
const T& Queue<T>::front(void) const {
    assert(head != nullptr);
    return head->data;
}

template <class T>
const T& Queue<T>::back(void) const {
    assert(head != nullptr);
    return tail->data;
}

template <class T>
void Queue<T>::push(const T& elem) {
    if (head == nullptr) {
        head = tail = new Node(elem, nullptr);
        return;
    }

    tail->next = new Node(elem, nullptr);
    tail = tail->next;
}

template <class T>
void Queue<T>::emplace(const T& elem) {
    push(elem);
}

template <class T>
void Queue<T>::pop(void) {
    assert(head != nullptr);

    Node* tmp = head;
    head = head->next;
    delete tmp;
}

template <class T>
void Queue<T>::swap(Queue<T>& other) {
    assert(!(empty() && other.empty()));

    size_t first_size = get_size(), second_size = other.get_size();

    for (size_t i = 0; i < first_size; i++) {
        other.push(front());
        pop();
    }

    for (size_t i = 0; i < second_size; i++) {
        push(other.front());
        other.pop();
    }
}

/* relational operators */
template <class T>
bool Queue<T>::operator==(const Queue<T>& other) const {
    Queue<T> lhs(*this), rhs(other);

    size_t lhs_size = lhs.get_size(), rhs_size = rhs.get_size();

    if (lhs_size != rhs_size) {
        return false;
    }

    while (!lhs.empty()) {
        if (lhs.front() != rhs.front()) {
            return false;
        }
        lhs.pop();
        rhs.pop();
    }
    return true;
}

template <class T>
bool Queue<T>::operator!=(const Queue<T>& other) const {
    return !((*this) == other);
}

template <class T>
void swap(Queue<T>& lhs, Queue<T>& rhs) {
    lhs.swap(rhs);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
    Queue<T> tmp(q);

    os << "[ ";
    while (!tmp.empty()) {
        os << tmp.front() << ' ';
        tmp.pop();
    }
    os << "]\n";

    return os;
}
