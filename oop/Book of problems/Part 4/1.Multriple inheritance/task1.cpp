#include <iostream>

class A
{
private:
    int n;
    double x;

public:
    A(int a = 1)
    {
        n = a;
        x = 1.1;
        std::cout << "A: " << n << ", " << x << std::endl;
    }
};

class B
{
private:
    int n;
    double y;
    
public:
    B(double b = 1)
    {
        n = 2;
        y = b;
        std::cout << "B: " << n << ", " << y << std::endl;
    }
};

class C : public B, public A
{
private:
    int n, m;
    
public:
    C(int x = 1, int y = 2, int z = 3) : A(x), B(y)
    {
        n = z;
        m = x * y;
        std::cout << "C: " << n << ", " << m << std::endl;
    }
};

int main()
{
    C c1;
    /*
    B: 2, 2
    A: 1, 1.1
    C: 3, 2
    */

    C c2(2, 4, 6);
    /*
    B: 2, 4
    A: 2, 1.1
    C: 6, 8
    */

    return 0;
}

