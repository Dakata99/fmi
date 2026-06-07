#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <string>
#include <cmath>

class Figure
{
protected:
    double start_x, start_y;
    std::string color;

public:
    Figure(const double&, const double&, const std::string&);

    virtual const std::string get_type(void) const = 0;
    virtual const std::string get_info(void) const = 0;

    virtual double get_start_x(void) const = 0;
    virtual double get_start_y(void) const = 0;

    virtual void translate(const double&, const double&) = 0;

    virtual void print(void) const = 0;
};

#endif