#include <iostream>

class H
{
private:
    int* a;
public:
    H(int x)
    {
        a = new int(x);
    }
    ~H()
    {
        std::cout << "~H()\n";
        delete[]a;
    }
    void write()const
    {
        std::cout << *a << std::endl;
    }
};

int main()
{
    H o1(5), o2(10);
    o1.write();o2.write();
    o1 = o2;
    o1.write();

    return 0;
}