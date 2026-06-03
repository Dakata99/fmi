#include <iostream>

class base
{
private:
    int x;
public:
    base()
    {
        std::cout << "base::base()\n";
        x = 0;
    }
    base(int n)
    {
        std::cout << "base::base(int n)\n";
        x = n;
    }
    void print()const
    {
        std::cout << "base::x" << x << std::endl;
    }
};

class der:public base
{
private:
    base b;
    int x;
public:
    der()
    {
        std::cout << "der::der()\n";
        x = 5;
    }
    der(int n):base(n)
    {
        b = base(-n);
        x = n + 5;
        std::cout << "der::der(" << n << ")\n";
    }
    void print()const
    {
        base::print();
        std::cout << "der::x" << x << std::endl;
        std::cout << "der::b\n";b.print();
    }
};

int main()
{
    der d1;
    d1.print();

    der d2(5);
    d2.print();

    /*
    Output:
        base::base()
        base::base()
        der::der(), x = 5
        base::x0
        der::x5
        der::b
        base::x0

        base::base(int n), x = n
        base::base()
        base::base(int n), x = -n
        der::der(5)
        base::x5
        der::x10
        der::b
        base::x-5
    */

    return 0;
}