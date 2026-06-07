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

int main()
{ 
    // създаване на точките P и P1 чрез
    // конструктора с подразбиращи се параметри
    Point3 P, P1(1, 1, 1);
    // извеждане на точките P и P1
    cout << "P = (" << P.getX() << "," << P.getY()
         << "," << P.getZ() << ")" << endl;
    cout << "P1 = (" << P1.getX() << "," << P1.getY()
         << "," << P1.getZ() << ")" << endl;

    // създаване на точката P2 чрез
    // конструктора за присвояване
    Point3 P2 = P1;
    // извеждане на точката P2
    cout << "P2 = (" << P2.getX() << "," << P2.getY() << ","
         << P2.getZ() << ")" << endl;

    // промяна на координатите на точката P2
    P2.setX(5); P2.setY(10); P2.setZ(15);
    // извеждане на точката P2
    cout << "P2 = (" << P2.getX() << "," << P2.getY() << ","
         << P2.getZ() << ")" << endl;
    return 0;
}
