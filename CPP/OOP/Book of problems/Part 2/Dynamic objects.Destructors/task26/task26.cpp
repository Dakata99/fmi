#include <iostream>

class L
{
private:
    int a;
    double b;
public:
    L(int x = 5, double y = 2.5)
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
    L* p;
    p = new L(8);

    if (!p)
    {
        std::cout << "Error when allocating memory!" << std::endl;
        return 1;
    }
    p->display();
    delete p;
    p = new L(1, 3.5);
    if (!p)
    {
        std::cout << "Error when allocating memory!" << std::endl;
        return 1;
    }
    p->display();
    delete p;
    
    return 0;
}