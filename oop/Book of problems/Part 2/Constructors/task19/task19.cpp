#include <iostream>

class Point3
{
private:
    double x, y, z;
public:
    Point3(double x = 0, double y = 0, double z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point3(const Point3& other)
    {
        this->x = other.x; //+1
        this->y = other.y; //+2
        this->z = other.z; //+3
    }
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
    void setX(const double& x)
    {
        this->x = x;
    }
    void setY(const double& y)
    {
        this->y = y;
    }
    void setZ(const double& z)
    {
        this->z = z;
    }
    void print()const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main()
{
    Point3 p1, p2(1, 2, 3);
    p1.print();
    p2.print();

    p1.setX(4);
    p1.setY(5);
    p1.setZ(6);
    
    p1.print();
    
    Point3 p3 = p2;
    p3.print();


    return 0;
}