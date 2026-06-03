#include <iostream>

class F
{
private:
    int a;
    char b;
public:
    F(int, char = 'b');
    ~F();
    void write()const;
};

F::F(int x, char y):b(y)
{
    std::cout << "F(int, char)\n";
    a = x;
}
F::~F()
{
    std::cout << "~F()\n";
}
void F::write()const
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    F* ptr;
    ptr = new F(8);
    if (!ptr)
    {
        std::cout << "Error!\n";
        return -1;
    }
    ptr->write();
    delete ptr;
    
    ptr = new F(1, 'x');
    if (!ptr)
    {
        std::cout << "Error!\n";
        return -1;
    }
    ptr->write();
    delete ptr;
    
    /*Output:
        F(int, char)
        8 b
        ~F()
        F(int, char)
        1 x
        ~F()
        */

    return 0;
}