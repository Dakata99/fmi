#include <iostream>
#include <cmath>

class Circle
{
private:
    double x, y, radius;
public:
    Circle(const double = 0, const double = 0, const double = 1);
    
    Circle operator+(const Circle&);
    Circle operator+=(const Circle&);

    bool isIn(const double, const double)const;
    bool operator==(const Circle&)const;
    bool operator!=(const Circle&)const;
    bool operator<(const Circle&)const;
    bool operator>(const Circle&)const;

    void print()const;

    friend std::ostream& operator<<(std::ostream&, const Circle&);
};

Circle::Circle(const double X, const double Y, const double rad):x(X), y(Y), radius(rad){}

Circle Circle::operator+(const Circle& other)
{
    return Circle(x + other.x, y + other.y, radius + other.radius);
}
Circle Circle::operator+=(const Circle& other)
{
    x += other.x;
    y += other.y;
    radius += other.radius;

    return *this;
}

bool Circle::isIn(const double x, const double y)const
{
    if (sqrt(x*x +y*y) <= radius)
    {
        return true;
    }
    return false;
}
bool Circle::operator==(const Circle& other)const
{
    return x == other.x && y == other.y && radius == other.radius;
}
bool Circle::operator!=(const Circle& other)const
{
    return !(*this == other);
}
bool Circle::operator<(const Circle& other)const
{
    double dist = sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    return dist + radius <= other.radius;
}
bool Circle::operator>(const Circle& other)const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Circle& c)
{
    os << "Center(" << c.x << ", " << c.y << ")\n";
    os << "Radius: " << c.radius << std::endl;
    return os;
}
void Circle::print()const
{
    std::cout << "Center(" << x << ", " << y << ")\n";
    std::cout << "Radius: " << radius << std::endl;
}

int main()
{
    Circle c1(1, 1, 2), c2(2, 2, 4);
    Circle c3 = c1 + c2;
    c2 += c3;
    c1.print();
    c2.print();
    c3.print();


    std::cout << std::boolalpha << c1.isIn(2, 2) << std::endl;
    bool flag = c1 == c2;
    std::cout << std::boolalpha << flag << std::endl;
    flag = c1 != c2;
    std::cout << std::boolalpha << flag << std::endl;

    Circle c4(10, 8, 30), c5(1, 2, 10);
    flag = c4 < c5;
    std::cout << std::boolalpha << flag << std::endl;
    flag = c4 > c5;
    std::cout << std::boolalpha << flag << std::endl;

    return 0;
}
