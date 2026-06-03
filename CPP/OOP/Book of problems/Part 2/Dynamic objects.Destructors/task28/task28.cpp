#include <iostream>
#include <cmath>

class Point3
{
private:
    double x, y, z;
public:
    Point3(const int a = 0, const int b = 0, const int c = 0):x(a), y(b), z(c){}

    double getX()const
    {
        return x;
    }
    double getY()const
    {
        return y;
    }
    double getZ()const
    {
        return z;
    }

    void print()const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

double distance(const Point3& p)
{
    return sqrt(p.getX() * p.getX() + p.getY() * p.getY() + p.getZ() * p.getZ());
}

void func()
{
    Point3** points = new Point3*[10];
    if (!points)
    {
        std::cout << "Error with allocating memory!" << std::endl;
        return;
    }
    double min = distance(*points[0]), max = distance(*points[0]);
    for (size_t i = 0; i < 10; i++)
    {
        double d = distance(*points[i]);
        if(d < min) min = d;
        if(d > max) max = d;
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        *points[i] = Point3(i + 1, i + 1, i + 1);
    }

    std::cout << "Points with least distance: " << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        if (fabs(distance(*points[i]) - min) > 1E-14)
        {
            points[i]->print();
        }   
    }

    std::cout << "Points with max distance: " << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        if (fabs(distance(*points[i]) - max) < 1E-14)
        {
            points[i]->print();
        }   
    }

    for (size_t i = 0; i < 10; i++)
    {
        delete points[i];
    }
    delete[]points;
}

int main()
{
    func();

    return 0;
}