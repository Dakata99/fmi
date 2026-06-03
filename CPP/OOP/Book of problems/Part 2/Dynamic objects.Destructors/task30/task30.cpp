#include <iostream>

class P
{
private:
    int a;
    double b;
public:
    P(int x = 5, double y = 2.5)
    {
        a = x;
        b = y;
    }
    ~P()
    {
        std::cout << "~P" << std::endl;
    }

    void display()const
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    P *p;
    p = new P[5];
    if (!p)
    {
        return 1;
    }
    for (size_t i = 0; i < 5; i++)
    {
        p[i].display();
    }
    delete[]p;
    
    return 0;
}