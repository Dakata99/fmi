#include <iostream>
#include <cstring>

class A
{
private:
    char* st;
    double x;
public:
    A(const char* = "AAA", double = 0.0);
    ~A();
    A(const A&);
    A& operator=(const A&);
    void print()const;
};

A::A(const char* s, double y)
{
    std::cout << "A(" << s << ", " << y << ")\n";
    st = new char[strlen(s) + 1];
    strcpy(st, s);
    x = y;
}
A::~A()
{
    std::cout << "~A()\n";
}
A::A(const A& s)
{
    std::cout << "A(const A& s)\n";
    st = new char[strlen(s.st) + 1];
    strcpy(st, s.st);
    x = s.x;
}
A& A::operator=(const A& s)
{
    std::cout << "A::operator=()\n";
    if (this != &s)
    {
        delete[]st;
        st = new char[strlen(s.st) + 1];
        strcpy(st, s.st);
        x = s.x;
    }
    return *this;
}
void A::print()const
{
    std::cout << st << " " << x << std::endl;
}

class B
{
private:
    double x;
    A a;
public:
    B(double, const A&);
    B(const B&);
    B& operator=(const B&);
    void print()const;
};

B::B(double d, const A& e):a(e)
{
    std::cout << "B::B(d, e)\n";
    x = d;
}
B::B(const B& p):a(p.a)
{
    std::cout << "B::B(const B& p)\n";
    x = p.x;
}
B& B::operator=(const B& p)
{
    std::cout << "B::operator=()\n";
    if (this != &p)
    {
        x = p.x;
        a = p.a;
    }
    return *this;
}
void B::print()const
{
    std::cout << x << std::endl;
    a.print();
}

int main()
{
    A a1("***"), a2;
    B b(5, a1), c(10, a2), d(c);
    b.print();
    c.print();
    d.print();
    d = b;
    d.print();

    /*Output:
        A(***, 0.0)
        A(AAA, 0.0)
        A(const A& s)
        B::B(d, e)
        A(const A& s)
        B::B(d, e)
        A(const A& s)
        B::B(const B& p)
        5
        *** 0.0
        10 
        AAA 0.0
        10
        AAA 0.0
        B::operator=()
        A::operator=()
        5
        *** 0.0
        ~A()
        ~A()
        ~A()
        ~A()
        ~A()
        */

    return 0;
}