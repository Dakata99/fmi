#include "Square.h"

Square::Square(const double& cx = 0.0, const double& cy = 0.0, const double& _side = 0.0) 
                : Figure(cx, cy), side(_side) {}

void Square::print(void) const
{
    std::cout << "Square with side " << side << std::endl;
    Figure::print();
}

double Square::perimeter(void) const { return 4 * side; }

double Square::area(void) const { return side * side; }