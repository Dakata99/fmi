#include <iostream>

class M
{
private:
    int a;
    double b;
public:
    M(int x = 5, double y = 2.5)
    {
        a = x;
        b = y;
    }
    void set(int x, double y)
    {
        a = x;
        b = y;
    }
    void display()const
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    M *p;
    p = new M[5];

    if (!p)
    {
        std::cout << "Error with allocating memory!" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < 5; i++)
    {
        p[i].display();
    }
    for (size_t i = 0; i < 5; i++)
    {
        p[i].set(i, i + 1.5);
    }
    for (size_t i = 0; i < 5; i++)
    {
        p[i].display();
    }
    delete[]p;
    
    return 0;
}