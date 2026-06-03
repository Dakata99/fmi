#include <iostream>

class Base
{
public:
    int x;
    Base(int a)
    {
        x = a;
    }
    virtual void f() const{}
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
    Der1 d1(2); Der2 d2(4);
    Base* ptr;
    ptr = &d1;ptr->f();
    ptr = &d2;ptr->f();

    /*Output:
    Der1::f() 7
    Der2::f() 9    
    */
   
    return 0;
}