#include <iostream>

class base
{
protected:
    int bx;
public:
    void init(int x)
    {
        bx = x;
    }
    void display()const
    {
        std::cout << "class base: bx = " << bx << std::endl;
    }
};

class der:public base
{
protected:
    int bx;
public: 
    void init(int x)
    {
        bx = x;
        base::bx = x + 5;
    }
    void display()const
    {
        std::cout << "class der: bx = " << bx << std::endl;
        std::cout << "base::bx = " << base::bx << std::endl;
    }
};

class derder:public der
{
protected:
     int bx;
public:
    void init(int x)
    {
        bx = x;
        base::bx = x + 5;
        der::bx = x + 10;
    }
    void display()const
    {
        std::cout << "class derder: bx = " << bx << std::endl;
        std::cout << " class der:bx = " << der::bx << std::endl;
        std::cout << "class base:bx = " << base::bx << std::endl;
    }
};

int main()
{
    base b;
    der d;
    derder dd;

    b.init(5); //bx = 5
    d.init(10); //bx = 5 for d, bx = 10 for base
    dd.init(100); //bx = 100 for dd, bx = 15 for base, bx = 10 for d

    b.display();d.display();dd.display();
    //class base:bx = 5
    //class der:bx = 10, base::bx = 15
    //class derder:bx = 100, class der:bx = 110, class base:bx = 105
    
    d.base::init(20);//bx = 20
    d.base::display();//class base:bx = 20

    d.display();//class der:bx = 10, base::bx = 20
    b.display();//class base:bx = 5

    return 0;
}