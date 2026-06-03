#include <iostream.h>

class C
{
private:
    int a, b;

public:
    void init(int, int);
    void display() const;
};

inline void C::init(int x, int y)
{
    a = x;
    b = y;
}

inline void C::display() const
{ 
    cout << a << " " << b << endl;
}
