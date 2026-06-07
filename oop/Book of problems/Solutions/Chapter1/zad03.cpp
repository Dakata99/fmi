#include <iostream.h>
#include <math.h>

// декларация на структурата triangle
struct triangle
{ 
    double a, b, c;				// страни на триъгълник
};

// създаване на триъгълник
void create_triangle(triangle& t)
{
    bool tri;
    do
    {
        cout << "a, b, c (страни на триъгълник): ";
        cin >> t.a >> t.b >> t.c;
        tri = (t.a > 0) && (t.b > 0) && (t.c > 0) &&
              (t.a + t.b > t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c > t.a);
    } while(!tri);
}

// извеждане на триъгълник
void show_triangle(const triangle &t)
{
    cout << "triangle(" << t.a << ", " << t.b << ", "
         << t.c << ")\n";
}

// намиране на периметъра на триъгълник
double perimeter(const triangle &t)
{
    return t.a + t.b + t.c;
}

// намиране на лицето на триъгълник
double surface(const triangle &t)
{
    double p = perimeter(t)/2;
    return sqrt(p*(p - t.a)*(p - t.b)*(p - t.c));
}

int main()
{
    // създаване на триъгълник
    triangle t; create_triangle(t);
    // извеждане на триъгълника
    show_triangle(t);
    // намиране и извеждане на периметъра на триъгълника
    cout << "Периметър: " << perimeter(t) << endl;
    // намиране и извеждане на лицето на триъгълника
    cout << "Лице: " << surface(t) << endl;
    return 0;
}


/*
///Функцията create_triangle може да бъде дефинирана и по следния начин:

triangle create_triangle()
{ 
    triangle t;
    bool tri;
    do
    { 
        cout << "a, b, c (страни на триъгълник): ";
        cin >> t.a >> t.b >> t.c;
        tri = (t.a > 0) && (t.b > 0) && (t.c > 0) &&
              (t.a + t.b > t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c > t.a);
    } while(!tri);
    return t;
}

//Тогава създаването на триъгълник се осъществява чрез дефиницията
triangle t = create_triangle();
*/
