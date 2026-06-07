#include <iostream>
#include <cmath>

const double DEG_TO_RAD = 3.14/180;

class Angle
{
private:
    double angle;
public:
    double getSin(double)const;
    double getCos(double)const;
    double getTan(double)const;
};

double Angle::getSin(double x) const
{
    return sin(DEG_TO_RAD * x);
}

double Angle::getCos(double x) const
{
    return cos(DEG_TO_RAD * x);
}

double Angle::getTan(double x) const
{
    return tan(DEG_TO_RAD * x);
}

int main()
{
    Angle alpha;
    std::cout << alpha.getSin(45) << std::endl;
    std::cout << alpha.getCos(45) << std::endl;
    std::cout << alpha.getTan(45) << std::endl;

    return 0;
}