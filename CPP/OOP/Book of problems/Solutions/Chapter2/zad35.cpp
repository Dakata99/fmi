#include <iostream.h>

class SquarePyramid;              // предварителна декларация

// дефиниция на класа Cylinder
class Cylinder
{ 
private:
    double radius;                // радиус на основата
    double height;                // височина

public:
    Cylinder(double, double);     // конструктор
    double getRadius() const;     // достъп до радиуса
    double getHeight() const;     // достъп до височината
    bool IsHigher(const SquarePyramid &) const;
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
    double side;                   // основа
    double height;                 // височина

public:
    SquarePyramid(double, double); // конструктор
    double getSide() const;        // достъп до основата
    double getHeight() const;      // достъп до височината
    // декларация на функцията-приятел IsHigher
    friend bool Cylinder::IsHigher(const SquarePyramid &)
        const;
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

// дефиниция на член-функцията на класа Cylinder,
// която е функция-приятел за класа SquarePyramid и
// определяща дали неявният цилиндър е по-висок от
// зададената като параметър квадратна пирамида
bool Cylinder::IsHigher(const SquarePyramid & s) const
{ 
    return height > s.height;
}

int main()
{ 
    // дефиниция на цилиндър
    Cylinder c(12.5, 8.0);
    // дефиниция на квадратна пирамида
    SquarePyramid s(5.2, 10.5);
    // проверка дали цилиндърът е по-висок от
    // квадратната пирамида
    if(c.IsHigher(s))
        cout << "Цилиндърът е по-висок от пирамидата.\n";
    else 
        cout << "Цилиндърът не е по-висок от пирамидата.\n";
    return 0;
}
