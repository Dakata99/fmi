#include <iostream.h>

class Top
{
public:
    Top()
    {
        cout << "Top::Top()\n";
    }

    Top(int x)
    {
        cout << "Top::Top(" << x << ")\n";
    }
};

class Middle1 : virtual public Top
{
public:
    Middle1() : Top(1)
    {
        cout << "Middle1::Middle1()\n";
    }
};

class Middle2 : virtual public Top
{
public:
    Middle2() : Top(2)
    {
        cout << "Middle2::Middle2()\n";
    }
};

class Middle3 : public Top
{
public:
    Middle3() : Top(3)
    {
        cout << "Middle3::Middle3()\n";
    }
};

class Bottom : public Middle1,
               public Middle2,
               public Middle3
{ 
public:
    Bottom()
    {
        cout << "Bottom::Bottom()\n";
    }
};

int main()
{
    Bottom b;
    return 0;
}

