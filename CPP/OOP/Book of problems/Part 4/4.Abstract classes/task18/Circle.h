#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Figure.h"

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(const double&, const double&, const double&);
    
    double area(void) const override;
    double perimeter(void) const override;
    virtual void print(void) const;
};

#endif