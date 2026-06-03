#include <iostream>
#include <cstring>

class A
{
private:
    char* x;
public:
    A(const char* s = "")
    {
        x = new char[strlen(s) + 1];
        strcpy(x, s);
    }
    ~A()
    {
        std::cout << "~A()\n";
        delete[]x;
    }
    A(const A& other)
    {
        x = new char[strlen(other.x) + 1];
        strcpy(x, other.x);
    }
    A& operator=(const A& other)
    {
        if (this != &other)
        {
            delete[]x;
            x = new char[strlen(other.x) + 1];
            strcpy(x, other.x);
        }
        return *this;
    }

    void print()const
    {
        std::cout << "A::x " << x << std::endl; 
    }
};

class B:virtual public A
{
private:
    char* x;
public:
    B(const char* a = "", const char* b = "")
    {
        x = new char[strlen(b) + 1];
        strcpy(x, b);
    }
    ~B()
    {
        std::cout << "~B()\n";
        delete[]x;
    }
    B(const B& other):A(other)
    {
        x = new char[strlen(other.x) + 1];
        strcpy(x, other.x);
    }
    B& operator=(const B& other)
    {
        if (this != &other)
        {
            A::operator=(other);
            delete[]x;
            x = new char[strlen(other.x) + 1];
            strcpy(x, other.x);
        }
        return *this;
    }
    void print()const
    {
        A::print();
        std::cout << "B::x " << x << std::endl;
    }
};

class C:virtual public A
{
private:
    char* x;
public:
    C(const char* a = "", const char* b = ""):A(a)
    {
        x = new char[strlen(b) + 1];
        strcpy(x, b);
    }
    ~C()
    {
        std::cout << "~C()\n";
        delete[]x;
    }
    C(const B& other):A(other)
    {
        x = new char[strlen(other.x) + 1];
        strcpy(x, other.x);
    }
    C& operator=(const C& other)
    {
        if (this != &other)
        {
            A::operator=(other);
            delete[]x;
            x = new char[strlen(other.x) + 1];
            strcpy(x, other.x);
        }
        return *this;
    }
    void print()const
    {
        A::print();
        std::cout << "C::x " << x << std::endl;
    }
};

class E:public A
{
private:
    char* x;
public: 
    E(const char* a = "", const char* b = ""):A(a)
    {
        x = new char[strlen(b) + 1];
        strcpy(x, b);
    }
    ~E()
    {
        std::cout << "~E()\n";
        delete[]x;
    }
    E(const E& other):A(other)
    {
        x = new char[strlen(other.x) + 1];
        strcpy(x, other.x);
    }
    E& operator=(const E& other)
    {
        if (this != &other)
        {
            A::operator=(other);
            delete[]x;
            x = new char[strlen(other.x) + 1];
            strcpy(x, other.x);
        }
        return *this;
    }
    void print()const
    {
        A::print();
        std::cout << "E::x " << x << std::endl;
    }
};

class D:public B, public C, public E
{
private:
    char* x;
public:
    D(const char* a = "", const char* b = "", const char* c = "", const char* d = "", const char* e = "")
        :A(a), B(a, b), C(a, c), E(a, e)
    {
        x = new char[strlen(d) + 1];
        strcpy(x, d);
    }
    ~D()
    {
        std::cout << "~D()\n";
        delete[]x;
    }
    D(const D& other)
    {
        x = new char[strlen(other.x) + 1];
        strcpy(x, other.x);
    }
    D& operator=(const D& other)
    {
        if (this != &other)
        {
            B::operator=(other);
            C::operator=(other);
            E::operator=(other);
            delete[]x;
            x = new char[strlen(other.x) + 1];
            strcpy(x, other.x);
        }
        return *this;
    }
    void print()const
    {
        B::print();
        C::print();
        E::print();
        std::cout << "D::x " << x << std::endl;
    }
};

int main()
{
    D d("111", "222", "333", "444", "555");
    D d1, d2;
    d.print();
    d1.print();
    d2.print();

    return 0;
}

