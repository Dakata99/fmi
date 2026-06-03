#include <iostream.h>
#include <math.h>

class Point
{
public:
    Point(double, double);
    double xcoord() const;
    double ycoord() const;

private:
    double x,            // абсциса
           y;            // ордината
};

Point::Point(double a, double b)
{
    x = a;
    y = b;
}

double Point::xcoord() const
{
    return x;
}

double Point::ycoord() const
{
    return y;
}

class Line
{
public:
    // конструктор на линия, минаваща
    // през зададени две точки
    Line(const Point&, const Point&);
    // функция за достъп до едната точка
    Point point1() const;
    // функция за достъп до другата точка
    Point point2() const;
    // разстояние между двете точки, през
    // които минава правата линия
    double len() const;
    // намира ъгловия коефициент на линия
    double slope() const;
    // намира пресечната точка на две линии
    Point intersection(const Line&) const;

private:
    Point p1, p2;        // точки, определящи линия
};

Line::Line(const Point& pt1, const Point& pt2)
           : p1(pt1), p2(pt2)
{}

Point Line::point1() const
{
    return p1;
}

Point Line::point2() const
{
    return p2;
}

double Line::len() const
{
    double xdist = p2.xcoord() - p1.xcoord();
    double ydist = p2.ycoord() - p1.ycoord();
    return sqrt(xdist * xdist + ydist * ydist);
}

double Line::slope() const
{
    double xdist = p2.xcoord() - p1.xcoord();
    double ydist = p2.ycoord() - p1.ycoord();
    if(fabs(xdist) < 1E-14)
    {
        cout << "Ъгловият коефициент е неопределен!\n"; 
        return 0;
    }
    else return ydist / xdist;
}

Point Line::intersection(const Line& lin) const
{
    // преобразуване на първата линия във вида
    // a1*x + b1*y + c1 = 0
    double a1 = p1.ycoord() - p2.ycoord();
    double b1 = p2.xcoord() - p1.xcoord();
    double c1 = p1.xcoord() * p2.ycoord() -
                p2.xcoord() * p1.ycoord();
    // преобразуване на втората линия във вида
    // a2*x + b2*y + c2 = 0
    double a2 = lin.p1.ycoord() - lin.p2.ycoord();
    double b2 = lin.p2.xcoord() - lin.p1.xcoord();
    double c2 = lin.p1.xcoord() * lin.p2.ycoord() -
                lin.p2.xcoord() * lin.p1.ycoord();
    if(fabs(a1*b2 - a2*b1) < 1E-14)
    {
        if(fabs(b1*c2 - b2*c1) < 1E-14)
        {
            cout << "Линиите съвпадат!\n";
            return p1;
        }
        else
        {
            cout << " Линиите са успоредни!\n";
            return p1;
        }
    }
    else
    {
        double x1 = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
        double y1 = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
        return Point(x1, y1);
    }
}

int main()
{
    // създаване на точките – върхове на правоъгълника
    Point P1(0, 0);
    Point P2(8, 0);
    Point P3(8, 4);
    Point P4(0, 4);
    // създаване на диагоналите на правоъгълника
    Line line1(P1, P3);
    Line line2(P2, P4);

    // намиране и извеждане на дължината
    // на диагонала на правоъгълника
    cout << "дължина на диагонала на правоъгълника: "
         << line1.len() << endl;

    // намиране и извеждане на ъгловите коефициенти
    // на диагоналите на правоъгълника
    cout << "ъглови коефициенти: "
         << line1.slope() << " "
         << line2.slope() << endl;

    // намиране и извеждане на координатите на пресечната
    // точка на диагоналите на правоъгълника
    Point intersect = line1.intersection(line2);
    cout << "координати на пресечната точка на диагоналите: "
         << intersect.xcoord() << ", "
         << intersect.ycoord() << endl;
    return 0;
}
