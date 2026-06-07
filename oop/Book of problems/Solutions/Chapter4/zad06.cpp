#include <iostream.h>
#include <stdlib.h>
#include <string.h>

class A
{
public:
    // канонично представяне
    A(char* = "");
    ~A();
    A(const A&);
    A& operator=(const A &);
    // извеждане на компонентите на класа
    void print() const;

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

A::A(const A& p)
{
    x = new char[strlen(p.x)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, p.x);
}

A& A::operator=(const A& p)
{
    if(this != &p)
    {
        delete x;
        x = new char[strlen(p.x)+1];
        if(!x)
        {
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(x, p.x);
    }
    return *this;
}

void A::print() const
{
    cout << "A::x " << x << endl;
}

class B : virtual public A
{
public:
    // канонично представяне
    B(char* = "", char* = "");
    ~B();
    B(const B&);
    B& operator=(const B&);
    // извеждане на компонентите на класа
    void print() const;

private:
    char* x;
};

B::B(char* a, char* b) : A(a)
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

B::B(const B& p) : A(p)
{
    x = new char[strlen(p.x)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, p.x);
}

B& B::operator=(const B& p)
{
    if(this != &p)
    {
        A::operator=(p);
        delete x;
        x = new char[strlen(p.x)+1];
        if(!x)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(x, p.x);
    }
    return *this;
}

void B::print() const
{
    A::print();
    cout << "B::x " << x << endl;
}

class C : virtual public A
{
public:
    // канонично представяне
    C(char* = "", char* = "");
    ~C();
    C(const C&);
    C& operator=(const C&);
    // извеждане на компонентите на класа
    void print() const;

private:
    char* x;
};

C::C(char* a, char* b) : A(a)
{
    x = new char[strlen(b)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, b);
}

C::~C()
{
    cout << "~C()\n";
    delete x;
}

C::C(const C& p) : A(p)
{
    x = new char[strlen(p.x)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, p.x);
}

C& C::operator=(const C& p)
{
    if(this != &p)
    {
        A::operator=(p);
        delete x;
        x = new char[strlen(p.x)+1];
        if(!x)
        {
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(x, p.x);
    }
    return *this;
}

void C::print() const
{
    A::print();
    cout << "C::x " << x << endl;
}

class E : public A
{
public:
    // канонично представяне
    E(char* = "", char* = "");
    ~E();
    E(const E&);
    E& operator=(const E&);
    // извеждане на компонентите на класа
    void print() const;
private:
    char* x;
};

E::E(char* a, char* b) : A(a)
{
    x = new char[strlen(b)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, b);
}

E::~E()
{
    cout << "~E()\n";
    delete x;
}

E::E(const E& p) : A(p)
{
    x = new char[strlen(p.x)+1];
    if(!x)
    {
        cout << "Грешка при заделяне на памет!\n";
        return;
    }
    strcpy(x, p.x);
}

E& E::operator=(const E& p)
{
    if(this != &p)
    {
        A::operator=(p);
        delete x;
        x = new char[strlen(p.x)+1];
        if(!x)
        {
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(x, p.x);
    }
    return *this;
}

void E::print() const
{
    A::print();
    cout << "E::x " << x << endl;
}

class D : public B, public C, public E
{
public:
    // канонично представяне
    D(char* a = "", char* b = "", char* c = "", char* d = "", char* e = "") : 
      A(a), B(a, b), C(a, c), E(a, e)
    // Някои компилатори изискват явно да се укаже кой клас А се
    //инициализира по следния начин: B::A(a)
    {
        x = new char[strlen(d)+1];
        if(!x)
        {
            cout << "Грешка при заделяне на памет!\n";
            return;
        }
        strcpy(x, d);
    }

    ~D()
    {
        cout << "~D() \n";
        delete x;
    }

    D(const D& p) : 
      A((const B&)p), B(p), C(p), E(p)
      // Някои компилатори изискват явно да се укаже кой клас А се
      //инициализира по следния начин: B::A((const B&)p)
    {
        x = new char[strlen(p.x)+1];
        if(!x)
        {
            cout << "Грешка при заделяне на памет!\n";
            return;
        }
        strcpy(x, p.x);
    }

    D& operator=(const D&p)
    {
        if(this!=&p)
        {
            B::operator=(p);
            C::operator=(p);
            E::operator=(p);
            delete x;
            x = new char[strlen(p.x)+1];
            if(!x)
            {
                cout << "Грешка при заделяне на памет!\n";
                exit(1);
            }
            strcpy(x, p.x);
        }
        return *this;
    }

    // извеждане на компонентите на класа
    void print() const;
private:
    char* x;
};

void D::print() const
{
    B::print();
    C::print();
    E::print();
    cout << "D::x " << x << endl;
}

int main()
{
    D d("111", "222", "333", "444", "555");
    D d1, d2;
    d2 = d1 = d;
    d.print();
    d1.print();
    d2.print();
    return 0;
}
