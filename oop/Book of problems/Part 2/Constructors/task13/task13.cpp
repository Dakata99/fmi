#include <iostream>
#include <algorithm>

class GCD
{
private:
    unsigned int a, b;
public:
    GCD(unsigned int x, unsigned int y)
    {
        a = x;
        b = y;
    }
    unsigned int getGCD() const
    {
        return std::__gcd(a, b);
    }
    unsigned int myGetGCD()
    {
        if (a == 0)
        {
            return b;
        }
        while (b != 0)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }
    unsigned int myGetGCD2(unsigned int x, unsigned int y)
    {
        if (y == 0)
        {
            return x;
        }
        return myGetGCD2(y, x % y);
    }
};

int main()
{
    unsigned int x, y;
    std::cin >> x >> y;

    GCD g(x, y);
    std::cout << g.getGCD() << std::endl;
    std::cout << g.myGetGCD() << std::endl;
    std::cout << g.myGetGCD2(42, 56) << std::endl;

    return 0;
}