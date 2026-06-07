#include <iostream>
class A
{
protected:
    void print(int n)const
    {
        std::cout << n << std::endl;        
    }
};

class D:protected A
{
public:
    void printD(int n)const
    {
        if (n <= 2)
        {
            print(n);
        }
        else if (n % 3 == 0)
        {
            printD(n/3);
        }
        else
        {
            printD(n/2 + 1);
        }
    }
};

int main()
{
    D d;
    d.printD(18); //2

    return 0;
}