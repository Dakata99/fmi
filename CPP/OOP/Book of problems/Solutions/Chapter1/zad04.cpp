#include <iostream.h>
#include <math.h>

const double PI = 3.14159265;

// декларация на структурата polar
struct polar
{
    double mag;                       // радиус
    double ang;                       // ъгъл
};

// декларация на структурата rect
struct rect
{
    double x;                         // абсциса
    double y;                         // ордината
};

// преобразуване на вектор, зададен чрез
// правоъгълни, в полярни координати
polar rect_to_polar(const rect& r)
{
    polar p;
    p.mag = sqrt(r.x * r.x + r.y * r.y);
    p.ang = atan2(r.y, r.x);
    return p;
}

// преобразуване на вектор, зададен чрез
// полярни в правоъгълни координати
rect polar_to_rect(const polar& p)
{
    const double DEG_TO_RAD = PI/180;
    rect r;
    r.x = p.mag * cos(p.ang*DEG_TO_RAD);
    r.y = p.mag * sin(p.ang*DEG_TO_RAD);
    return r;
}

// извеждане на вектор, зададен чрез
// полярни координати
void show_polar(const polar& p)
{
    const double RAD_TO_DEG = 180/PI;
    cout << "радиус = " << p.mag;
    cout << ", ъгъл = " << p.ang * RAD_TO_DEG;
    cout << " градуса.\n";
}

// извеждане на вектор, зададен чрез
// правоъгълни координати
void show_rect(const rect& r)
{
    cout << "абсциса = " << r.x
         << ", ордината = " << r.y << "\n";
}

int main()
{
    rect r;
    polar p;
    cout << "Изберете режим на въвеждане на координатите: \n";
    cout << "r - за правоъгълни и "
            "p - за полярни координати. \n";
    char ch; cin >> ch;
    switch(ch)
    {
    case 'r':
        cout << "Въведете правоъгълните координати x и y: ";
        while(cin >> r.x >> r.y)
        { 
            p = rect_to_polar(r);
            show_polar(p);
            cout << "Следващи правоъгълни координати, "
                    "за край въведете низа end ";
        }
        break;
    case 'p':
        cout << "Въведете полярните координати mag и ang: ";
        while(cin >> p.mag >> p.ang)
        { 
            r = polar_to_rect(p);
            show_rect(r);
            cout << "Следващи полярни координати, "
                    "за край въведете низа end ";
        }
    }
    return 0;
}
