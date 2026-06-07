#include <iostream.h>

class E
{ 
private:
    int a, b;

public:
    void init();
    void init(int);
    void init(int, int);
    void display() const;
};

void E::init()
{ 
    a = b = 0;
}

void E::init(int x)
{ 
    a = x;
}

void E::init(int x, int y)
{
    a = x;
    b = y;
}

void E::display() const
{ 
    cout << a << " " << b << endl;
}

int main()
{ 
    E e1, e2, e3;
    e1.init();
    e2.init(1);
    e3.init(1, 2);
    e1.display();
    e2.display();
    e3.display();
    return 0;
}
