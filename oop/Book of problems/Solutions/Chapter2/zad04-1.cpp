#include <iostream.h>

class C
{ 
private:
    int a, b;

public:
    void init(int x, int y)
    {
        a = x;
        b = y;
    }

    void display() const
    {
        cout << a << " " << b << endl;
    }
};
