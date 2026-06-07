#include <iostream>

class C
{
private:
    char* ptr;
public:
    C()
    {
        std::cout << "C()\n";
        ptr = new char[10];
    }
    ~C()
    {
        std::cout << "~C()\n";
        delete[]ptr;
    }
};

void f()
{
    C c1, c2, c3;
    //they will die here
}

int main()
{
    f();
    return 0;
}