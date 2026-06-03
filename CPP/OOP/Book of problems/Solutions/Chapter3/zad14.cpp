#include <iostream.h>

class A
{
public:
    A(int x = 5) 
    {
        a = x;
    }
    A& operator=(const A &x)
    { 
        if(this!=&x) a = x.a + 1;
        return *this;
    }
    void Print() const
    { 
        cout << "A: " << a << endl;
    }

private:
    int a;
};

class B : public A
{
public:
    B(int x = 1)
    {
        y = x;
    }
    B& operator=(const B& x)
    { 
        if(this != &x)
        { 
            y = x.y + 2;
            A::operator=(x);
        }
        return *this;
    }
    void Print() const
    { 
        cout << "B: " << y << endl;
        A::Print();
    }

private: 
    int y;
};

class C : public A
{
public:
    C(int x = 2) : A(x+3)
    { 
        y = x;
    }
    C(const C& p)
    { 
        y = p.y + 2;
    }
    C& operator=(const C& x)
    { 
        if(this !=&x)
        {
            y = x.y + 3;
            A::operator=(x);
        }
        return *this;
    }
    void Print() const
    {
        cout << "C: " << y << endl;
        A::Print();
    }

private:
    int y;
};

class D : public C
{ 
public:
    D(int x = 3)
    { 
        y = x;
    }
    D(const D& p) : C(p)
    {
        y = p.y+3;
    }
    void Print()
    { 
        cout << "D: " << y << endl;
        C::Print();
    }

private:
    int y;
};

int main()
{ 
    B x(10), y = x;
    C z(20), u;
    D v(30), t = v;
    cout << "x: "; x.Print();
    cout << "y: "; y.Print();
    cout << "z: "; z.Print();
    cout << "u: "; u.Print();
    cout << "v: "; v.Print();
    cout << "t: "; t.Print();
    y = x; cout << "y: "; y.Print();
    u = z; cout << "u: "; u.Print();
    t = v; cout << "t: "; t.Print();
    return 0;
}
