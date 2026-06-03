#include <iostream>
#include <cmath>

class Point
{
private:
    double x, y;
public:
    Point(const double _x = 0, const double _y = 0):x(_x), y(_y){}
    
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
    Point pt1, pt2;
public:
    Line(const Point& _pt1, const Point& _pt2):pt1(_pt1), pt2(_pt2){}

    double distance()
    {
        return sqrt((pt1.getX() - pt2.getX())*(pt1.getX() - pt2.getX()) + (pt1.getY() - pt2.getY())*(pt1.getY() - pt2.getY()));
    }
};

class Triangle
{
private:
    Point pt1, pt2, pt3;
public:
    Triangle(const Point& _pt1, const Point& _pt2, const Point& _pt3):pt1(_pt1), pt2(_pt2), pt3(_pt3){}

    double perimeter()const
    {
        Line l1(pt1, pt2), l2(pt2, pt3), l3(pt3, pt1);
        double a = l1.distance();
        double b = l2.distance();
        double c = l3.distance();

        return a + b + c;
    }
    double area()const
    {
        Line l1(pt1, pt2), l2(pt2, pt3), l3(pt3, pt1);
        double a = l1.distance();
        double b = l2.distance();
        double c = l3.distance();
        double p = (a + b + c)/2;

        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    bool isRight()const
    {
        Line l1(pt1, pt2), l2(pt2, pt3), l3(pt3, pt1);
        double a = l1.distance();
        double b = l2.distance();
        double c = l3.distance();

        if (a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b)
        {
            return true;
        }
        return false;
    }
    bool isIsosceles()const
    {
        Line l1(pt1, pt2), l2(pt2, pt3), l3(pt3, pt1);
        double a = l1.distance();
        double b = l2.distance();
        double c = l3.distance();

        if (a == b || b == c || c == a)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Triangle t(Point(1, 2), Point(3, 4), Point(5, 2));
    std::cout << t.perimeter() << std::endl;
    std::cout << t.area() << std::endl;
    std::cout << std::boolalpha << t.isIsosceles() << std::endl;
    std::cout << std::boolalpha << t.isRight() << std::endl;

    return 0;
}