#include "Figure.h"

Figure::Figure(const double& x = 0.0, const double& y = 0.0, const std::string& col = "")
                    : start_x(fabs(x)), start_y(fabs(y)), color(col) {}