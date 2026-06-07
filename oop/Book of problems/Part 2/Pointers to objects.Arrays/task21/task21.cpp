#include <iostream>

class K
{
private:
    int a;
    double b;
public:
    K(int a, double b)
    {
        this->a = a;
        this->b = b;
    }
    K(K const& other)
    {
        this->a = other.a;
        this->b = other.b;
    }
    void display() const
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    K k1(4, 1.8), *k2 = &k1;
    k1.display();
    k2->display();

    K k3 = *k2;
    k3.display();

    return 0;
}