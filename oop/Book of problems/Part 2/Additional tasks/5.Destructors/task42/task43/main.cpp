#include <iostream>

class G
{
private:
    int* a;
public: 
    G(int);
    ~G();
    void write()const;
};

G::G(int x)
{
    a = new int(x);
}
G::~G()
{
    std::cout << "~G()\n";
    delete a;
}
void G::write()const
{
    std::cout << *a << std::endl;
}

int main()
{
    G o1(5), o2(10);
    o1.write();o2.write();
    G o3 = o2;
    o3.write();

    return 0;
}