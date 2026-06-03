#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>

class Figure
{
protected:
    double x, y;

public:
    Figure(const double&, const double&);
    
    virtual double area(void) const = 0;
    virtual double perimeter(void) const = 0;
    virtual void print(void) const;
};

#endif