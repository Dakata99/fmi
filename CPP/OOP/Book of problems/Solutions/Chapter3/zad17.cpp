#include <iostream.h>

class base
{
public:
    base(int x)
    {
        b = x;
    }

    base& operator=(const base &x)
    {
        b = x.b + 1;
        return *this;
    }

protected:
    int b;
};

class der1 : public base
{
public:
    der1(int x = 1) : base(x)
    {
        d = x;
    }

    der1& operator=(const der1& x)
    {
        d = x.d + 2;
        b = x.b + 3;
        return *this;
    }

    void print() const
    { 
        cout << "der: " << d << " base: " << b << endl;
    }

private:
    int d;
};

class der2 : public base
{ 
public:
    der2(int x = 2) : base(x)
    { 
        d = x;
    }

    der2& operator=(const der2& x)
    { 
        d = x.d + 3;
        return *this;
    }

    void print() const
    { 
        cout << "der: " << d << " base: " << b << endl;
    }

private:
    int d;
};

class der3 : public base
{ 
public:
    der3(int x = 3) : base(x)
    {
        d = x;
    }

    void print() const
    { 
        cout << "der: " << d << " base: " << b << endl;
    }

private:
    int d;
};

int main()
{ 
    der1 d1(5), d2;
    der2 d3(5), d4;
    der3 d5(5), d6;
    d2 = d1;
    d4 = d3;
    d6 = d5;
    cout << "d1: "; d1.print();
    cout << "d2: "; d2.print();
    cout << "d3: "; d3.print();
    cout << "d4: "; d4.print();
    cout << "d5: "; d5.print();
    cout << "d6: "; d6.print();
    return 0;
}
