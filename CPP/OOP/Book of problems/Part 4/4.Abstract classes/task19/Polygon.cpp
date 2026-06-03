#include "Polygon.h"

Polygon::Polygon(const size_t _sides, const size_t len):sides(_sides), sideLen(len){}

double Polygon::perimeter()const
{
    return sides*sideLen;
}
double Polygon::area()const
{
    return 1;
}

void Polygon::print()const
{
    std::cout << "Polygon with " << sides << " sides.\n";
}