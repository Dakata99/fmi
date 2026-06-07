#pragma once

template<class T>
class Point3
{
private:
    T x, y, z;
public:
//des/constructors
    Point3(const T = 0, const T = 0, const T = 0);
    Point3(const Point3&);
//operators
    Point3& operator=(const Point3&);
//getters
    T getX()const;
    T getY()const;
    T getZ()const;
//setters
    void setX(const T);
    void setY(const T);
    void setZ(const T);
//funcs
    void printPoint3()const;
};