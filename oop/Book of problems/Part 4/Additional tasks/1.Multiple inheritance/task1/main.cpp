#include <iostream>

class A
{
private:
    int n;
    double x;
public:
    A(int a = 1, double b = 2.5)
    {
        n = a;
        x = b;
        std::cout << "A: " << n << ", " << x << std::endl;
    }
};

class B
{
private:
    int n;
    double x;
public:
    B(int a = 4, double b = 1.5)
    {
        n = a;
        x = b;
        std::cout << "B: " << n << ", " << x << std::endl;
    }
};

class C:public A, public B
{
private:
    int n, m;
public:
    C(int x = 1, int y = 2, int z = 3):A(x), B(y, 6.5)
    {
        n = z;
        m = x + y;
        std::cout << "C: " << n << ", " << m << std::endl;
    }
};

int main()
{
    C c1(0);
    C c2(1, 3);
    C c3(0, 1, 2);

    /*Output:
        A: 0, 2.5
        B: 2, 6.5
        C: 3, 2
        A: 1, 2.5
        B: 3, 6.5
        C: 3, 4
        A: 0, 2.5
        B: 1, 6.5
        C: 2, 1
        
    */

    return 0;
}