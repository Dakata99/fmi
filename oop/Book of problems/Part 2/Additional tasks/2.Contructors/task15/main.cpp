#include <iostream>

class D
{
private:
    int a;
    double b;
public:
    D(int x = 1, double y = 1.5):a(x), b(y+3.5)
    {
        std::cout << "D(int, double)\n";
    }
    D(D const& other)
    {
        a = other.a + 2;
        b = other.b + 2;
    }
    void write()const
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    D e1, e2(6), e3 = D(3, 8.4), e4 = e3;
    e1.write();
    e2.write();
    e3.write();
    e4.write();

    /*Output:
        D(int, double)
        D(int, double)
        D(int, double)
        1 5
        6 5
        3 11.9
        5 13.9*/    

    return 0;
}