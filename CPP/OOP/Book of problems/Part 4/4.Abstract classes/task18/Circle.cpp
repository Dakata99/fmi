#include "Circle.h"

Circle::Circle(const double& cx = 0.0, const double& cy = 0.0, const double& r = 0.0) 
                        : Figure(cx, cy), radius(r) {}

void Circle::print(void) const
{
    std::cout << "Circle with radius " << radius << std::endl;
    Figure::print();
}

double Circle::perimeter(void) const { return 2 * 3.14 * radius; }

double Circle::area(void) const { return 3.14 * radius * radius; }