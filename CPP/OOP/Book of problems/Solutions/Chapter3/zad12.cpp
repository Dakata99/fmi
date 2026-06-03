#include <iostream.h>
#include <stdlib.h>
#include <math.h>

// дефиниция на клас Point
class Point
{
public:
    Point(double, double);                  // конструктор
    void scale(double);                     // член-функция за мащабиране
    void translate(double, double);         // член-функция за транслация
    double distance(const Point&) const;    // намиране на разстояние между две точки
    void print() const;                     // извеждане на точка

private:
    double x, y;                            // координати на точката
};

// конструктор
Point::Point(double X, double Y)
{
    x = X;
    y = Y;
}

// член-функция за мащабиране
void Point::scale(double k)
{
    x = x * k;
    y = y * k;
}

// член-функция за транслация
void Point::translate(double h, double v)
{
    x = x + h;
    y = y + v;
}

// член-функция за намиране на разстояние между две точки
double Point::distance(const Point& P) const
{
    double xdist = x - P.x;
    double ydist = y - P.y;
    return sqrt(xdist*xdist + ydist*ydist);
}

// член-функция за извеждане на точка
void Point::print() const
{
    cout << "Point(" << x << ", " << y << ")\n";
}

// дефиниция на клас Quadrilateral
class Quadrilateral
{
public:
    Quadrilateral(Point, Point, Point, Point);  // конструктор
    void scale(double);                         // мащабиране
    void translate(double, double);             // транслация
    double perimeter() const;                   // намиране на периметъра на четириъгълник
    double area() const;                        // намиране на лицето на четириъгълник
    void print() const;                         // извеждане на четириъгълник

protected:
    Point p1, p2, p3, p4;                       // върхове на четириъгълник

private:
    // намиране на лице на триъгълник
    double triangleArea(Point, Point, Point) const;
};

// конструктор
Quadrilateral::Quadrilateral(Point pp1, Point pp2,
                             Point pp3, Point pp4)
                             : p1(pp1), p2(pp2), p3(pp3), p4(pp4)
{}

// член-функция за мащабиране
void Quadrilateral::scale(double k)
{
    p1.scale(k);
    p2.scale(k);
    p3.scale(k);
    p4.scale(k);
}

// член-функция за транслация
void Quadrilateral::translate(double h, double v)
{
    p1.translate(h, v);
    p2.translate(h, v);
    p3.translate(h, v);
    p4.translate(h, v);
}

// член-функция за намиране на периметъра на четириъгълник
double Quadrilateral::perimeter() const
{
    return p1.distance(p2) + p2.distance(p3) +
           p3.distance(p4) + p4.distance(p1);
}

// член-функция за намиране на лицето на четириъгълник
double Quadrilateral::area() const
{
    return triangleArea(p1, p2, p3) +
           triangleArea(p1, p3, p4);
}

// член-функция за намиране на лицето на триъгълник
double Quadrilateral::triangleArea(Point pp1, Point pp2, Point pp3) const
{
    double a = pp1.distance(pp2),
           b = pp1.distance(pp3),
           c = pp2.distance(pp3),
           pp = (a+b+c)/2;
    return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
}

