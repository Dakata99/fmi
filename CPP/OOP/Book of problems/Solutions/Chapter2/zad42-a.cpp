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

    Point3& operator++();
    Point3 operator++(int notused);
    Point3& operator--();
    Point3 operator--(int notused);

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

// предефиниране на префиксен оператор ++
Point3& Point3::operator++()
{ 
    ++x;
    ++y;
    ++z;
    return *this;
}

// предефиниране на постфиксен оператор ++
Point3 Point3::operator++(int notused)
{ 
    Point3 temp(x, y, z);
    x++;
    y++;
    z++;
    return temp;
}

// предефиниране на префиксен оператор --
Point3& Point3::operator--()
{ 
    --x;
    --y;
    --z;
    return *this;
}

// предефиниране на постфиксен оператор --
Point3 Point3::operator--(int notused)
{ 
    Point3 temp(x, y, z);
    x--;
    y--;
    z--;
    return temp;
}

int main()
{
    Point3 p(1, 2, 3);
    ++p;
    cout << '(' << p.getX() << ", " 
         << p.getY() << ", " << p.getZ() 
         << ")" << endl;

    Point3 q = p--;
    cout << '(' << p.getX() << ", " 
         << p.getY() << ", " << p.getZ() 
         << ")" << endl;
    cout << '(' << q.getX() << ", " 
         << q.getY() << ", " << q.getZ() 
         << ")" << endl;
    return 0;
}
