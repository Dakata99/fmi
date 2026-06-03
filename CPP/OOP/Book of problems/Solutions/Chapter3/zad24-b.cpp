#include <iostream.h>

// дефиниция на шаблон на клас Point3
template <class T>
class Point3
{
public:
    Point3(T = 0, T = 0, T = 0);
    Point3(const Point3&);
    Point3& operator=(const Point3&);
    T getX() const;
    T getY() const;
    T getZ() const;
    void print() const;
    void setX(T);
    void setY(T);
    void setZ(T);

private:
    T x;
    T y;
    T z;
};

template <class T>
Point3<T>::Point3(T _x, T _y, T _z)
{
    x = _x;
    y = _y;
    z = _z;
}

template <class T>
Point3<T>::Point3(const Point3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

template <class T>
Point3<T>& Point3<T>::operator=(const Point3& p)
{
    if(this != &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    return *this;
}

template <class T>
T Point3<T>::getX() const
{
    return x;
}

template <class T>
T Point3<T>::getY() const
{
    return y;
}

template <class T>
T Point3<T>::getZ() const
{
    return z;
}

template <class T>
void Point3<T>::print() const
{
    cout << "Point(" << x << ", " << y 
         << ", " << z << ")\n";
}

template <class T>
void Point3<T>::setX(T _x)
{
    x = _x;
}

template <class T>
void Point3<T>::setY(T _y)
{
    y = _y;
}

template <class T>
void Point3<T>::setZ(T _z)
{
    z = _z;
}

// дефиниция на шаблон на производен клас ColPoint3
template <class T, class U>
class ColPoint3 : public Point3<T>
{
public:
    ColPoint3(T = 0, T = 0, T = 0, U = 0);
    ColPoint3(const ColPoint3&);
    ColPoint3& operator=(const ColPoint3&);
    U getCol() const;
    void print() const;
    void setCol(U);

private:
    U col;
};

template <class T, class U>
ColPoint3<T, U>::ColPoint3(T x, T y, T z, U c)
                           : Point3<T>(x, y, z)
{
    col = c;
}

template <class T, class U>
ColPoint3<T, U>::ColPoint3(const ColPoint3& p) : Point3<T>(p)
{
    col = p.col;
}

template <class T, class U>
ColPoint3<T, U>& ColPoint3<T,U>::operator=(const ColPoint3& p)
{
    if(this != &p)
    {
        Point3<T>::operator=(p);
        col = p.col;
    }
    return *this;
}

template <class T, class U>
U ColPoint3<T, U>::getCol() const
{
    return col;
}

template <class T, class U>
void ColPoint3<T, U>::print() const
{
    Point3<T>::print();
    cout << "Colour: " << col << endl;
}

template <class T, class U>
void ColPoint3<T, U>::setCol(U c)
{
    col = c;
}

// дефиниция на шаблон на производен клас WeightColPoint3
template <class T, class U, class V>
class WeightColPoint3 : public ColPoint3<T, U>
{
public:
    WeightColPoint3(T = 0, T = 0, T = 0, U = 0, V = 0);
    WeightColPoint3(const WeightColPoint3&);
    WeightColPoint3& operator=(const WeightColPoint3&);
    V getWeight() const;
    void print() const;
    void setWeight(V);

private:
    V weight;
};

template <class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(T x, T y, T z, U c, V w) 
                                          : ColPoint3<T, U>(x, y, z, c)
{
    weight = w;
}

template <class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(const WeightColPoint3& p)
                                          : ColPoint3<T, U>(p)
{
    weight = p.weight;
}

template <class T, class U, class V>
WeightColPoint3<T, U, V>& WeightColPoint3<T, U, V>::operator=(const WeightColPoint3& p)
{
    if(this != &p)
    {
        ColPoint3<T, U>::operator=(p);
        weight = p.weight;
    }
    return *this;
}

template <class T, class U, class V>
V WeightColPoint3<T, U, V>::getWeight() const
{
    return weight;
}

template <class T, class U, class V>
void WeightColPoint3<T, U, V>::print() const
{
    ColPoint3<T, U>::print();
    cout << "Weight: " << weight << endl;
}

template <class T, class U, class V>
void WeightColPoint3<T, U, V>::setWeight(V w)
{
    weight = w;
}

const int MAX_SIZE = 50;
int main()
{ 
    // деклариране на масив от точки с реални координати,
    // цвят и тегло в тримерното пространство
    WeightColPoint3<double, double, double> Points[MAX_SIZE];
    int n, i;
    // въвеждане на броя на точките
    do
    { 
        cout << "n= "; cin >> n;
    } while(n < 1 || n > MAX_SIZE);

    // въвеждане на точките
    cout << "Въведете " << n 
         << " точки с цвят и с различни тегла!\n";
    for(i = 0; i < n; i++)
    {
        double x, y, z, u, v;
        cout << "x, y, z, u, v: ";
        cin >> x >> y >> z >> u >> v;
        Points[i].setX(x);
        Points[i].setY(y);
        Points[i].setZ(z);
        Points[i].setCol(u);
        Points[i].setWeight(v);
    }

    // въвеждане на радиуса на кълбото
    double R;
    cout << "R: "; cin >> R;
    // намиране на точките (в масива NewPoints)
    // с цвят от диапазона [1, 10], лежащи в
    // кълбото с център координатното начало и
    // радиус R, както и на техния брой m
    int m = -1; // индексирана променлива на масива NewPoints
    WeightColPoint3<double, double, double> NewPoints[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        double x = Points[i].getX(),
               y = Points[i].getY(),
               z = Points[i].getZ(),
               u = Points[i].getCol();
        if(u >= 1 && u <= 10 && x*x + y*y + z*z <= R*R)
        {
            m++;
            NewPoints[m] = Points[i];
        }
    }
    if(m >= 0)
    {
        m++;        // брой на елементите на масива NewPoints
        // сортиране в низходящ ред по тегло на точките
        // с цвят от диапазона [1, 10], лежащи в кълбото
        // с център координатното начало и радиус R
        for(i = 0; i < m-1; i++)
        {
            WeightColPoint3<double, double, double> TempPoint;
            double MaxWeight = NewPoints[i].getWeight();
            int k = i;
            for(int j = i+1; j < m; j++)
            {
                if(NewPoints[j].getWeight() > MaxWeight)
                {
                    MaxWeight = NewPoints[j].getWeight();
                    k = j;
                }
            }
            TempPoint = NewPoints[i];
            NewPoints[i] = NewPoints[k];
            NewPoints[k] = TempPoint;
        }

        // извеждане на сортираните точки
        for(i = 0; i < m; i++)
        {
            NewPoints[i].print();
            cout << endl;
        }
    }
    else
    {
        cout << "Не съществува точка с търсеното свойство.\n";
    }
    return 0;
}
