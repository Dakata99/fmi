#include <iostream>

class A
{
public:
    void Hello();
};

void A::Hello()
{
    std::cout << "Hello world!\n" << std::endl;
}

int main()
{
    A e;
    e.Hello();
    //prints Hello world!
    return 0;
}