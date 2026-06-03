#include <iostream>
#include <cmath>

class Line;

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

    friend bool lies(const Point& p, const Line& l);
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

    friend bool lies(const Line& l, const Point& p)
    {
        double x = l.p1.getX() - l.p2.getX(), y = l.p1.getY() - l.p2.getY();

        return x*p.getX() + y*p.getY() == 0;
    }
};

bool lies(const Point& p, const Line& l)
{
    double x = l.point1().getX() - l.point2().getX(), y = l.point1().getY() - l.point2().getY();

    return x*p.getX() + y*p.getY() == 0;
}

int main()
{
    Line l(Point(2, 3), Point(3, 4));
    Point p(-1, 1);
    std::cout << std::boolalpha << lies(l, p) << std::endl;

    return 0;
}
