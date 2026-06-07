#include <iostream>

class base
{
private:
    double a;
public: 
    void set_a(double x)
    {a = x;}
    double get_a()const{return a;}
};

class der:public base
{
private: 
    double b;
public:
    void set_b(double x){b = x;set_a(x+5);}
    double get_b()const{return b;}
};

int main()
{
    der d;

    return 0;
}