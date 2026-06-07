#include <iostream>

class Point3
{
private:
    double x, y, z;
public:
    Point3(const double = 0, const double = 0, const double = 0);

    double getX()const;
    double getY()const;
    double getZ()const;

    void print()const;
};

Point3::Point3(const double X, const double Y, const double Z):x(X), y(Y), z(Z){}

double Point3::getX()const
{
    return x;
}
double Point3::getY()const
{
    return y;
}
double Point3::getZ()const
{
    return z;
}

void lieOnOctant(const Point3* points, const size_t size)
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < size; i++)
    {
        if (points[i].getX() >= 0 && points[i].getY() >= 0 && points[i].getZ() >= 0)
        {
            arr[0]++;
        }
        else if (points[i].getX() < 0 && points[i].getY() >= 0 && points[i].getZ() >= 0)
        {
            arr[1]++;
        }
        else if (points[i].getX() < 0 && points[i].getY() < 0 && points[i].getZ() >= 0)
        {
            arr[2]++;
        }        
        else if (points[i].getX() >= 0 && points[i].getY() < 0 && points[i].getZ() >= 0)
        {
            arr[3]++;
        }
        else if (points[i].getX() >= 0 && points[i].getY() >= 0 && points[i].getZ() < 0)
        {
            arr[4]++;
        }
        else if (points[i].getX() < 0 && points[i].getY() >= 0 && points[i].getZ() < 0)
        {
            arr[5]++;
        }
        else if (points[i].getX() < 0 && points[i].getY() < 0 && points[i].getZ() < 0)
        {
            arr[6]++;
        }
        else
        {
            arr[7]++;
        }
    }
    for (size_t i = 0; i < 8; i++)
        std::cout << "Number of points in " << i << " octant is: " << arr[i] << std::endl;
}
size_t lieOnPlane(const Point3* points, const size_t size)
{
    size_t counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        double temp = points[i].getX()*points[i].getX() + points[i].getY()*points[i].getY() + points[i].getZ()*points[i].getZ();
        if (temp == 0)
        {
            counter++;
        }
    }
    return counter;
}
size_t zeroPoint(const Point3* points, const size_t size)
{
    size_t counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (points[i].getX() == 0 && points[i].getY() == 0 && points[i].getZ() == 0)
        {
            counter++;
        }
        
    }
    return counter;
}

int main()
{
    Point3* points = new Point3[6];
    points[0] = Point3(1, 4, 2);
    points[1] = Point3(-1, 14, -9);
    points[2] = Point3(11, 41, -2);
    points[3] = Point3(0, 0, 0);
    points[4] = Point3(6, 5, -2);
    points[5] = Point3(-1, 11, 0);

    lieOnOctant(points, 6);
    std::cout << lieOnPlane(points, 6) << std::endl;
    std::cout << zeroPoint(points, 6) << std::endl;

    return 0;
}
