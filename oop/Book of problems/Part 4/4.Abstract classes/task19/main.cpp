#include <iostream>
#include "Figure.cpp"
#include "Circle.cpp"
#include "Polygon.cpp"

int main()
{
    Circle c(5);
    std::cout << "Circle area: " << c.area() << std::endl;
    std::cout << "Circle perimeter: " << c.perimeter() << std::endl;
    c.print();

    Polygon p(5, 3);
    std::cout << "Polygon area: " << p.area() << std::endl;
    std::cout << "Polygon perimeter: " << p.perimeter() << std::endl;
    p.print();

    return 0;
}