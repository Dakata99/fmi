#include <iostream>

class E
{
private:
    int a;
    double b;
public:
    E(int, double);
    E(E const&);
    void write()const;
};

E::E(int x, double y):a(x+1), b(y+1)
{
    std::cout << "E(int, double)\n";
}
E::E(E const& other)
{
    std::cout << "E(E const&)\n";
    a = other.a - 2;
    b = other.b - 2;
}
void E::write()const
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    E e1(1, 4.5), *ptr = &e1;
    e1.write();ptr->write();
    E e2 = *ptr;e2.write();

    return 0;
}