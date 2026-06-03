#include <iostream>
#include <cmath>

class Vector
{
private:
    double x, y;
    double angle, radius;
    char regime;
public:
    //Constructors
    Vector():x(0.0), y(0.0), regime('r'){}
    Vector(const double _x, const double _y, const char _regime = 'r')
    {
        regime = _regime;
        if (regime == 'r')
        {
            x = _x;
            y = _y;
        }
        else if(regime == 'p')
        {
            angle = _x;
            radius = _y;
        }
        else
            std::cout << "Invalid coordinates!" << std::endl;
    }
    

    //getters
    double getX()const
    {
        return x;
    }
    double getY()const
    {
        return y;
    }
    double getAngle()const
    {
        return angle;
    }
    double getRadius()const
    {
        return radius;
    }
    char getRegime()const
    {
        return regime;
    }

    //setters
    void setX(const double _x)
    {
        x = _x;
    }
    void setY(const double _y)
    {
        y = _y;
    }
    void setAngle(const double _angle)
    {
        angle = _angle;
    }
    void setRadius(const double _radius)
    {
        radius = _radius;
    }
    void setRegime(const double _regime)
    {
        regime = _regime;
    }

    //operators
    Vector operator+(const Vector& v)
    {
        return Vector(x + v.getX(), y + v.getY(), 'r');
    }
    Vector operator-(const Vector& v)
    {
        return Vector(x - v.getX(), y - v.getY(), 'r');
    }
    Vector operator*(double t)
    {
        return Vector(x*t, y*t, 'r');
    }
    friend Vector operator*(double t, const Vector& v)
    {
        return Vector(t*v.getX(), t*v.getY());
    }

    //funcs
    void toPolar()
    {
        radius = sqrt(x*x + y*y);
        angle = y/radius;
        regime = 'p';
    }
    void toRect()
    {
        x = radius*cos(angle); 
        y = radius*sin(angle);
        regime = 'r';
    }
    void print()const
    {
        if(regime == 'r')
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        else if(regime == 'p')
            std::cout << "Angle = " << angle << ", radius = " << radius << std::endl;
    }

};

void func()
{
    size_t n;
    std::cout << "Enter a number between 1 and 20: "; std::cin >> n;

    //initialize vectors
    Vector* vecs = new Vector[n];
    for (size_t i = 0; i < n; i++)
        vecs[i] = Vector(i, i + 1, 'r');

    //printing vectors
    for (size_t i = 0; i < n; i++)
        vecs[i].print();

    //sum of vectors
    double x = 0, y = 0;
    for (size_t i = 0; i < n; i++)
    {
        x += vecs[i].getX(); 
        y += vecs[i].getY();
    }

    Vector res(x, y, 'r');
    std::cout << "Sum of all vectors is ";res.print();

    Vector res2 = 2*res;
    res2.print();

    Vector res3 = res2*3;
    res3.print();

    //substract of vectors
    x = 0, y = 0;
    for (size_t i = 0; i < n; i++)
    {
        x -= vecs[i].getX();
        y -= vecs[i].getY();
    }

    Vector res4(x, y, 'r');
    std::cout << "Substraction of all vectors is ";res4.print();
    

    //print polar vecs
    for (size_t i = 0; i < n; i++)
    {
        vecs[i].toPolar();
        vecs[i].print();
    }
}

int main()
{
    func();

    return 0;
}