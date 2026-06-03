#pragma once
#include "Point3.h"

template<class T, class U>
class ColPoint3:public Point3<T>
{
private:
    U color;
public:
//des/constructors
    ColPoint3(const T = 0, const T = 0, const T = 0, const U = 0);
    ColPoint3(const Point3<T>, const U);
    ColPoint3(const ColPoint3&);
//operators
    ColPoint3& operator=(const ColPoint3&);
//getters
    U getColor()const;
//setters
    void setColor(const U);
//funcs
    void printColPoint3()const;
};