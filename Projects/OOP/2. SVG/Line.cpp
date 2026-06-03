#include "Line.h"

Line::Line(const double& start_x = 0.0, const double& start_y = 0.0, 
           const double& end_x_ = 0.0, const double& end_y_ = 0.0, const double& str_width = 0.0, 
           const std::string& col = "")
            : Figure(start_x, start_y, col), end_x(fabs(end_x_)), end_y(fabs(end_y_)), stroke_width(fabs(str_width)) {}

const std::string Line::get_type(void) const { return "line"; }

const std::string Line::get_info(void) const
{
    std::stringstream s;
    
    s << "\t<line x1=\"" << start_x << "\" y1=\"" << start_y <<
            "\" x2=\"" << end_x << "\" y2=\"" << end_y <<
            "\" stroke-width=\"" << stroke_width <<  
            "\" stroke=\"" + color + "\" />\n";

    return s.str();
}

double Line::get_start_x(void) const { return start_x; }

double Line::get_start_y(void) const { return start_y; }

double Line::get_end_x(void) const { return end_x; }

double Line::get_end_y(void) const { return end_y; }

double Line::get_stroke_width(void) const { return stroke_width; }

void Line::translate(const double& x = 0.0, const double& y = 0.0)
{
    start_x += x;
    start_y += y;
    end_x += x;
    end_y += y;
}

void Line::print(void) const
{
    std::cout << "line " << start_x << " " 
                         << start_y << " " 
                         << end_x << " " 
                         << end_y << " " 
                         << stroke_width << " " 
                         << color << std::endl;
}
