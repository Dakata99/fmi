#include <iostream.h>

class Base
{
public:
    int x;

    Base(int a)
    {
        x = a;
    }

    virtual void f() const
    {
        cout << "Base::f()\n"
            << "Base::x " << x << endl;
    }
};

class Der1 : public Base
{
public:
    Der1(int a) : Base(a)
    {}
};

class Der2 : public Base
{
public:
    Der2(int a) : Base(a)
    {}

    void f() const
    {
        cout << "Der2::f() " << 2*x+1 << endl;
    }
};

class Der11 : public Der1
{
public:
    Der11(int a) : Der1(a)
    {}

    void f() const
    {
        cout << "Der11::f() " << 10*x-5 << endl;
    }
};

class Der12 : public Der11
{ 
public:
    Der12(int a) : Der11(a)
    {}
};

int main()
{
    Base b(1);
    Der1 d1(5);
    Der11 d11(10);
    Der12 d12(15);
    Der2 d2(20);
    Base *ptr = &b; ptr->f();
    ptr = &d1; ptr->f();
    ptr = &d11; ptr->f();
    ptr = &d12; ptr->f();
    ptr = &d2; ptr->f();
    return 0;
}
