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

class Der11:public Der1
{
public:
    Der11(int a):Der1(a){}
    void f()const
    {
        std::cout << "Der11::f() "  << 10*x-5 << std::endl;
    }
};

class Der12:public Der11
{
public:
    Der12(int a):Der11(a){}
};

int main()
{
    Base b(1);
    Der1 d1(5);
    Der11 d11(10);
    Der12 d12(15);
    Der2 d2(20);

    Base* ptr = &b;ptr->f();
    ptr = &d1;ptr->f();
    ptr = &d11;ptr->f();
    ptr = &d12;ptr->f();
    ptr = &d2;ptr->f();

    /*Output:
        Base::f()
        Base::x 1
        Base::f()
        Base::x 5
        Der11:f() 95
        Der11:f() 145
        Der2::f() 41        
        */

    return 0;
}