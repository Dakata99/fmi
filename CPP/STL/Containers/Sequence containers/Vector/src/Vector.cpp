#include "Vector.h"

// private funcs
template <class T>
void Vector<T>::copy(const Vector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[size];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
void Vector<T>::del(void) {
    delete[] data;
}

template <class T>
void Vector<T>::init(const size_t& num, const T& val) {
    size = capacity = num;
    data = new T[size];

    for (size_t i = 0; i < size; i++) {
        data[i] = val;
    }
}

// public funcs
template <class T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <class T>
Vector<T>::Vector(const size_t& size) {
    init(size, T());
}

template <class T>
Vector<T>::Vector(const size_t& size, const T& val) {
    init(size, val);
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) {
    copy(other);
}

template <class T>
Vector<T>::Vector(const Iterator<T>& begin, const Iterator<T>& end) {
    while (begin != end) {
        push_back(*begin);
        begin++;
    }
}

template <class T>
Vector<T>::~Vector() {
    del();
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        del();
        copy(other);
    }
    return *this;
}

// Iterators
template <class T>
Iterator<T> Vector<T>::begin(void) {
    return Iterator<T>(this->data);
}

template <class T>
Iterator<T> Vector<T>::end(void) {
    return Iterator<T>(this->data + size);
}

template <class T>
Iterator<T> Vector<T>::rbegin(void) {
    return Iterator<T>(this->data + size);
}

template <class T>
Iterator<T> Vector<T>::rend(void) {
    return Iterator<T>(this->data);
}

template <class T>
Iterator<T> Vector<T>::cbegin(void) const {
    return Iterator<T>(this->data);
}

template <class T>
Iterator<T> Vector<T>::cend(void) const {
    return Iterator<T>(this->data + size);
}

template <class T>
Iterator<T> Vector<T>::crbegin(void) const {
    return Iterator<T>(this->data + size);
}

template <class T>
Iterator<T> Vector<T>::crend(void) const {
    return Iterator<T>(this->data);
}

// capacity
template <class T>
size_t Vector<T>::get_size(void) const {
    return size;
}

template <class T>
size_t Vector<T>::get_max_size(void) const {
    return pow(2, 64) / sizeof(T) - 1;
}

template <class T>
void Vector<T>::resize(const size_t& new_size, T& value) {
    const T* temp = new T[new_size];
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
size_t Vector<T>::capacity_vec(void) const {
    return capacity;
}

template <class T>
bool Vector<T>::empty(void) const {
    return size == 0;
}

template <class T>
void Vector<T>::reserve(const size_t& new_size) {}

template <class T>
void Vector<T>::shrink_to_fit(void) {}

// element access
template <class T>
const T& Vector<T>::operator[](size_t index) const {
    assert(data != nullptr && index >= 0 && index <= size - 1);
    return data[index];
}

template <class T>
const T& Vector<T>::at(size_t index) const {
    assert(data != nullptr && index >= 0 && index <= size - 1);
    return data[index];
}

template <class T>
T& Vector<T>::front(void) const {
    assert(data != nullptr);
    return data[0];
}

template <class T>
T& Vector<T>::back(void) const {
    assert(data != nullptr);
    return data[size - 1];
}

template <class T>
T* Vector<T>::get_data(void) {
    return data;
}

// modifiers
template <class T>
void Vector<T>::assign(size_t new_size, const T& value) {}

template <class T>
void Vector<T>::push_back(const T& element) {
    if (data == nullptr) {
        capacity = 1;
        data = new T[capacity];
    } else if (size >= capacity) {
        capacity++;
        T* temp = new T[size];

        for (size_t i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = temp[i];
        }

        delete[] temp;
    }
    data[size++] = element;
}

template <class T>
void Vector<T>::pop_back(void) {
    if (data == nullptr || size == 0) {
        return;
    }

    size--;

    T* temp = new T[size];
    for (size_t i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = new T[size];

    for (size_t i = 0; i < size; i++) {
        data[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Vector<T>::insert(void) {}

template <class T>
void Vector<T>::erase(void) {}

template <class T>
void Vector<T>::swap(Vector<T>& x) {}

template <class T>
void Vector<T>::clear(void) {
    del();
}

template <class T>
void Vector<T>::emplace(void) {}

template <class T>
void Vector<T>::emplace_back(void) {}

// non-member function overloads
template <class T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    assert(size == other.size());

    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !(*this == other);
}

template <class T>
bool Vector<T>::operator>=(const Vector<T>& other) const {
    return false;
}

template <class T>
bool Vector<T>::operator>(const Vector<T>& other) const {
    return false;
}

template <class T>
bool Vector<T>::operator<=(const Vector<T>& other) const {
    return false;
}

template <class T>
bool Vector<T>::operator<(const Vector<T>& other) const {
    return false;
}

template <class T>
void swap(Vector<T>& x, Vector<T>& y) {}

// printing funcs
template <class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    std::cout << "( ";

    for (size_t i = 0; i < vector.size; i++) {
        os << vector.data[i] << " ";
    }

    std::cout << ")\n";

    return os;
}
