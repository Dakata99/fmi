#include <iostream.h>

class base
{ 
public:
    base(int x)
    { 
        cout << "base(int)\n";
        b = x;
    }
    base(const base &x)
    { 
        cout << "base(const base &)\n";
        b = x.b + 1;
    }

protected:
    int b;
};

class der : public base
{ 
public:
    der(int x = 1) : base(x)
    { 
        cout << "der(int)\n";
        d = x;
    }
    der(const der& x) : base(x)
    { 
        cout << "der(const der &)\n";
        d = x.d + 2;
    }
    void print() const
    {
        cout << "der: " << d
            << " base: " << b << endl;
    }

private:
    int d;
};

int main()
{ 
    der d1(5);
    der d2 = d1;
    cout << "d1: "; d1.print();
    cout << "d2: "; d2.print();
    return 0;
}
