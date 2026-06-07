#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class A
{
public:
    A(char* = "");
    ~A();
    virtual void print() const;

private:
    char* x;
};

A::A(char* s)
{
    x = new char[strlen(s)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, s);
}

A::~A()
{
    cout << "~A()\n";
    delete x;
}

void A::print() const
{
    cout << "A:: x " << x << endl;
}

class B : virtual public A
{
public:
    B(char* = "", char* = "");
    ~B();
    void print() const;

private:
    char* x;
};

B::B(char* a, char* b): A(a)
{
    x = new char[strlen(b)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, b);
}

B::~B()
{
    cout << "~B()\n";
    delete x;
}

void B::print() const
{
    A::print();
    cout << "B:: x " << x << endl;
}

class C : virtual public B
{
public:
    C(char* = "", char* = "", char* = " ");
    ~C();
    void print() const;

private:
    char* x;
};

C::C(char* a, char* b, char* c): B(a, b)
{
    x = new char[strlen(c)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, c);
}

C::~C()
{
    cout << "~C()\n";
    delete x;
}

void C::print() const
{
    B::print();
    cout << "C:: x " << x << endl;
}

int main()
{
    A *ptr = new B("O", "K");
    ptr->print();
    delete ptr;
    ptr = new C("M", "A", "M");
    ptr->print();
    delete ptr;
    return 0;
}
