#include <iostream>

class B
{
private:
    int b;
public:
    B(int n)
    {
        b = n;
    }
    void print()
    {
        std::cout << "B: " << b << std::endl;
    }
};

class D:public B
{
private:
    B b;
public:
    D(){}
    D(int n):B(n)
    {
        b = n;
    }
    void print()const
    {
        std::cout << "D: " << b << std::endl;
    }
};

int main()
{

    return 0;
}