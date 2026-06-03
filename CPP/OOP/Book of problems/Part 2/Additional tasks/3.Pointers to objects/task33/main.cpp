#include <iostream>
#include "Point2.cpp"
#include "Points.cpp"

int main()
{
    Points ps(8);
    ps.add(Point2(1, 2));
    ps.add(Point2(3, 4));
    ps.add(Point2(5, 6));
    ps.add(Point2(7, 8));
    ps.add(Point2(9, 10));
    ps.add(Point2(1, 2));
    ps.add(Point2(7, 8));
    ps.add(Point2(11, 12));
    ps.print();

    Points ps2(5);
    ps2.add(Point2(3, 4));
    ps2.add(Point2(1, 2));
    ps2.add(Point2(11, 12));
    ps2.add(Point2(99, 10));
    ps2.add(Point2(1, 2));
    ps2.print();

    Points temp = intersection(ps, ps2);
    temp.print();
    
    return 0;
}