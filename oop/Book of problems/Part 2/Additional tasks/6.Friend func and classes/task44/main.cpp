#include <iostream>

class Point3
{
private:
    double x, y, z;
public: 
    Point3(const double X = 0, const double Y = 0, const double Z = 0):x(X), y(Y), z(Z){}

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

    void setX(const double X)
    {
        x = X;
    }
    void setY(const double Y)
    {
        y = Y;
    }
    void setZ(const double Z)
    {
        z = Z;
    }

    friend void symmetric(Point3& p)
    {
        p.x = -p.x;
        p.y = -p.y;
        p.z = -p.z;
    }
    friend void lexic(const Point3& first, const Point3& second)
    {
        bool flag = first.getX() >= second.getX() && first.getY() >= second.getY() && first.getZ() >= second.getZ();
        if(flag)
        {
            std::cout << "First is: ";first.print();
            std::cout << "Second is: ";second.print();
        }
        else
        {
            std::cout << "First is: ";second.print();
            std::cout << "Second is: ";first.print();
        }
    }

    void print()const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main()
{
    Point3 p1(1, 2, 3), p2(4, 5, 6);
    symmetric(p2);
    p1.print();
    p2.print();
    lexic(p1, p2);

    return 0;
}