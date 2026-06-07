#include <iostream>

class A
{
private:
    int a;
public:
    A(int x = 5)
    {
        a = x;
    }
    A& operator=(const A& x)
    {
        if (this != &x)
        {
            a = x.a + 1;
        }
        return *this;
    }
    void print()const
    {
        std::cout << "A: " << a << std::endl;
    }
};

class B:public A
{
private:
    int y;
public:
    B(int x = 1)
    {
        y = x;
    }
    B& operator=(const B& x)
    {
        if (this != &x)
        {
            y = x.y + 2;
            A::operator=(x);
        }
        return *this;
    }
    void print()const
    {
        std::cout << "B: " << y << std::endl;
        A::print();
    }
};

class C:public A
{
private:
    int y;
public:
    C(int x = 2):A(x + 3)
    {
        y = x;
    }
    C(const C& p)
    {
        y = p.y + 2;
    }
    C& operator=(const C& x)
    {
        if (this != &x)
        {
            y = x.y + 3;
            A::operator=(x);
        }
        return *this;
    }
    void print()const
    {
        std::cout << "C: " << y << std::endl;
        A::print();
    }
};

class D:public C
{
private:
    int y;
public:
    D(int x = 3)
    {
        y = x;
    }
    D(const D& p):C(p)
    {
        y = p.y + 3;
    }
    void print()const
    {
        std::cout << "D: " << y << std::endl;
        C::print();
    }
};

int main()
{
    B x(10), y = x;
    C z(20), u;
    D v(30), t = v;

    std::cout << "x = "; x.print();//B:10
                                   //A:5
    std::cout << "y = "; y.print();//B:10
                                   //A:5
    std::cout << "z = "; z.print();//C:20
                                   //A:23
    std::cout << "u = "; u.print();//C:2
                                   //A:5
    std::cout << "v = "; v.print();//D:30
                                   //C:2
                                   //A:5
    std::cout << "t = "; t.print();//D:33
                                   //C:4
                                   //A:5

    y = x;std::cout << "y = "; y.print();
    u = z;std::cout << "z = "; z.print();
    t = v;std::cout << "t = "; t.print();

    return 0;
}