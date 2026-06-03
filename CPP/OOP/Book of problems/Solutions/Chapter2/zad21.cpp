#include <iostream.h>

class K
{
private:
    int a;
    double b;

public:
    K(int, double);
    K(K const &);
    void display() const;
};

K::K(int x, double y)
{
    a = x;
    b = y;
}

K::K(K const &r)
{
    a = r.a;
    b = r.b;
}

void K::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    K e1(4, 1.8), *e2 = &e1;
    e1.display();
    e2->display();
    K e3 = *e2;
    e3.display();
    return 0;
}
