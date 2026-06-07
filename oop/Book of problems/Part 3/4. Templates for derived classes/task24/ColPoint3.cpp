#include "ColPoint3.h"

//des/constructors
template<class T, class U>
ColPoint3<T, U>::ColPoint3(const T X, const T Y, const T Z, const U col):Point3<T>(X, Y, Z), color(col){}

template<class T, class U>
ColPoint3<T, U>::ColPoint3(const Point3<T> p, const U col):Point3<T>(p), color(col){}

template<class T, class U>
ColPoint3<T, U>::ColPoint3(const ColPoint3& other)
{
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());
    color = other.color;
}

//operators
template<class T, class U>
ColPoint3<T, U>& ColPoint3<T, U>::operator=(const ColPoint3& other)
{
    if (this != &other)
    {
        setX(other.getX());
        setY(other.getY());
        setZ(other.getZ());
        color = other.color;
    }
    return *this;
}

//getters
template<class T, class U>
U ColPoint3<T, U>::getColor()const
{
    return color;
}

//setters
template<class T, class U>
void ColPoint3<T, U>::setColor(const U col)
{
    color = col;
}

//funcs
template<class T, class U>
void ColPoint3<T, U>::printColPoint3()const
{
    Point3<T>::printPoint3();
    std::cout << "Color: " << color << std::endl;
}