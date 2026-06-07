#include <iostream.h>
#include <math.h>

// декларация на структурата Point
struct Point
{
    double x,                          // абсциса на точка
           y;                          // ордината на точка
};

// създаване на точка от равнината
void create_point(Point& t)
{
    cout << "абсциса: "; cin >> t.x;
    cout << "ордината: "; cin >> t.y;
}

// извеждане на точка от равнината
void show_point(const Point& p)
{
    cout << "Point(" << p.x << ", " << p.y << ")";
}

// намиране на дължината на отсечка с дадени краища
double segment(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) +
                (p2.y - p1.y)*(p2.y - p1.y));
}

// декларация на структурата Triangle
struct Triangle
{
    Point A, B, C;        // върхове на триъгълника
};

// създаване на триъгълник
void create_triangle(Triangle& t)
{
    cout << "Въведете три точки в равнината, които "
         << "могат да са върхове на триъгълник!\n";
    create_point(t.A);
    create_point(t.B);
    create_point(t.C);
}

// извеждане на триъгълник
void show_triangle(const Triangle &t)
{
    cout << "triangle("; show_point(t.A);
    cout << ", "; show_point(t.B);
    cout << ", "; show_point(t.C);
    cout << ")\n";
}

// намиране на периметъра на триъгълник
double perimeter(const Triangle &t)
{
    double a = segment(t.B, t.C),
           b = segment(t.A, t.C),
           c = segment(t.A, t.B);
    return a + b + c;
}

// намиране на лицето на триъгълник
double surface(const Triangle &t)
{
    double a = segment(t.B, t.C),
           b = segment(t.A, t.C),
           c = segment(t.A, t.B);
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    // създаване на триъгълник
    Triangle t; 
    create_triangle(t);
    // извеждане на триъгълника
    show_triangle(t);
    // намиране и извеждане на периметъра на триъгълника
    cout << "Периметър: " << perimeter(t) << endl;
    // намиране и извеждане на лицето на триъгълника
    cout << "Лице: " << surface(t) << endl;
    return 0;
}
