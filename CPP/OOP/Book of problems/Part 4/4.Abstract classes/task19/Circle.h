#pragma once
#include "Figure.h"

class Circle:public Figure
{
private:
    double radius;
public:
    Circle(double = 0);
    double perimeter()const override;
    double area()const override;
    void print()const override;
};