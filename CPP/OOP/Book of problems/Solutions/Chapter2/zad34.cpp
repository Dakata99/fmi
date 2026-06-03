#include <iostream.h>

class SquarePyramid;               // предварителна декларация

// дефиниция на класа Cylinder
class Cylinder
{
private:
    double radius;                 // радиус на основата
    double height;                 // височина

public:
    Cylinder(double, double);      // конструктор
    double getRadius() const;      // достъп до радиуса
    double getHeight() const;      // достъп до височината
    // декларация на приятелската функция
    friend bool IsHigher(const Cylinder&, const SquarePyramid &);
};

Cylinder::Cylinder(double r, double h)
{
    radius = r;
    height = h;
}

double Cylinder::getRadius() const
{
    return radius;
}

double Cylinder::getHeight() const
{
    return height;
}

// дефиниция на класа SquarePyramid
class SquarePyramid
{
private:
    double side;                     // основа
    double height;                   // височина

public:
    SquarePyramid (double, double);  // конструктор
    double getSide() const;          // достъп до основата
    double getHeight() const;        // достъп до височината
    // декларация на приятелската функция
    friend bool IsHigher(const Cylinder&, const SquarePyramid &);
};

SquarePyramid::SquarePyramid(double s, double h)
{
    side = s;
    height = h;
}

double SquarePyramid::getSide() const
{
    return side;
}

double SquarePyramid::getHeight() const
{
    return height;
}

// дефиниция на приятелската на двата класа функция
bool IsHigher(const Cylinder& c, const SquarePyramid & s)
{
    return c.height > s.height;
}

int main()
{
    // дефиниране на цилиндър
    Cylinder c(12.5, 8.0);
    // дефиниране на квадратна пирамида
    SquarePyramid s(5.2, 10.5);
    if(IsHigher(c, s))
        cout << "Цилиндърът е по-висок от пирамидата.\n";
    else 
        cout << "Цилиндърът не е по-висок от пирамидата.\n";
    return 0;
}
