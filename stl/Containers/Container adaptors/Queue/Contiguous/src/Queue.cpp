#include "Queue.h"

#include <iostream>
#include <new>

template <class T>
void Queue<T>::clear(void) {
    delete[] data;
}

template <class T>
void Queue<T>::copy(const Queue<T>& other) {
    if (other.size == 0) {
        return;
    }

    size = other.size;
    max_size = other.max_size;
    data = new T[size];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
void Queue<T>::resize(const size_t& new_size) {
    T* temp = new T[size];
    for (size_t i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;

    size = new_size;
    data = new T[size];
    for (size_t i = 0; i < size; i++) {
        data[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
Queue<T>::Queue() : size(0), max_size(1) {
    data = new T[max_size];
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) : size(0), max_size(1) {
    copy(other);
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
bool Queue<T>::empty(void) const noexcept {
    return size == 0;
}

template <class T>
const size_t Queue<T>::get_size(void) const noexcept {
    return size;
}

template <class T>
const T& Queue<T>::front(void) const {
    if (data == nullptr) {
        throw std::bad_alloc("Accessing null pointer!\n");
    }

    try {
        return data[0];
    } catch (std::out_of_range& error) {
        std::cerr << error.what();
    }
}

template <class T>
const T& Queue<T>::back(void) const {
    if (data == nullptr) {
        throw std::bad_alloc("Accessing null pointer!\n");
    }

    try {
        return data[size - 1];
    } catch (std::out_of_range& error) {
        std::cerr << error.what();
    }
}

template <class T>
void Queue<T>::push(const T& elem) {
    if (size + 1 >= max_size) {
        resize(max_size * 2);
    }

    data[size++] = elem;
}

template <class T>
void Queue<T>::emplace(const T& elem) {}

template <class T>
void Queue<T>::pop(void) {
    if (size <= 0) {
        throw std::out_of_range("NULL pointer occured!\n");
    }

    try {
        if (2 * size < max_size) {
            resize(max_size / 2);
        }
        size--;
    } catch (std::out_of_range& error) {
        std::cerr << error.what();
    }
}

template <class T>
void Queue<T>::swap(Queue<T>& other) {
    Queue<T> tmp(other);
}

/* relational operators */
// template <class T>
// bool Queue<T>::operator==(const Queue<T>&) const;

// template <class T>
// void swap(Queue<T>&, Queue<T>&);
