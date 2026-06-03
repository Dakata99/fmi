#include <iostream>

class base
{
protected:
    int b;
public:
    base(int x)
    {
        b = x;
    }
    base& operator=(const base& x)
    {
        b = x.b + 1;
        return *this;
    }
};

class der1:public base
{
private:   
    int d;
public:
    der1(int x = 1):base(x)
    {
        d = x;
    }
    der1& operator=(const der1& x)
    {
        d = x.d + 2;
        b = x.b + 3;
        return *this;
    }
    void print()const
    {
        std::cout << "der: " << d << " base: " << b << std::endl;
    }
};

class der2:public base
{
private:
    int d;
public:    
    der2(int x = 2):base(x)
    {
        d = x;
    }
    der2& operator=(const der2& x)
    {
        d = x.d + 3;
        return *this;
    }
    void print()const
    {
        std::cout << "der: " << d << " base: " << b << std::endl;
    }
};

class der3:public base
{
private:
    int d;
public: 
    der3(int x = 3):base(x)
    {
        d = x;
    }
    void print()const
    {
        std::cout << "der: " << d << " base: " << b << std::endl;
    }
};

int main()
{
    der1 d1(5), d2;
    der2 d3(5), d4;
    der3 d5(5), d6;

    d2 = d1;
    d4 = d3;
    d6 = d5;

    std::cout << "d1: ";d1.print(); //der:5 base:5
    std::cout << "d2: ";d2.print(); //der:7 base:8
    std::cout << "d3: ";d3.print(); //der:5 base:5
    std::cout << "d4: ";d4.print(); //der:8 base:2
    std::cout << "d5: ";d5.print();//der:5 base:5
    std::cout << "d6: ";d6.print();//der:8 base:6

    return 0;
}