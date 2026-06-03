#pragma once

class Point2
{
private:
    double x, y;
public:
    Point2(const double = 0.0, const double  = 0.0);
    
    Point2& operator=(const Point2&);
    bool operator==(const Point2&)const;

    void setX(const double);
    void setY(const double);

    double getX()const;
    double getY()const;

    void print()const;
};
