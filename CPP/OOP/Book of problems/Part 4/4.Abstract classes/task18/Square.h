#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Figure.h"

class Square : public Figure
{
private:
    double side;

public:
    Square(const double&, const double&, const double&);

    virtual void print(void) const;
    double perimeter(void) const override;
    double area(void) const override;
};

#endif