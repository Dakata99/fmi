#include <iostream.h>
#include <math.h>

const double DEG_TO_RAD = 3.14159265/180;

class angle
{
public:
    void setValue(double);    // инициализиране на degrees
    double getSin() const;    // намиране на sin
    double getCos() const;    // намиране на cos
    double getTan() const;    // намиране на tan

private:
    double degrees;
};

void angle::setValue(double a)
{
    degrees = a;
}

double angle::getSin() const
{
    return sin(DEG_TO_RAD * degrees);
}

double angle::getCos() const
{
    return cos(DEG_TO_RAD * degrees);
}

double angle::getTan() const
{
    return tan(DEG_TO_RAD * degrees);
}

int main()
{
    // за ъгъл от 45 градуса се
    // намират sin, cos и tan
    angle deg;
    deg.setValue(45);
    cout << "sin(45) = " << deg.getSin() << endl
         << "cos(45) = " << deg.getCos() << endl
         << "tan(45) = " << deg.getTan() << endl;
    return 0;
}
