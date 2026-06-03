#include <iostream>
#include <cmath>

struct Point2D
{
    double x, y;
};

void init_point(Point2D& p)
{
    std::cin >> p.x >> p.y;
}
void print_point(const Point2D& p)
{
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}
double distance(const Point2D& p1, const Point2D& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void init_points(Point2D* points, const size_t num)
{
    for (size_t i = 0; i < num; i++)
        init_point(points[i]);
}
void biggestDistance(const Point2D* points, const size_t num)
{
    double max = 0;
    for (size_t i = 0; i < num; i++)
    {
        for (size_t j = i + 1; j < num; j++)
        {
            if (max < distance(points[i], points[j]))
                max = distance(points[i], points[j]);
        }
    }
    std::cout << "Max distance is: " << max << std::endl;
}


void test()
{
    std::cout << "Enter number of points(>= 2 && <= 100): ";
    size_t num; std::cin >>num;

    Point2D* points = new Point2D[num];
    init_points(points, num);
    biggestDistance(points, num);
}

int main()
{
    test();

    return 0;
}
