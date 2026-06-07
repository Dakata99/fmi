#include <iostream.h>

class Q
{
public:
    void f();
    void g();
    int x;
};

void Q::f()
{ 
    cout << "f()\n" << "x= " << x << endl;
}

void Q::g()
{ 
    --x;
    cout << "g()\n" << "x= " << x << endl;
}

int main()
{ 
    Q obj;
    // дефиниране на указател px към цялата
    // компонента x на класа Q
    int Q::*px = & Q::x;
    // обръщение към x чрез указателя px
    obj.*px = 25;
    cout << obj.*px << endl;
    // дефиниране на указател ptr към член-функцията f
    void (Q::*ptr)() = &Q::f;
    // обръщение към f чрез указателя към нея
    (obj.*ptr)();
    // свързване на ptr с член-функцията g
    ptr = &Q::g;
    // обръщение към g чрез указателя ptr
    (obj.*ptr)();
    return 0;
}
