#include "Stack.h"

template <class T>
void Stack<T>::copy(const Stack<T>& other) {
    top_index = other.top_index;
    size = other.size;

    for (size_t i = 0; i < top_index; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
void Stack<T>::clear(void) {
    delete[] data;
}

template <class T>
void Stack<T>::resize(const size_t& new_size) {
    T* temp = new T[top_index];
    for (size_t i = 0; i < top_index; i++) {
        temp[i] = data[i];
    }

    delete[] data;

    size = new_size;
    data = new T[size];
    for (size_t i = 0; i < top_index; i++) {
        data[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
Stack<T>::Stack() : data(nullptr), top_index(0), size(0) {}

template <class T>
Stack<T>::Stack(const Stack<T>& other) : data(nullptr) {
    copy(other);
}

template <class T>
Stack<T>::~Stack() {
    clear();
}

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
    if (data == nullptr) {
        size = 1;
        data = new T[size];
        data[top_index++] = element;
    } else if (top_index >= size) {
        resize(size + 1);
    } else {
        data[top_index++] = element;
        size++;
    }
}

template <class T>
void Stack<T>::pop(void) {
    if (top_index > 0) {
        top_index--;
    } else {
        clear();
        data = nullptr;
    }

    if (top_index * 2 == size && data != nullptr) {
        resize((size / 2) + 1);
    }
}

template <class T>
bool Stack<T>::empty(void) const {
    return data == nullptr;
}

template <class T>
const T& Stack<T>::top(void) const {
    return data[top_index - 1];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& st) {
    os << "[ ";

    for (size_t i = st.top_index - 1; i >= 0; i--) {
        os << st.data[i] << ' ';
    }

    os << "]\n";

    return os;
}
