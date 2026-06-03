#include <iostream>

class F
{
private:
    int a, b;
public:
    F();
    F(int);
    F(int, int);
    void display()const;
};

F::F()
{
    a = b = 0;
}

F::F(int x)
{
    a = x;
}

F::F(int x, int y)
{
    a = x;
    b = y;
}

void F::display() const
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    F f1, f2(1), f3(1, 2);
    f1.display();
    f2.display();
    f3.display();
    
    return 0;
}