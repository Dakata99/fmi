#include "Point3.h"

//des/constructors
template<class T>
Point3<T>::Point3(const T X, const T Y, const T Z):x(X), y(Y), z(Z){}

template<class T>
Point3<T>::Point3(const Point3<T>& other):x(other.x), y(other.y), z(other.z){}

//operators
template<class T>
Point3<T>& Point3<T>::operator=(const Point3<T>& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

//getters
template<class T>
T Point3<T>::getX()const
{
    return x;
}

template <class T>
T Point3<T>::getY()const
{
    return y;
}

template<class T>
T Point3<T>::getZ()const
{
    return z;
}

//setters
template<class T>
void Point3<T>::setX(const T X)
{
    x = X;
}

template<class T>
void Point3<T>::setY(const T Y)
{
    y = Y;
}

template<class T>
void Point3<T>::setZ(const T Z)
{
    z = Z;
}

//funcs
template<class T>
void Point3<T>::printPoint3()const
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}