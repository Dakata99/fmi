#include <iostream.h>

class gcd
{
public:
    // конструктор
    gcd(int a, int b)
    {
        x = a; 
        y = b;
    }

    // намиране на най-големия общ делител на x и y
    int value() const
    { 
        if(y == 0)
        {
            return x;
        }
        else
        { 
            gcd t(y, x%y);
            return t.value();
        }
    }

private:
    int x, y;
};

int main()
{
    int a, b;
    do
    {
        cout << "a= "; cin >> a;
        cout << "b= "; cin >> b;
    } while(a < 0 || b < 0 || a == 0 && b == 0);

    // създаване на обект от клас gcd
    gcd t(a,b);
    // намиране и извеждане на най-големия
    // общ делител на a и b
    cout << t.value() << endl;
    return 0;
}
