#pragma once
#include "Figure.h"

class Polygon:public Figure
{
private:
    size_t sides;
    double sideLen;
public:
    Polygon(const size_t = 0, const size_t = 0);

    double perimeter()const override;
    double area()const override;
    void print()const override;
};