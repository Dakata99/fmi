#include <iostream>

class Point3
{
private:
    double x, y, z;
public:
    Point3(const double X = 0, const double Y = 0, const double Z = 0):x(X), y(Y), z(Z){}

    void setX(double X)
    {
        x = X;
    }
    void setY(double Y)
    {
        y = Y;
    }
    void setZ(double Z)
    {
        z = Z;
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

    void print()const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

void func()
{
    std::cout << "Enter a number between 1 and 20: ";
    size_t n;
    std::cin >> n;

    Point3* points = new Point3[n];
    for (size_t i = 0; i < n; i++)
    {
        points[i].setX(i);
        points[i].setY(i + 1);
        points[i].setZ(i - 1);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        double result = points[i].getX()*points[i].getX() + points[i].getY()*points[i].getY() + points[i].getZ()*points[i].getZ();
        if (result >= 1 && result <= 9)
        {
            points[i].print();
        }
    }
}

int main()
{
    func();

    return 0;
}
