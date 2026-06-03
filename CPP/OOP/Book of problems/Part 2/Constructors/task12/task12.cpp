#include <iostream>

class Fact
{
private:
    int n;
public:
    Fact(int x)
    {
        n = x;
    }
    unsigned int getFact(int)const;
};

unsigned int Fact::getFact(int x) const
{
    if (x == 0)
    {
        return 1;
    }
    return x * getFact(x - 1);
}

int main()
{
    int x;
    do
    {
        std::cin >> x;
    } while (x <= 0);
    Fact f(x);
    std::cout << f.getFact(x) << std::endl;
    
    
    return 0;
}