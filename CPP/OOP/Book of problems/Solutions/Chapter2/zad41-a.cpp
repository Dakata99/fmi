#include <iostream.h>

class Point3
{ 
public:
    // конструктор с подразбиращи се параметри
    Point3(int = 0, int = 0, int = 0);
    // конструктор за присвояване
    Point3(const Point3 &);
    // член-функции за достъп до координатите на точка
    int getX() const;
    int getY() const;
    int getZ() const;
    // мутатори на координатите на точка
    void setX(int);
    void setY(int);
    void setZ(int);
    // операторни функции, предефиниращи
    // бинарен и унарен оператор '-'
    Point3 operator-() const;
    Point3 operator-(const Point3&) const;

private:
    int x;                // абсциса
    int y;                // ордината
    int z;                // апликата
};

Point3::Point3(int _x, int _y, int _z) 
{
    x = _x;
    y = _y;
    z = _z;
}

Point3::Point3(const Point3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

int Point3::getX() const
{
    return x;
}

int Point3::getY() const 
{ 
    return y;
}

int Point3::getZ() const
{ 
    return z;
}

void Point3::setX(int _x)
{
    x = _x;
}

void Point3::setY(int _y)
{
    y = _y;
}

void Point3::setZ(int _z)
{ 
    z = _z;
}

// операторна функция, предефинираща унарния оператор "-"
Point3 Point3::operator-() const
{ 
    Point3 temp;
    temp.x = -x;
    temp.y = -y;
    temp.z = -z;
    return temp;
}

// операторна функция, предефинираща бинарния оператор "-"
Point3 Point3::operator-(const Point3& p) const
{ 
    Point3 temp;
    temp.x = x - p.x;
    temp.y = y - p.y;
    temp.z = z - p.z;
    return temp;
}

int main()
{ 
    // дефиниране чрез триаргументния конструктор
    // и извеждане на точка от пространството
    Point3 P(1, 2, -4);
    cout << "P = (" << P.getX() << ", " << P.getY()
         << ", " << P.getZ() << ")\n";

    // дефиниране чрез конструктора за присвояване,
    // промяна чрез прилагане на унарния оператор
    // '-' и извеждане на точка от пространството
    Point3 P1 = P;
    P1 = -P1;
    cout << "P1 = (" << P1.getX() << ", "
         << P1.getY() << ", " << P1.getZ() << ")\n";

    // промяна на точката P чрез прилагане на бинарния
    // оператор '-' и извеждане на точката
    P = P - P1;
    cout << "P = (" << P.getX() << ", " << P.getY()
         << ", " << P.getZ() << ")\n";
    return 0;
}
