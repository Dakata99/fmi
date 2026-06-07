#ifndef _FIGURES_H_
#define _FIGURES_H_

#include <vector>

#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

class Menu;

class Figures
{
private:
    friend Menu;
    std::vector<Figure*> figures;

private:
    void print(void) const;
    void within(const Figure*) const;
    void translate(const size_t&, const double&, const double&);

    bool inside(const Figure*&, const Figure*) const;

    Figure* create_rectangle(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    Figure* create_circle(const std::string&, const std::string&, const std::string&, const std::string&);
    Figure* create_line(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
};

#endif