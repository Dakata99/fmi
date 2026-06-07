#include "Point2.h"

Point2::Point2(const double X, const double Y):x(X), y(Y){}

Point2& Point2::operator=(const Point2& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}
bool Point2::operator==(const Point2& other)const
{
    return x == other.x && y == other.y;
}

void Point2::setX(const double X)
{
    x = X;
}
void Point2::setY(const double Y)
{
    y = Y;
}

double Point2::getX()const
{
    return x;
}
double Point2::getY()const
{
    return y;
}

void Point2::print()const
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}