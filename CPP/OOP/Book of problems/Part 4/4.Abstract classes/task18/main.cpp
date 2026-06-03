#include <iostream>

#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

int main(void)
{
    Figure* figs[3];
    
    figs[0] = new Circle(0, 0, 1);
    figs[1] = new Square(0, 0, 1);
    figs[2] = new Rectangle(0, 0, 1, 1);

    figs[0]->print();
    std::cout << "Perimeter: " << figs[0]->perimeter() << " and area " << figs[0]->area() << std::endl;
    
    figs[1]->print();
    std::cout << "Perimeter: " << figs[1]->perimeter() << " and area " << figs[1]->area() << std::endl;
    
    figs[2]->print();
    std::cout << "Perimeter: " << figs[2]->perimeter() << " and area " << figs[2]->area() << std::endl;

    double  sum_perims = 0.0, 
            sum_areas = 0.0;
    
    for (size_t i = 0; i < 3; i++)
    {
        sum_perims += figs[i]->perimeter();
        sum_areas += figs[i]->area();
    }
    
    std::cout << "Sum of all perimeters is: " << sum_perims << std::endl;
    std::cout << "Sum of all areas is: " << sum_areas << std::endl;
    
    return 0;
}