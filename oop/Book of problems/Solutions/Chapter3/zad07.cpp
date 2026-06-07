#include <iostream.h>

class base
{ 
private:
    int a;

public:
    base(int x = 1)
    { 
        a = x;
    }
    int get() const
    { 
        return a;
    }
};

class der : public base
{ 
private:
    int b;

public:
    der(int y = 5)
    {
        b = y;
    }

    int get() const
    { 
        return b;
    }
};

int main()
{ 
    base b;
    der d;
    cout << b.get() << endl;
    cout << d.get() << endl;
    return 0;
}
