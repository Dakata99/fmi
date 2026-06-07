#include "Circle.h"

Circle::Circle(double r):radius(r){}

void Circle::print()const
{
    std::cout << "Circle with radius " << radius << std::endl;
}
double Circle::perimeter()const 
{
    return 2*3.14*radius;
}
double Circle::area()const 
{
    return 3.14*radius*radius;
}