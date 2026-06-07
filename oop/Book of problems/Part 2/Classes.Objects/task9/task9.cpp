#include <iostream>
#include <cmath>

class Absolute
{
public:
    int getAbs(int);
    double getAbs(double);
};

int Absolute::getAbs(int x) 
{
    return abs(x);
}
double Absolute::getAbs(double y) 
{
    return fabs(y);
}

int main()
{
    Absolute a;
    std::cout << a.getAbs(-100) << std::endl;
    std::cout << a.getAbs(-5.5) << std::endl;
    return 0;
}