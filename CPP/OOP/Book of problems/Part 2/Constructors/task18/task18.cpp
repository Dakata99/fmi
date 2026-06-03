#include <iostream>

class H
{
private:
    int a, b;
public:
    H(int a = 1, int b = 1)
    {
        this->a = a;
        this->b = b;
    }
    H(H const& other)
    {
        this->a = other.a;
        this->b =other.b;
    }
    void display() const
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    H h1, h2(6), h3(3, 8);
    h1.display();
    h2.display();
    h3.display();

    H h4 = h3;
    h4.display();

    return 0;
}