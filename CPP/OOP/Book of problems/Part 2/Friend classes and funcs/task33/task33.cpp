#include <iostream>

class Fraction
{
private:
    int n, d;
public:
    Fraction():n(0), d(1){}
    Fraction(int x, int y)
    {
        n = x;
        d = (y != 0) ? y : 1;
    }

    //getters
    int getN()const
    {
        return n;
    }
    int getD()const
    {
        return d;
    }

    //setters
    void setN(const int x)
    {
        n = x;
    }
    void setD(const int y)
    {
        d = y;
    }

    //print
    void print()const
    {
        std::cout << n << "/" << d << std::endl;
    }
};

bool isFraction(const Fraction& f)
{
    return f.getN() % f.getD() != 0;
}

void func()
{
    int a, b;
    do
    {
        std::cin >> a >> b;
    } while (b == 0);

    Fraction f(a, b);
    if (isFraction(f))
    {
        std::cout << "Not devided!" << std::endl;
    }
    else
    {
        std::cout << "Devided!" << std::endl;
    }
}

int main()
{
    func();

    return 0;
}