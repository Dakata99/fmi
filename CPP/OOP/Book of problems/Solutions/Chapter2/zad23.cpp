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

void Input(int n, Point3 a[])
{
    for(int i = 0; i < n; i++)
    {
        int p;
        cout << "x= "; cin >> p;
        a[i].setX(p);
        cout << "y= "; cin >> p;
        a[i].setY(p);
        cout << "z= "; cin >> p;
        a[i].setZ(p);
    }
}

void Output(int n, Point3 a[])
{
    for(int i = 0; i < n; i++)
    {
        cout << "Point3("
             << a[i].getX() << ", "
             << a[i].getY() << ", "
             << a[i].getZ() << ")\n";
    }
}

bool lexic(Point3 P1, Point3 P2)
{ 
    return  P1.getX() <  P2.getX() ||
            P1.getX() == P2.getX() && P1.getY() <  P2.getY() ||
            P1.getX() == P2.getX() && P1.getY() == P2.getY() &&
            P1.getZ() <  P2.getZ();
}

void Sort_Points(int n, Point3 P[])
{ 
    for(int i = 0; i < n-1; i++)
    { 
        int k = i;
        Point3 Min = P[i];
        for(int j = i+1; j < n; j++)
        {
            if(lexic(P[j], Min))
            {
                Min = P[j];
                k = j;
            }
        }
        P[k] = P[i]; P[i] = Min;
    }
}


int main()
{
    const int n = 5;
    Point3 arr[n];
    Input(n, arr);
    Sort_Points(n, arr);
    Output(n, arr);
    return 0;
}
