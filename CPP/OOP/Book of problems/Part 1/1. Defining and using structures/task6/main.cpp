#include <iostream>
#include <cmath>

struct Point2D
{
    double x, y;
};

double distance(const Point2D& p1, const Point2D& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct Triangle
{
    Point2D a, b, c;
};

bool correct(Point2D& p1, Point2D& p2, Point2D& p3)
{
    double a = distance(p1, p2), b = distance(p2, p3), c = distance(p3, p1);

    return a > 0 && b > 0 && c > 0 && a + b > c || b + c > a || c + a > b;
}

void init_triangle(Triangle& t)
{
    do
    {
        std::cin >> t.a.x >> t.a.y;
        std::cin >> t.b.x >> t.b.y;
        std::cin >> t.c.x >> t.c.y;
    } while (!correct(t.a, t.b, t.c));
}
void print_triangle(const Triangle& t)
{
    double a = distance(t.a, t.b), b = distance(t.b, t.c), c = distance(t.c, t.a);
    std::cout << a << ", " << b << ", " << c << std::endl;
}
double perimeter(const Triangle& t)
{
    double a = distance(t.a, t.b), b = distance(t.b, t.c), c = distance(t.c, t.a);

    return a + b + c;
}
double area(const Triangle& t)
{
    double a = distance(t.a, t.b), b = distance(t.b, t.c), c = distance(t.c, t.a);
    double halfP = (a + b + c)/2;
    
    return sqrt(halfP*(halfP - a)*(halfP - b)*(halfP - c));
}

int main()
{
    Triangle t;
    init_triangle(t);
    print_triangle(t);
    std::cout << "Perimeter: " << perimeter(t) << std::endl;
    std::cout << "Area: " << area(t) << std::endl;

    return 0;
}