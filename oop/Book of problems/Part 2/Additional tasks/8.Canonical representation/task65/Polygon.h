#pragma once

struct Point
{
    double x, y;
};

class Polygon
{
private:
    Point* points;
    size_t count;
public:
    Polygon(const size_t = 3);
    Polygon(const Polygon&);
    ~Polygon();

    Polygon& operator=(const Polygon&);

    void setCount(const size_t);
    
};


