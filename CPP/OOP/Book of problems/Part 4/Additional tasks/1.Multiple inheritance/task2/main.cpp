#include <iostream>

class A
{
private:
    int x, y;
public:
    A(int a = 0, int b = 1)
    {
        x = a;
        y = b;
        std::cout << "A: " << x << ", " << y << std::endl;
    }
    A(const A& other)
    {
        x = other.x + 1;
        y = other.y + 2;
        std::cout << "A.x: " << x << std::endl;
        std::cout << "A.y: " << y << std::endl;
    }
    A& operator=(const A& other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
};

class B
{
private:
    int x, y;
public:
    B(int a = 2, int b = 3)
    {
        x = a; 
        y = b;
        std::cout << "B: " << x << ", " << y << std::endl;
    }
};

class C
{
private:
    int x, y;
public:
    C(int a = 1, int b = 2)
    {
        x = a;
        y = b;
        std::cout << "C: " << x << ", " << y << std::endl;
    }
    C(const C& other)
    {
        x = other.x + 1;
        y = other.y + 2;
        std::cout << "C.x: " << x << std::endl;
        std::cout << "C.y: " << y << std::endl;
    }
};

class D:public B, A, protected C
{
private:
    int x, y;
public:
    D(int a = 3, int b = 1, int c = 2):A(a), B(b), C(c)
    {
        x = b + c;
        y = a - b;
        std::cout << "D: " << x << ", " << y << std::endl;
    }
    D& operator=(const D& other)
    {
        if (this != &other)
        {
            A::operator=(other);
            x = other.x;
            y = other.y;
        }
        return *this;
    }
};

int main()
{
    D x, y(1, 2, 3), z;
    D t = y;
    z = y;

    /*Output:
        B: 1, 3
        A: 3, 1
        C: 2, 2
        D: 3, 2
        B: 2, 3
        A: 1, 1
        C: 3, 2
        D: 5, -1
        B: 1, 3
        C: 2, 2
        D: 3, 2
        A.x: 2
        A.y: 3
        C.x: 4
        C.y: 4
    */

    return 0;
}