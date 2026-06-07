#include <iostream.h>
#include <stdlib.h>
#include <math.h>

// дефиниция на клас Triangle
class Triangle
{
protected:
    double a, b, c;                     // страни на триъгълника

public:
    void init(double, double, double);  // инициализиране
    double perimeter() const;           // намиране на периметъра
    double area() const;                // намиране на лицето
    void print() const;                 // извеждане на страните
};

void Triangle::init(double x, double y, double z)
{
    if(x > 0 && y > 0 && z > 0 && 
       x + y > z && x + z > y && y + z > x)
    {
        a = x;
        b = y;
        c = z;
    }
    else 
    {
        cout << x << ", " << y << ", " << z 
             << " не могат да са страни на триъгълник.\n";
        exit(1);
    }
}

double Triangle::perimeter() const
{
    return a + b + c;
}

double Triangle::area() const
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

void Triangle::print() const
{
    cout << a << ", " << b << ", " << c << endl;
}

// дефиниция на клас RightTriangle
class RightTriangle : public Triangle
{
public:
    void init(double, double, double);  // инициализиране
    double area() const;                // намиране на лицето
};

void RightTriangle::init(double x, double y, double z)
{
    Triangle::init(x, y, z);
    if(fabs(x*x + y*y - z*z) > 1.0e-14 &&
       fabs(x*x + z*z - y*y) > 1.0e-14 &&
       fabs(y*y + z*z - x*x) > 1.0e-14)
    {
        cout << "Триъгълникът не е правоъгълен!\n";
        exit(1);
    }
}

double RightTriangle::area() const
{
    if(fabs(a*a + b*b - c*c) <= 1e-14) 
        return a*b / 2;
    else if(fabs(a*a + c*c - b*b) <= 1e-14) 
        return a*c / 2;
    else 
        return b*c / 2;
}

// дефиниция на клас IsoscelesTriangle
class IsoscelesTriangle : public Triangle
{
public:
    void init(double, double, double);      // инициализиране
    double area() const;                    // намиране на лицето
};

void IsoscelesTriangle::init(double x, double y, double z)
{
    Triangle::init(x, y, z);
    if (fabs(x-y) > 1.0e-14 &&
        fabs(x-z) > 1.0e-14 &&
        fabs(y-z) > 1.0e-14)
    {
        cout << "Триъгълникът не е равнобедрен.\n";
        exit(1);
    }
}

double IsoscelesTriangle::area() const
{
    if(fabs(a - b) <= 1.0e-14) 
        return sqrt(a*a - c*c/4)*c/2;
    else if(fabs(a - c) <= 1.0e-14) 
        return sqrt(a*a - b*b/4)*b/2;
    else 
        return sqrt(b*b-a*a/4)*a/2;
}

int main()
{
    // създаване на триъгълник
    Triangle t1;
    t1.init(2, 3, 4);
    // извеждане на триъгълника
    t1.print();
    // извеждане на периметъра и лицето на триъгълника
    cout << t1.perimeter() << " " << t1.area() << endl;
    // създаване на правоъгълен триъгълник
    RightTriangle t2;
    t2.init(6, 10, 8);
    // извеждане на триъгълника
    t2.print();
    // извеждане на периметъра и лицето на триъгълника
    cout << t2.perimeter() << " " << t2.area() << endl;
    // създаване на равнобедрен триъгълник
    IsoscelesTriangle t3;
    t3.init(5, 4, 5);
    // извеждане на триъгълника
    t3.print();
    // извеждане на периметъра и лицето на триъгълника
    cout << t3.perimeter() << " " << t3.area() << endl;
    return 0;
}
