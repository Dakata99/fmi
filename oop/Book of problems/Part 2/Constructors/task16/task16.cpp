#include <iostream>
#include <cmath>

class Point
{
private:
    double x, y;
public:
    Point()
    {
        x = y = 0;  
    }
    Point(double a, double b)
    {
        x = a; y = b;
    }
    double xcoord()const
    {
        return x;
    }
    double ycoord()const
    {
        return y;
    }
};

class Line
{
private:
    Point p1, p2;
public:
    Line(const Point& _p1, const Point& _p2)
    {
        p1 = Point(_p1.xcoord(), _p1.ycoord());
        p2 = Point(_p2.xcoord(), _p2.ycoord());
    }
    Point point1() const
    {
        return p1;
    }
    Point point2() const
    {
        return p2;
    }
    double len() const
    {
        return sqrt((p1.xcoord() - p2.xcoord()) * (p1.xcoord() - p2.xcoord()) + 
                    (p1.ycoord() - p2.ycoord()) * (p1.ycoord() - p2.ycoord()));
    }
    double slope() const
    {
        return (p1.ycoord() - p2.ycoord())/(p1.xcoord() - p2.xcoord());
    }
    Point intersection(const Line& line) const
    {
        double A1 = p1.ycoord() - p2.ycoord();
        double B1 = p2.xcoord() - p1.xcoord();
        double C1 = p1.xcoord()*p2.ycoord() - p2.xcoord()*p1.ycoord();
        
        double A2 = line.p1.ycoord() - line.p2.ycoord();
        double B2 = line.p2.xcoord() - line.p1.xcoord();
        double C2 = line.p1.xcoord()*line.p2.ycoord() - line.p2.xcoord()*line.p1.ycoord();


        return Point (((-C1)*B2 - (-C2)*B1)/(A1*B2 - A2*B1), (A1*(-C2) - A2*(-C1))/(A1*B2 - A2*B1));
    }
};

void func()
{
    Point p1(0,0), p2(8,0), p3(8,4), p4(0,4);
    Line l1(p1, p3), l2(p2, p4);
    std::cout << l1.len() << std::endl;
    std::cout << l1.slope() << " " << l2.slope() << std::endl;
    std::cout << l1.intersection(l2).xcoord() << " " << l1.intersection(l2).ycoord() << std::endl;
}

int main()
{
    func();

    return 0;
}