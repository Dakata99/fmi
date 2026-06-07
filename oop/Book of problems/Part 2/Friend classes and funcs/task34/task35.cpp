#include <iostream>

class SquarePyramid;

class Cylinder
{
private:
    double radius, height;
public:
    Cylinder(const double _radius, const double _height):radius(_radius), height(_height){}

    //getters
    double getRadius()const
    {
        return radius;
    }
    double getHeight()const
    {
        return height;
    }

    //setters
    void setRadius(const double _radius)
    {
        radius = _radius;
    }
    void setHeight(const double _height)
    {
        height = _height;
    }

    friend bool isHigher(const Cylinder& c, const SquarePyramid& sp);
};

class SquarePyramid
{
private:
    double height, length;
public:
    SquarePyramid(const double _height, const double _length):height(_height), length(_length){}

    //getters
    double getHeight()const
    {
        return height;
    }
    double getLength()const
    {
        return length;
    }

    //setters
    void setLenght(const double _length)
    {
        length = _length;
    }
    void setHeight(const double _height)
    {
        height = _height;
    }

    friend bool isHigher(const Cylinder& c, const SquarePyramid& sp);
};

bool isHigher(const Cylinder& c, const SquarePyramid& sp)
{
    return c.getHeight() > sp.getHeight();    
}



void func()
{
    Cylinder c(5, 4);
    SquarePyramid sp(6, 7);

    if (isHigher(c, sp))
        std::cout << "Cylinder is higher!" << std::endl;
    else
        std::cout << "Square pyramid is higher!" << std::endl;
}

int main()
{
    func();

    return 0;
}