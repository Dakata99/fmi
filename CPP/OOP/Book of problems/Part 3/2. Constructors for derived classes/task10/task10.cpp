#include <iostream>

class base
{
protected:
    int b;
public:
    base(int x)
    {
        std::cout << "base(int)\n";
        b = x;
    }
    base(const base& x)
    {
        std::cout << "base(const base&)\n";
        b = x.b + 1;
    }
};

class der:public base
{
private:
    int d;
public:
    der(int x = 1):base(x)
    {
        std::cout << "der(int)\n";
        d = x;
    }
    der(const der& x):base(x)
    {
        std::cout << "der(const der&)\n";
        d = x.d +2;
    }
    void print()const
    {
        std::cout << "der: " << d << std::endl;
        std::cout << "base: " << b << std::endl;
    }
};

int main()
{
    der d1(5);
    der d2 = d1;
    std::cout << "d1: ";d1.print();
    std::cout << "d2: ";d2.print();

    /*
    Output:
        base(int)    --b = 5
        der(int)     --d = 5
        base(const base&)    --b = 5 + 1 = 6
        der(const der&)      --d = 5 + 2 = 7
        der:5
        base:5
        der:7
        base:6
    */

    return 0;
}