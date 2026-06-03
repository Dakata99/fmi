#include "PQueue.h"

template <class T>
PQueue<T>::Node::Node(const T& elem, const size_t prior, Node* _next)
    : data(elem), priority(prior), next(_next) {}

template <class T>
void PQueue<T>::clear(void) {
    Node* tmp = head;

    while (head != nullptr) {
        head = head->next;
        delete tmp;
        tmp = head;
    }

    head = tail = nullptr;
}

template <class T>
void PQueue<T>::copy(const PQueue<T>& other) {
    Node* move = other.head;

    assert(move != nullptr);

    Node* new_head = new Node(move->data, move->priority, nullptr);
    Node* curr = new_head;
    move = move->next;

    while (move != nullptr) {
        curr->next = new Node(move->data, move->priority, nullptr);
        curr = curr->next;
        tail = move;
        move = move->next;
    }

    head = new_head;
}

template <class T>
void PQueue<T>::sort_by_priority(
    void) /* Not a good solution(slow), but it works */
{
    Node *curr = head, *index = nullptr;

    if (head == nullptr) {
        return;
    }

    while (curr != nullptr) {
        index = curr->next;

        while (index != nullptr) {
            if (curr->priority <= index->priority) {
                T data = curr->data;
                size_t priority = curr->priority;

                curr->data = index->data;
                curr->priority = index->priority;

                index->data = data;
                index->priority = priority;
            }
            index = index->next;
        }
        curr = curr->next;
    }
}

template <class T>
PQueue<T>::PQueue(const size_t priority)
    : head(nullptr), tail(nullptr), max_priority(priority) {}

template <class T>
PQueue<T>::PQueue(const PQueue<T>& other) {
    copy(other);
}

template <class T>
PQueue<T>::~PQueue() {
    clear();
}

template <class T>
PQueue<T>& PQueue<T>::operator=(const PQueue<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
bool PQueue<T>::empty(void) const {
    return head == nullptr;
}

template <class T>
size_t PQueue<T>::size(void) const {
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
const T& PQueue<T>::top(void) const {
    assert(head != nullptr);

    return head->data;
}

template <class T>
void PQueue<T>::push(const T& elem, const size_t priority) {
    if (max_priority + 1 <= priority) {
        printf("Error! No such priority!\n");
        return;
    }

    Node* new_node = new Node(elem, priority, nullptr);

    if (head == nullptr) {
        head = tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = tail->next;

    sort_by_priority();
}

template <class T>
void PQueue<T>::emplace(const T& elem) {
    push(elem);
}

template <class T>
void PQueue<T>::pop(void) {
    assert(head != nullptr);

    Node* tmp = head;
    head = head->next;
    delete tmp;
}

template <class T>
void PQueue<T>::swap(PQueue<T>& other) {
    assert(!empty() || !other.empty());

    size_t first_size = size(), second_size = other.size();

    size_t i = first_size;

    PQueue<T> tmp(other);
    other = *this;
    *this = tmp;
}

template <class T>
void swap(PQueue<T>& lhs, PQueue<T>& rhs) {
    lhs.swap(rhs);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const PQueue<T>& q) {
    PQueue<T> tmp(q);

    os << "( ";
    while (!tmp.empty()) {
        os << tmp.top() << ' ';
        tmp.pop();
    }
    os << ")\n";

    return os;
}
