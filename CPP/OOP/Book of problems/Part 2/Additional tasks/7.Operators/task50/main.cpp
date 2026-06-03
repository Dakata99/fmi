#include <iostream>

class Point2
{
private:
    int x, y;
public:
    Point2(int a, int o)
    {
        x = a;
        y = o;
    }
    void operator-(const Point2& p)
    {
        x -= p.x;
        y -= p.y;
    }
};