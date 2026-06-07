#include <iostream.h>

class B
{
public:
    int a, b;
    void init(int, int);
};

void B::init(int x, int y)
{
    a = x;
    b = y;
}

int main()
{
    B c;
    c.init(5, 8);
    cout << c.a << " " << c.b << endl;
    return 0;
}
