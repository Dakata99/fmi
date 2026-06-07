#pragma once

template<class T>
class Vector
{
private:
    T* vec;
    size_t size, capacity;
public:
//des/constructors
    Vector(const size_t = 1);
    Vector(const Vector&);
    ~Vector();

//operators
    Vector& operator=(const Vector&);
    T& operator[](const size_t index);

//getters
    size_t sizee()const;
    size_t capacityy()const;

//setters
    void resize(const size_t);

//funcs
    bool empty()const;
    void push_back(const T&);
    void pop_back();

    Vector& sum(const Vector&);
    Vector& substract(const Vector&);
    Vector& multiply(const double);
    
    

    void print()const;
};
