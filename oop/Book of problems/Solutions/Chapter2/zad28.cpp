#include <iostream.h>
#include <math.h>

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

double Distance(const Point3& p)
{ 
    return sqrt((double)(p.getX() * p.getX() +
                p.getY() * p.getY() +
                p.getZ() * p.getZ()));
}

int main()
{ 
    // заделяне на памет за масив от 10 указателя
    Point3 ** array = new Point3*[10];
    if(!array)
    { 
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }

    int i;
    // създаване на масива от указатели
    for(i = 0; i < 10; i++)
    { 
        int x, y, z;
        cout << "*array[" << i << "](x, y, z)= ";
        cin >> x >> y >> z;
        array[i] = new Point3(x, y, z);
        if(!array[i])
        { 
            cout << "Грешка при заделяне на памет!\n";
            return 1;
        }
    }

    // намиране на минималното и на максималното
    // разстояние на точките, сочени от указателите
    // на масива до координатното начало
    double min = Distance(*array[0]), 
           max = Distance(*array[0]);
    for(i = 1; i < 10; i++)
    { 
        double d = Distance(*array[i]);
        if(d < min) min = d;
        if(d > max) max = d;
    }

    // намиране и извеждане на точките на най-малко
    // разстояние от координатното начало
    cout << "Точки на най-малко разстояние (" << min
        << ") от координатното начало\n";
    for(i = 0; i < 10; i++)
    { 
        if(fabs(Distance(*array[i]) - min) < 1E-14)
            cout << "Point(" << array[i]->getX() << ", "
                 << array[i]->getY() << ", "
                 << array[i]->getZ() << ")\n";
    }

    // намиране и извеждане на точките на най-голямо
    // разстояние от координатното начало
    cout << "Точки на най-голямо разстояние (" << max
        << ") от координатното начало\n";
    for(i = 0; i < 10; i++)
    { 
        if(fabs(Distance(*array[i]) - max) < 1E-14)
            cout << "Point(" << array[i]->getX() << ", "
                 << array[i]->getY() << ", "
                 << array[i]->getZ() << ")\n";
    }

    // освобождаване на заделената в хийпа памет
    for(i = 0; i < 10; i++)
        delete array[i];
    delete [] array;
    return 0;
}
