#include "Circle.h"

Circle::Circle(const double& cx = 0.0, const double& cy = 0.0, const double& r = 0.0, const std::string& col = "")
                : Figure(cx, cy, col), radius(fabs(r)) {}

const std::string Circle::get_type(void) const { return "circle"; }

const std::string Circle::get_info(void) const
{
    std::stringstream s;

    s << "\t<circle cx=\"" << start_x << "\" cy=\"" << start_y <<
           "\" r=\"" << radius << "\" fill=\"" + color + "\" />\n";

    return s.str();
}

double Circle::get_start_x(void) const { return start_x; }

double Circle::get_start_y(void) const { return start_y; }

double Circle::get_radius(void) const { return radius; }

void Circle::translate(const double& x = 0.0, const double& y = 0.0)
{
    start_x += x;
    start_y += y;
}

void Circle::print(void)const
{
    std::cout << "circle " << start_x << " " << start_y << " " << radius << " " << color << std::endl;
}
