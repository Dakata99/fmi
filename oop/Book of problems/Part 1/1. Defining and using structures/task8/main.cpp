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
void init_points(Point2D* points, const size_t num)
{
    for (size_t i = 0; i < num; i++)
        init_point(points[i]);
}
void print_point(const Point2D& p)
{
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}
void print_points(const Point2D* points, const size_t num)
{
    for (size_t i = 0; i < num; i++)
        print_point(points[i]);
}
void sort(Point2D*& points, const size_t num)
{
    for (size_t i = 0; i < num; i++)
    {
        for (size_t j = i + 1; j < num; j++)
        {
            bool flag = points[i].x < points[j].x || points[i].x == points[j].x && points[i].y < points[j].y;
            if (!flag)
            {
                std::swap(points[i], points[j]);
            }
        }
    }
}

int main()
{
    std::cout << "Enter number of poits(>= 2 && <= 100): ";
    size_t n;
    std::cin >> n;

    Point2D* points = new Point2D[n];
    init_points(points, n);
    print_points(points, n);
    sort(points, n);
    print_points(points, n);

    return 0;
}
