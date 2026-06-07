#include "Figure.h"

Figure::Figure(const double& cx = 0.0, const double& cy = 0.0) : x(cx), y(cy) {}

void Figure::print(void) const { std::cout << "x: " << x << " y: " << y << std::endl; }