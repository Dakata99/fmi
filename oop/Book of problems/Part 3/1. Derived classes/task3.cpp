#include <iostream>
#include <cmath>

class Triangle
{
protected:
    double a, b, c;
    
public:
    void init(const double x, const double y, const double z)
    {
        if (x > 0 && y > 0 && z > 0 && x + y > z && y + z > x && z + x > y)
        {
            a = x;
            b = y;
            c = z;
        }
        else std::cout << "Invalid parameters!" << std::endl;
    }
    double perimeter() const { return a + b + c; }
    double area() const
    {
        double p = (a + b + c)/2;
        return sqrt(p*(p - a)*(p - b)*(p - c));
    }
    void print()const
    {
        std::cout << a << " " << b << " " << c << std::endl;
    }
};
class RightTriangle : public Triangle
{
public:
    void init(const double x, const double y, const double z)
    {
        if (x > 0 && y > 0 && z > 0 )
        {
            if(x*x + y*y == z*z)
            {
                a = x;
                b = y;
                c = z;
            } 
            else if(y*y + z*z == x*x)
            {
                a = y;
                b = z;
                c = x;
            }
            else if(z*z + x*x == y*y)
            {
                a = z;
                b = x;
                c = y;
            }
            else
            {
                std::cout << "Thats not a right triangle!" << std::endl;
                a = b = c = 0;
            }
        }
        else
        {
            std::cout << "Not valid parameters to make a right triangle!" << std::endl;
        }
    }
    double area()const
    {
        return a*b/2;
    }
};
class IsoscelesTriangle:public Triangle
{
public:
    void init(const double x, const double y, const double z)
    {
        if (x > 0 && y > 0 && z > 0 )
        {
            if(x == y)
            {
                a = b = x;
                c = z;
            } 
            else if(y == z)
            {
                a = b = y;
                c = x;
            }
            else if(z == x)
            {
                a = b = z;
                c = y;
            }
            else
            {
                std::cout << "Thats not a isosceles triangle!" << std::endl;
                a = b = c = 0;
            }
        }
        else
        {
            std::cout << "Invalid perimeters to make a isosceles triangle!" << std::endl;
        }
    }
    double area()const
    {
        double height = sqrt(a*a - c*c/4);
        return c*height/2;
    }
};

void func()
{
    Triangle t1;
    t1.init(4, 6, 8);
    t1.print();
    std::cout << "T1 perimeter is: " << t1.perimeter() << std::endl;
    std::cout << "T1 area is: " << t1.area() << std::endl;

    RightTriangle t2;
    t2.init(3, 4, 5);
    t2.print();
    std::cout << "T2 area is: " << t2.area() << std::endl;

    IsoscelesTriangle t3;
    t3.init(4, 8, 8);
    t3.print();
    std::cout << "T3 area is: " << t3.area() << std::endl;
}

int main()
{
    func();

    return 0;
}
