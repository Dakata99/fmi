#include <iostream>
#include <cmath>

class Point
{
private:
    double x, y;
public:
    Point(const double X = 0.0, const double Y = 0.0):x(X), y(Y){}
    
    double getX()const
    {
        return x;
    }
    double getY()const
    {
        return y;
    }
};


class Line
{
private:
    Point p1, p2;
public:
    Line(const Point& pp1, const Point& pp2):p1(pp1), p2(pp2){}
    Point point1()const
    {
        return p1;
    }
    Point point2()const
    {
        return p2;
    }
    double length()const
    {
        return sqrt((p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY()));
    }

    friend bool perpendicular(const Line& l1, const Line& l2)
    {
        double k1 = (l1.p1.getX() - l1.p2.getX()) /(l1.p1.getY() - l1.p2.getY());
        double k2 = (l2.p1.getX() - l2.p2.getX()) /(l2.p1.getY() - l2.p2.getY());
    
        return k1*k2 == -1;
    }
};

int main()
{
    Line l1(Point(2, 3), Point(3, 4)), l2(Point(8, 5), Point(4, 1));
    std::cout << std::boolalpha << perpendicular(l1, l2) << std::endl;

    return 0;
}
