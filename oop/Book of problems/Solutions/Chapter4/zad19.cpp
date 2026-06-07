#include <iostream.h>
#include <math.h>
#include <stdlib.h> 

const double PI = 3.14159265;

class Figure
{ 
public:
    // метод за намиране на лице на фугура
    virtual double area() const = 0;
    // метод за намиране на периметър на фигура
    virtual double perimeter() const = 0;
};

class Circle : public Figure
{
public:
    Circle(double r) : radius(r)
    {}

    double area() const
    { 
        return PI*radius*radius;
    }

    double perimeter() const
    { 
        return 2*PI*radius;
    }

private:
    double radius;
};

class Point
{
public:
    Point() : x(0), y(0)
    {}

    Point(double _x, double _y) : x(_x), y(_y)
    {}

    double distanceTo(const Point& p) const
    { 
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }

    double x, y;
};

class ListOfPoints
{
public:
    // канонично представяне
    ListOfPoints(int);
    ListOfPoints(const ListOfPoints&);
    ListOfPoints& operator=(const ListOfPoints&);
    ~ListOfPoints();
    // оператор за индексиране
    Point& operator[](int);

protected:
    int size;                // брой на точките
    Point *points;            // списък от точки
    void copy(const ListOfPoints&);
};

ListOfPoints::ListOfPoints(int numPoints) : size(numPoints)
{
    points = new Point[size];
}

ListOfPoints::ListOfPoints(const ListOfPoints& list) :  points(NULL)
{ 
    copy(list);
}

ListOfPoints& ListOfPoints::operator=(const ListOfPoints& list)
{ 
    if(this != &list)
        copy(list);
    return *this;
}

ListOfPoints::~ListOfPoints()
{ 
    delete points; 
}

Point& ListOfPoints::operator[](int i)
{
    if(i < 0 || i >= size) exit(1); // проверка за валиден индекс
    return points[i];
}

void ListOfPoints::copy(const ListOfPoints& list)
{ 
    if(points != NULL)
        delete points;
    points = new Point[list.size];
    for(int i = 0; i < list.size; i++)
    { 
        points[i].x = list.points[i].x;
        points[i].y = list.points[i].y;
    }
}

class Polygon : public Figure, public ListOfPoints
{ 
public:
    Polygon(int);
    double area() const;
    double perimeter() const;
};

Polygon::Polygon(int verteces) : ListOfPoints(verteces)
{}

double Polygon::area() const
{ 
    double a = 0;
    for(int i = 0; i < size-1; i ++)
        a += (points[i].x - points[i+1].x) *
        (points[i].y + points[i+1].y);
    if(size > 1)
        a += (points[size-1].x - points[0].x) *
        (points[size-1].y + points[0].y);
    return fabs(a/2);
}

double Polygon::perimeter() const
{ 
    double p = 0;
    for(int i = 0; i < size-1; i++)
        p += points[i].distanceTo(points[i+1]);
    if(size > 1)
        p += points[size-1].distanceTo(points[0]);
    return p;
}

int main()
{ 
    // дефиниране на кръг и квадрат
    Circle c(1);
    Polygon square(4);
    square[0].x = 0;
    square[0].y = 0;
    square[1].x = 1;
    square[1].y = 0;
    square[2].x = 1;
    square[2].y = 1;
    square[3].x = 0;
    square[3].y = 1;
    cout << c.perimeter() << endl 
         << c.area() << endl
         << square.perimeter() << endl
         << square.area() << endl;
    return 0;
}
