#include <iostream>
#include <cmath>

class Point2d
{
private:
    double x, y;
public:
    //Constructors
    Point2d():x(0), y(0){}
    Point2d(const double _x, const double _y):x(_x), y(_y){}
    Point2d(const Point2d& other):x(other.x), y(other.y){}

    //Getters
    double getX()const
    {
        return x;
    }
    double getY()const
    {
        return y;
    }

    //Setters
    void setX(const double _x)
    {
        x = _x;
    }
    void setY(const double _y)
    {
        y = _y;
    }
    void set(const double _x, const double _y)
    {
        x = _x;
        y = _y;
    }
    
    //funcs
    double distance(const Point2d other)const 
    {
        double xdist = x - other.x;
        double ydist = y - other.y;

        return sqrt(xdist*xdist + ydist*ydist);
    }
    void translate(const double _x, const double _y)
    {
        x += _x;
        y += _y;
    }
    void scale(const double k)
    {
        x *= k;
        y *= k;
    }
    void print()const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

class Quadrilater
{
private:   
    double triangleArea(const Point2d& pp1, const Point2d& pp2, const Point2d& pp3)const
    {
        double a = pp1.distance(pp2), 
               b = pp1.distance(pp3), 
               c = pp2.distance(pp3),
               pp = (a + b + c)/2;

        return sqrt(pp*(pp - a)*(pp - b)*(pp - c));
    }
protected:
    Point2d p1, p2, p3, p4;
public:
//Constructors
    Quadrilater();
    Quadrilater(const Point2d& _p1, const Point2d& _p2, const Point2d& _p3, const Point2d& _p4)
        :p1(_p1), p2(_p2), p3(_p3), p4(_p4){}

//Getters
    Point2d getP1()const
    {
        return p1;
    }
    Point2d getP2()const
    {
        return p2;
    }
    Point2d getP3()const
    {
        return p3;
    }
    Point2d getP4()const
    {
        return p4;
    }

//Setters
    void setPoints(const Point2d& _p1, const Point2d& _p2, const Point2d& _p3, const Point2d& _p4)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        p4 = _p4;
    }

//Funcs
    double perimeter()const
    {
        double l1 = p1.distance(p2);
        double l2 = p2.distance(p3);
        double l3 = p3.distance(p4);
        double l4 = p4.distance(p1);

        return l1 + l2 + l3 + l4;
    }
    double area()const
    {
        return triangleArea(p1, p2, p3) + triangleArea(p1, p3, p4);
    }
    void translate(const double _x, const double _y)
    {
        std::cout << "Translating...\n";
        p1.translate(_x, _y);
        p2.translate(_x, _y);
        p3.translate(_x, _y);
        p4.translate(_x, _y);
    }
    void scale(const double k)
    {
        std::cout << "Scaling...\n";
        p1.scale(k);
        p2.scale(k);
        p3.scale(k);
        p4.scale(k);
    }
    void print()const
    {
        std::cout << "Quadrilater points-----\n";
        p1.print();p2.print();p3.print();p4.print();
        std::cout << "-----------------------\n";
    }
};

class Rectangle:public Quadrilater
{
private:
    double diag;
public:
    Rectangle(const Point2d& q1, const Point2d& q2, const Point2d& q3, const Point2d& q4):Quadrilater(q1, q2, q3, q4)
    {
        if (q1.distance(q3) != q2.distance(q4))
        {
            std::cout << "Not a rectangle!\n";
            exit(-1);
        }
        diag = p1.distance(p3);
    }

    double perimeter()const
    {
        return 2*(p1.distance(p2) + p1.distance(p4));
    }
    double area()const
    {
        return p1.distance(p2)*p1.distance(p4);
    }
    double diagonal()const
    {
        return diag;
    }
    void print()const
    {
        std::cout << "Rectangle points-----------\n";
        p1.print();p2.print();p3.print();p4.print();
        std::cout << "------------------------\n";
    }
    void print_diag()const
    {
        std::cout << "Diagonal is " << diag << std::endl;
    }
};

class Square:public Rectangle
{
public:
    Square(const Point2d& r1, const Point2d& r2, const Point2d& r3, const Point2d& r4):Rectangle(r1, r2, r3, r4)
    {
        if (r1.distance(r2) != r2.distance(r3))
        {
            std::cout << "Not a square!" << std::endl;
            exit(-1);
        }
    }

    double perimeter()const
    {
        return 4*p1.distance(p2);
    }
    double area()const
    {
        return p1.distance(p2)*p1.distance(p2);
    }
    void print()const
    {
        std::cout << "Square points-----------\n";
        p1.print();p2.print();p3.print();p4.print();
        std::cout << "------------------------\n";
    }
};

void func()
{
    Point2d p1(0, 0), p2(3, 1), p3(3, 0), p4(0, 1), p5(1, 1), p6(0, 3), p7(3, 3);

    Quadrilater q(p1, p3, p2, p5);
    q.print();

    std::cout << "Perimeter of quadrilater: " << q.perimeter() << std::endl;
    std::cout << "Area of quadrilater: " << q.area() << std::endl;

    q.translate(2, 5);
    q.print();
    std::cout << "Perimeter of quadrilater: " << q.perimeter() << std::endl;
    std::cout << "Area of quadrilater: " << q.area() << std::endl;

    q.scale(3);
    q.print();
    std::cout << "Perimeter of quadrilater: " << q.perimeter() << std::endl;
    std::cout << "Area of quadrilater: " << q.area() << std::endl;

    Rectangle r(p1, p3, p2, p4);
    r.print();
    std::cout << "Perimeter: " << r.perimeter() << std::endl;
    std::cout << "Area: " << r.area() << std::endl;

    r.diagonal();r.print_diag();
    r.translate(2, 5);
    r.print();

    r.scale(3);
    r.print();

    Square s(p1, p3, p7, p6);
    s.print();
    std::cout << "Perimeter: " << s.perimeter() << std::endl;
    std::cout << "Area: " << s.area() << std::endl;

    s.diagonal();s.print_diag();
    s.translate(2, 5);
    s.print();

    s.scale(3);
    s.print();
}

int main()
{
    func();

    return 0;
}

