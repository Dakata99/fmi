#include <iostream>
#include <cmath>

unsigned int fact(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

class Expr
{
private:
    int n;
    double x;
public:
    Expr(int _n = 0, double _x = 0)
    {
        n = _n;
        x = _x;
    }
    double S1()const;
    double S2()const;
    double S3()const;
};

double Expr::S1() const
{
    double sum = 1;
    for (size_t i = 1; i <= n; i++)
    {
        sum += (pow(x, i))/(fact(i));
    }
    return sum;
}

double Expr::S2() const
{
    double sum = 1;
    for (size_t i = 2, j = 1; i <= 2*n; i*=2, j++)
    {
        sum += (pow(-1, j)*pow(x, i))/(fact(i));
    }
    return sum;
}

double Expr::S3() const
{
    double sum = x;
    for (size_t i = 3, j = 1; i <= 2*n + 1; i+=2, j++)
    {
        sum += (pow(-1, j)*pow(x, i))/(fact(i));
    }
    return sum;
}

int main()
{
    int n;
    double x;
    do
    {
        std::cout << "n = "; std::cin >> n;
        std::cout << "x = "; std::cin >> x;
    } while (!(x >= -1 && x <= 1 && n >= 0));

    Expr e(n, x);
    std::cout << e.S1() << std::endl;
    std::cout << e.S2() << std::endl;
    std::cout << e.S3() << std::endl;

    return 0;
}