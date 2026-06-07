#include "Rectangle.h"

Rectangle::Rectangle(const double& cx = 0.0, const double& cy = 0.0, const double& _a = 0.0, const double& _b = 0.0) 
                    : Figure(cx, cy), a(_a), b(_b) {}

void Rectangle::print(void) const
{
    std::cout << "Rectangle with sides " << a << " and " << b << std::endl;
    Figure::print();
}

double Rectangle::perimeter(void) const { return 2 * a + 2 * b; }

double Rectangle::area(void) const { return a * b; }