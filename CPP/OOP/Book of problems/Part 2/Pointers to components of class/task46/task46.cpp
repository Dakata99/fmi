#include <iostream>

class Q
{
public:
    void f();
    void g();
    int x;
};

void Q::f()
{
    std::cout << "f()\n" << "x = " << x << std::endl; 
}
void Q::g()
{
    --x;
    std::cout << "g()\n" << "x = " << x << std::endl;
}

void func()
{
    Q obj;
    int Q::*px = &Q::x;
    obj.*px = 25;
    std::cout << obj.*px << std::endl;

    void (Q::*ptr)() = &Q::f;
    (obj.*ptr)();

    ptr = &Q::g;
    (obj.*ptr)();
}

int main()
{
    func();

    return 0;
}