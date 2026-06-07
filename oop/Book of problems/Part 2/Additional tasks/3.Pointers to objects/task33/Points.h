#pragma once
#include "Point2.h"

class Points
{
private:
    Point2* points;
    size_t current, max;
public:
    Points(const size_t = 1);
    Points(const Points&);
    ~Points();

    Points& operator=(const Points&);

    friend Points intersection(Points&, Points&);

    bool isIn(const Point2&)const;
    size_t getTimes(const Point2&);
    void setSize(const size_t);
    void add(const Point2&);
    //void remove(const size_t);

    void print()const;
};
