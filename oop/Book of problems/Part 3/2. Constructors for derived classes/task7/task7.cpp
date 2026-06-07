#include <iostream>

class base
{
private:
    int a;
public:
    base(int x = 1)
    {
        a = x;
    }
    int get()const
    {
        return a;
    }
};

class der:public base
{
private:
    int b;
public:
    der(int y = 5)
    {
        b = y;
    }
    int get()const
    {
        return b;
    }
};

void func()
{
    base b;
    der d;
    std::cout << b.get() << std::endl;
    std::cout << d.get() << std::endl;
}

int main()
{
    func();

    return 0;
}