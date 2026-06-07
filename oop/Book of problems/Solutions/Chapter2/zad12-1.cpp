#include <iostream.h>

class fact
{ 
public:
    // конструктор
    fact(int a)
    {
        x = a;
    }
    // намиране на x!
    unsigned int value() const
    { 
        int y = 1;
        for(int i = 1; i <= x; i++)
            y *= i;
        return y;
    }

private:
    int x;
};

int main()
{ 
    int a;
    do
    { 
        cout << "a= "; 
        cin >> a;
    } while(a <= 0);

    // създаване на обект t от клас fact
    fact t(a);
    // намиране и извеждане на a!
    cout << t.value() << endl; 
    return 0;
}
