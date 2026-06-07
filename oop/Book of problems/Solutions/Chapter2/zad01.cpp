#include <iostream.h>

class A
{
public:
    void Hello();
};

void A::Hello()
{
    cout << "Hello world!\n";
}

int main()
{
    A e;
    e.Hello();
    return 0;
}
