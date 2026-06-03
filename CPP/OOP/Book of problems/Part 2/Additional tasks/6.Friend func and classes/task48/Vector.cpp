#include "Vector.h"
#include <cmath>

template<class T>
Vector<T>::Vector(const size_t num)
{
    size = 0;
    capacity = num;
    vec = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    size = other.sizee();
    capacity = other.capacityy();
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = other.vec[i];
    }
}

template<class T>
Vector<T>::~Vector()
{
    delete[]vec;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        delete[]vec;
        size = other.sizee();
        capacity = other.capacityy();
        for (size_t i = 0; i < size; i++)
        {
            vec[i] = other.vec[i];
        }
    }
    return *this;
}
template<class T>
T& Vector<T>::operator[](const size_t index)
{
    if (index < 0 || index > size)
    {
        exit(-1);
    }
    return vec[index];
}

template<class T>
size_t Vector<T>::sizee()const
{
    return size;
}

template<class T>
size_t Vector<T>::capacityy()const
{
    return capacity;
}

template<class T>
void Vector<T>::resize(const size_t size)
{
    this->size = size;
}

template<class T>
bool Vector<T>::empty()const
{
    return size == 0;
}

template<class T>
void Vector<T>::push_back(const T& data)
{
    if (size + 1 >= capacity)
    {
        capacity = pow(2, capacity);
        T* temp = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = vec[i];
        }
        delete[]vec;
        vec = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            vec[i] = temp[i];
        }
        delete[]temp;
    }
    vec[size++] = data;
}

template<class T>
void Vector<T>::pop_back()
{
    if (empty())
    {
        std::cout << "Vector is empty!\n";
        return;
    }
    T* temp = new T[capacity];
    size--;
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = vec[i];
    }
    delete[]vec;
    vec = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = temp[i];
    }
    delete[]temp;
}

template<class T>
Vector<T>& Vector<T>::sum(const Vector<T>& other)
{
    if (size != other.sizee())
    {
        std::cout << "Cannot add vectors with different sizes!\n";
        exit(-1);
    }
    for (size_t i = 0; i < size; i++)
    {
        vec[i] += other.vec[i];
    }
    
    return *this;
}

template<class T>
Vector<T>& Vector<T>::substract(const Vector<T>& other)
{
    if (size != other.sizee())
    {
        std::cout << "Cannot substract vectors with different sizes!\n";
        exit(-1);
    }
    for (size_t i = 0; i < size; i++)
    {
        vec[i] -= other.vec[i];
    }
    
    return *this;
}

template<class T>
Vector<T>& Vector<T>::multiply(const double k)
{
    for (size_t i = 0; i < size; i++)
    {
        vec[i] *= k;
    }
    return *this;
}

template<class T>
void Vector<T>::print()const
{
    std::cout << "(";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << ")\n";
}