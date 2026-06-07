#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cassert>
#include <cmath>
#include <iostream>

template <class T>
class Iterator;

template <class T>
class Vector {
private:
    friend Iterator<T>;
    T* data;
    size_t size, capacity;

private:
    void copy(const Vector&);
    void del(void);
    void init(const size_t&, const T&);

public:
    // Constructors
    Vector();
    Vector(const size_t&);
    Vector(const size_t&, const T&);
    Vector(const Vector&);
    Vector(const Iterator<T>&, const Iterator<T>&);
    ~Vector();

    Vector& operator=(const Vector&);

    // Iterators
    Iterator<T> begin(void);
    Iterator<T> end(void);
    Iterator<T> rbegin(void);
    Iterator<T> rend(void);
    Iterator<T> cbegin(void) const;
    Iterator<T> cend(void) const;
    Iterator<T> crbegin(void) const;
    Iterator<T> crend(void) const;

    // capacity
    size_t get_size(void) const;
    size_t get_max_size(void) const;
    void resize(const size_t&, T& = T());
    size_t capacity_vec(void) const;
    bool empty(void) const;
    void reserve(const size_t&);
    void shrink_to_fit(void);

    // element access
    const T& operator[](size_t) const;
    const T& at(size_t) const;
    T& front(void) const;
    T& back(void) const;
    T* get_data(void);

    // modifiers
    void assign(size_t, const T&);
    void push_back(const T&);
    void pop_back(void);
    void insert(void);
    void erase(void);
    void swap(Vector<T>&);
    void clear(void);
    void emplace(void);
    void emplace_back(void);

    // non-member function overloads
    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;

    bool operator>=(const Vector&) const;
    bool operator>(const Vector&) const;

    bool operator<=(const Vector&) const;
    bool operator<(const Vector&) const;

    template <class E>
    friend void swap(Vector<E>&, Vector<E>&);

    // printing funcs
    template <class E>
    friend std::ostream& operator<<(std::ostream&, const Vector<E>&);
};

#endif
