#include <iostream.h>

class base
{
public:
    void init(int x)
    {
        bx = x;
    }
    void display() const
    {
        cout << " class base: bx = " << bx << endl;
    }

protected:
    int bx;
};

class der : public base
{
public:
    void init(int x)
    {
        bx = x; 
        base::bx = x + 5;
    }
    void display() const
    {
        cout << " class der: bx = " << bx;
        cout << " base::bx = " << base::bx << endl;
    }

protected:
    int bx;
};

class derder : public der
{
public:
    void init(int x)
    {
        bx = x; 
        base::bx = x + 5;
        der::bx = x + 10;
    }
    void display() const
    {
        cout << " class derder: bx = " << bx;
        cout << " class der: bx = " << der::bx;
        cout << " base::bx = " << base::bx << endl;
    }

protected:
    int bx;
};

int main()
{
    base b;
    der d;
    derder dd;
    b.init(5); d.init(10); dd.init(100);
    b.display(); d.display(); dd.display();
    d.base::init(20);
    d.base::display();
    d.display();
    b.display();
    return 0;
}
