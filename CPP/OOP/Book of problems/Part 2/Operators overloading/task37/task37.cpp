#include <iostream>

class Rat
{
private:
    int n, d;
public:
    Rat():n(0), d(1){}
    Rat(const int _n, const int _d)
    {
        n = _n;
        if(_d == 0)
            d = 1;
        else
            d = _d;
    }

    //getters
    int getN()const
    {
        return n;
    }
    int getD()const
    {
        return d;
    }

    //setters
    void setN(const int _n)
    {
        n = _n;
    }
    void setD(const int _d)
    {
        d = _d;
    }

    void print()const
    {
        std::cout << n << "/" << d << std::endl;
    }

    Rat operator+(const Rat& other)
    {
        return Rat(n*other.getD() + other.getN()*d, d*other.getD());
    }
    Rat operator-(const Rat& other)
    {
        return Rat(n*other.getD() - other.getN()*d, d*other.getD());
    }
    Rat operator*(const Rat& other)
    {
        return Rat(n*other.getN(), d*other.getD());
    }
    Rat operator/(const Rat& other)
    {
        return Rat(n*other.getD(), d*other.getN());
    }

};

void func()
{
    Rat r1(2, 3), r2(5, 7);

    Rat r3 = r1 + r2;
    Rat r4 = r1 - r2;
    Rat r5 = r1*r2;
    Rat r6 = r1/r2;

    r3.print();
    r4.print();
    r5.print();
    r6.print();
}

int main()
{
    func();

    return 0;
}