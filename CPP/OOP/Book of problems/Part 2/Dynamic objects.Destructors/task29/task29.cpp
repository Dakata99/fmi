#include <iostream>

class N
{
private:
    int a;
    double b;
public:
    N(int x = 5, double y = 2.5)
    {
        a = x;
        b = y;
    }
    ~N()
    {
        std::cout << "~N" << std::endl;
    }

    void print()const 
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    N *p = NULL;
    p = new N(8);
    if (!p)
    {
        return 1;
    }
    p->print();
    delete p;
    p = new N(1, 3.5);
    if (!p)
    {
        return 1;
    }
    p->print();
    delete p;
    
    return 0;
}