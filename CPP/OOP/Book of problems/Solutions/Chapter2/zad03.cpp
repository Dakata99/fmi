#include <iostream.h>

class C
{ 
private:
    int a, b;

public:
    void init(int, int);
    void display() const;
};

void C::init(int x, int y)
{ 
    a = x;
    b = y;
}

void C::display() const
{ 
    cout << a << " " << b << endl;
}

int main()
{ 
    C c;
    c.init(5, 8);
    c.display();
    return 0;
}
