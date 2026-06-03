#include <iostream.h>
#include <math.h>

class Absolute
{ 
public:
    int ab(int);
    double ab(double);
};

int Absolute::ab(int x)
{
    return abs(x);
}

double Absolute::ab(double x)
{
    return fabs(x);
}

int main()
{ 
    Absolute num;
    cout << "јбсолютната стойност на Ц567 е: " << num.ab(-567)
         << endl << "јбсолютната стойност на Ц5.167 е: "
         << num.ab(-5.167) << endl;
    return 0;
}
