#include <iostream.h>

class A
{
public:
    A(int a = 1)
    { 
        n = a; x = 1.1;
        cout << "A: " << n << ", " << x << endl;
    }

private:
    int n;
    double x;
};

class B
{
public:
    B(double b = 1)
    {
        n = 2; y = b;
        cout << "B: " << n << ", " << y << endl;
    }

private:
    int n;
    double y;
};

class C : public B, public A
{
public:
    C(int x = 1, int y = 2, int z = 3) : A(x), B(y)
    {
        n = z; m = x*y;
        cout << "C: " << n << ", " << m << endl;
    }

private:
    int n, m;
};

int main()
{
    C c1;
    C c2(2, 4, 6);
    return 0;
}
