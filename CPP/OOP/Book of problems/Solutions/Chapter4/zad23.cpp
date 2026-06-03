#include <iostream.h>

class Points
{
public:
    virtual void Print() const = 0;
};

// дефиниране на клас, обектите на който са цели числа
class Point1 : public Points
{
public:
    Point1(int a = 0)
    {
        x = a;
    }

    void Print() const
    {
        cout << x << endl;
    }

private:
    int x;
};

// дефиниране на клас, обектите на който са
// точки от равнината с цели координати
class Point2 : public Points
{
public:
    Point2(int a = 0, int o = 0)
    {
        x = a;
        y = o;
    }

    void Print() const
    {
        cout << "(" << x << ", " << y << ")\n";
    }

private:
    int x, y;
};

// дефиниране на клас, обектите на който са
// точки от пространството с цели координати
class Point3 : public Points
{
public:
    Point3(int a, int o, int b)
    {
        x = a;
        y = o;
        z = b;
    }

    void Print() const
    {
        cout << "(" << x << ", " << y 
            << ", " << z << ")\n";
    }

private:
    int x, y, z;
};

int main()
{
    // декларация на полиморфния едномерен масив с 6 елемента
    Points* a[6];
    // дефиниране на обекти, представящи цели числа
    Point1 p1(1), p2(2);
    // дефиниране на обекти, представящи точки от равнината
    Point2 p3(3,4), p4(5, 6);
    // дефиниране на обекти, представящи точки от пространството
    Point3 p5(7, 8, 9), p6(10, 11, 12);
    // създаване на полиморфния едномерен масив от цели
    // числа и точки от равнината и пространството
    a[0] = &p1; a[1] = &p3; a[2] = &p5;
    a[3] = &p6; a[4] = &p4; a[5] = &p2;
    Points *ptr;
    // извеждане на полиморфния списък
    for(int i = 0; i < 6; i++)
    {
        ptr = a[i];
        ptr->Print();
    }
    return 0; 
}
