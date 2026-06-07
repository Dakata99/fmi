#include "Rectangle.h"

Rectangle::Rectangle(const double& x = 0.0, const double& y = 0.0, 
                     const double& wid = 0.0, const double& hei = 0.0, const std::string& color = "")
                : Figure(x, y, color), width(fabs(wid)), height(fabs(hei)) {}

const std::string Rectangle::get_type(void) const { return "rectangle"; }

const std::string Rectangle::get_info(void) const
{
    std::stringstream s;

    s << "\t<rect x=\"" << start_x << "\" y=\"" << start_y << 
           "\" width=\"" << width  << "\" height=\"" << height <<
           "\" fill=\"" + color + "\" />\n";

    return s.str();
}

double Rectangle::get_start_x(void) const { return start_x; }

double Rectangle::get_start_y(void) const { return start_y; }

double Rectangle::get_end_x(void) const { return start_x + width; }

double Rectangle::get_end_y(void) const { return start_y + height; }

double Rectangle::get_width(void) const { return width; }

double Rectangle::get_height(void) const { return height; }

void Rectangle::translate(const double& x = 0.0, const double& y = 0.0)
{
    start_x += x;
    start_y += y;
}

void Rectangle::print(void) const
{
    std::cout << "rectangle " << start_x << " " << start_y << " " << width << " " << height << " " << color << std::endl;
}