// член-функция за извеждане на четириъгълник
void Quadrilateral::print() const
{
    cout << "Четириъгълник с върхове: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

// дефиниция на клас Rectangle
class Rectangle : public Quadrilateral
{
public:
    Rectangle(Point, Point, Point, Point);  // конструктор
    double perimeter() const;               // намиране на периметъра
    double area() const;                    // намиране на лицето
    double diagonal() const;                // намиране на диагонала
    void print() const;                     // извеждане на правоъгълник
    void print_diag() const;                // извеждане на диагонала на правоъгълник
private:
    double diag;
};

// конструктор
Rectangle::Rectangle(Point q1, Point q2, Point q3, Point q4) :
                     Quadrilateral(q1, q2, q3, q4)
{
    if (fabs(p1.distance(p3) - p2.distance(p4)) > 1.0e-14 ||
        fabs(p1.distance(p2) - p3.distance(p4)) > 1.0e-14 ||
								fabs(p1.distance(p4) - p2.distance(p3)) > 1.0e-14)
    {
        cout << "Не е правоъгълник.\n";
        exit(1);
    }
    diag = p1.distance(p3);
}

// член-функция за намиране на периметъра на правоъгълник
double Rectangle::perimeter() const
{
    double a = p1.distance(p2),
           b = p1.distance(p4);
    return 2 * (a + b);
}

// член-функция за намиране на лицето на правоъгълник
double Rectangle::area() const
{
    double a = p1.distance(p2),
           b = p1.distance(p4);
    return a * b;
}

// член-функция за намиране на диагонала на правоъгълник
double Rectangle::diagonal() const
{
    return diag;
}

// член-функция за извеждане на правоъгълник
void Rectangle::print() const
{
    cout << "Правоъгълник с върхове: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

// член-функция за извеждане на диагонала на правоъгълник
void Rectangle::print_diag() const
{
    cout << "Диагонал: " << diag << endl;
}

// дефиниция на клас Square
class Square : public Rectangle
{
public:
    Square(Point, Point, Point, Point); // конструктор
    double perimeter() const;           // намиране на периметъра
    double area() const;                // намиране на лицето
    void print() const;                 // извеждане на квадрат
};

// конструктор
Square::Square(Point q1, Point q2, Point q3, Point q4) :
               Rectangle(q1, q2, q3, q4)
{
    if(fabs(p1.distance(p2) - p2.distance(p3)) > 1.0e-7)
    {
        cout << "Не е квадрат.\n";
        exit(1);
    }
}

// член-функция за намиране на периметъра на квадрат
double Square::perimeter() const
{
    return 4 * p1.distance(p2);
}

// член-функция за намиране на лицето на квадрат
double Square::area() const
{
    double a = p1.distance(p2);
    return a * a;
}

// член-функция за извеждане на квадрат
void Square::print() const
{
    cout << "Квадрат с върхове: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

int main()
{
    // дефиниране на точки
    Point P1(0, 0), P2(3, 1), P3(3, 0),
          P4(0, 1), P5(1, 1), P6(0, 3),
          P7(3, 3);

    // дефиниция на четириъгълник
    Quadrilateral q(P1, P3, P2, P5);
    // извеждане на четириъгълника
    q.print();
    // намиране и извеждане на периметъра
    // и лицето на четириъгълника
    cout << "Периметър: " << q.perimeter() << endl
         << "Лице: " << q.area() << endl;
    // транслиране на четириъгълника
    q.translate(2, 5);
    // извеждане на транслирания четириъгълник
    q.print();
    // намиране и извеждане на периметъра
    // и лицето на транслирания четириъгълник
    cout << "Периметър: " << q.perimeter() << endl
         << "Лице: " << q.area() << endl;
    // мащабиране на транслирания четириъгълник
    q.scale(3);
    // извеждане на мащабирания четириъгълник
    q.print();
    // намиране и извеждане на периметъра
    // и лицето на мащабирания четириъгълник
    cout << "Периметър: " << q.perimeter() << endl
         << "Лице: " << q.area() << endl;
    
    // създаване на правоъгълник
    Rectangle r(P1, P3, P2, P4);
    // извеждане на правоъгълника
    r.print();
    // намиране и извеждане на периметъра
    // и лицето на правоъгълника
    cout << "Периметър: " << r.perimeter() << endl
         << "Лице: " << r.area() << endl;
    // намиране на диагонала на правоъгълника
    r.diagonal();
    // извеждане на диагонала на правоъгълника
    r.print_diag();
    // транслиране на правоъгълника
    r.translate(2, 5);
    // извеждане на транслирания правоъгълник
    r.print();
    // мащабиране на транслирания правоъгълник
    r.scale(3);
    // извеждане на мащабирания правоъгълник
    r.print();

    // създаване на квадрат
    Square s(P1, P3, P7, P6);
    // извеждане на квадрата
    s.print();
    // намиране и извеждане на периметъра
    // и лицето на квадратa
    cout << "Периметър: " << s.perimeter() << endl
         << "Лице: " << s.area() << endl;
    // намиране на диагонала на квадрата
    s.diagonal();
    // извеждане на диагонала на квадрата
    s.print_diag();
    // транслиране на квадрата
    s.translate(2, 5);
    // извеждане на транслирания квадрат
    s.print();
    // мащабиране на транслирания квадрат
    s.scale(3);
    // извеждане на мащабирания квадрат
    s.print();
    return 0;
}
