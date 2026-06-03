#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Figure.h"

class Rectangle : public Figure
{
private:
    double a, b;

public:
    Rectangle(const double&, const double&, const double&, const double&);

    double area(void) const override;
    double perimeter(void) const override;
    virtual void print(void) const;
};

#endif