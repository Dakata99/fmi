#include <iostream>

class Top
{
public:
    Top()
    {
        std::cout << "Top::Top()\n";
    }
    Top(int x)
    {
        std::cout << "Top::Top(" << x << ")\n";
    }
};

class Middle1:virtual public Top
{
public:
    Middle1():Top(1)
    {
        std::cout << "Middle1::Middle1()\n";
    }
};

class Middle2:virtual public Top
{
public:
    Middle2():Top(2)
    {
        std::cout << "Middle2::Middle2()\n";
    }
};

class Middle3:public Top
{
public:
    Middle3():Top(3)
    {
        std::cout << "Middle3::Middle3()\n";
    }
};

class Bottom:public Middle1, public Middle2, public Middle3
{
public:
    Bottom()
    {
        std::cout << "Bottom::Bottom()\n";
    }
};

int main()
{
    Bottom b;

    return 0;
}
