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

void initPoints(unsigned int n, Point3 p[])
{
    for (size_t i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        p[i].setX(x);
        std::cin >> x;
        p[i].setY(x);
        std::cin >> x;
        p[i].setZ(x);
    }
}
void symetric(size_t n, Point3 p[])
{
    for (size_t i = 0; i < n; i++)
    {
        p[i].setX(-p[i].getX());
        p[i].setY(-p[i].getY());
        p[i].setZ(-p[i].getZ());
    }
}
void printPoints(size_t n, Point3 p[])
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "(" << p[i].getX() << ", " << p[i].getY() << ", " << p[i].getZ() << ")" << std::endl;
    }
}
bool lexic(const Point3& p1, const Point3& p2)
{
    return p1.getX() < p2.getX() || p1.getX() == p2.getX() && p1.getY() < p2.getY() || p1.getY() == p2.getY()
            && p1.getZ() < p2.getZ() || p1.getZ() == p2.getZ();
}
void sortPoints(size_t n, Point3 p[])
{
    for (size_t i = 0; i < n - 1; i++)
    {
        int k = i;
        Point3 min = p[i];
        for (size_t j = i + 1; i < n; i++)
        {
            if (lexic(p[j], min))
            {
                min = p[j];
                k = j;
            }
            p[k] = p[i];
            p[i] = min;
        }        
    }
}
bool lexic(const Point3* p1, const Point3* p2)
{
    return p1->getX() < p2->getX() || p1->getX() == p2->getX() && p1->getX() < p2->getX() || p1->getX() == p1->getX()
            && p1->getX() < p2->getX() || p1->getX() == p2->getX();
}
void sortPoints(size_t n, Point3** p)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        int k = i;
        Point3* min = p[i];
        for (size_t j = i + 1; i < n; i++)
        {
            if (lexic(p[j], min))
            {
                min = p[j];
                k = j;
            }
            p[k] = p[i];
            p[i] = min;
        }        
    }
}

int main()
{
    /*
    Point3 p1, p2(1, 2, 3);
    p1.print();
    p2.print();

    p1.setX(4);
    p1.setY(5);
    p1.setZ(6);
    
    p1.print();
    
    Point3 p3 = p2;
    p3.print();
    */

   /*
    Point3* points = new Point3[3];
    initPoints(3, points);
    symetric(3, points);
    printPoints(3, points);
    */



    return 0;
}