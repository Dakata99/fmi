#include <iostream>

class Base
{
public:
    int x;
    Base(int a)
    {
        x = a;
    }
    virtual void f()const
    {
        std::cout << "Base::f()\n" << "Base::x " << x << std::endl;
    }
};

class Der1:public Base
{
public:
    Der1(int a):Base(a){}
    void f()const
    {
        std::cout << "Der1::f() " << x*x+x+1 << std::endl;
    }
};

class Der2:public Base
{
public:
    Der2(int a):Base(a){}
    void f()const
    {
        std::cout << "Der2::f() " << 2*x+1 << std::endl;
    }
};

int main()
{
    Base b(1); Der1 d1 (5); Der2 d2(10);
    Base *ptr = &b;ptr->f();
    ptr = &d1;ptr->f();
    ptr = &d2;ptr->f();

    /*Output:
        Base::f()
        Base::x 1
        Der1::f() 31
        Der2::f() 21
    */

    return 0;
}