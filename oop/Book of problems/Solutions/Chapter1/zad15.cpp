#include <iostream.h>
#include <math.h>

struct rat
{ 
private:
    int num;                          // числител
    int den;                          // знаменател

public:
    void makerat(int, int);           // създава рационално число
    int numer()const;                 // намира числителя на рационално число
    int denom()const;                 //намира знаменателя на рационално число
    void printrat() const;            // извежда рационално число
};

// намиране на най-големия общ делител
// на две естествени числа
int gcd(int a, int b)
{
    while(a != b)
    {
        if (a > b) a = a-b; 
        else b = b-a;
    }
    return a;
}

void rat::makerat(int a, int b)
{
    // предполага се, че b е различно от 0
    if(a == 0)
    {
        num = 0;
        den = 1;
    }
    else
    {
        int g = gcd(abs(a), abs(b));
        if(a > 0 && b > 0 || a < 0 && b < 0)
        {
            num = abs(a)/g;
            den = abs(b)/g;
        }
        else
        {
            num = - abs(a)/g;
            den = abs(b)/g;
        }
    }
}

int rat::numer() const
{
    return num;
}

int rat::denom() const
{
    return den;
}

void rat::printrat() const
{
    cout << num << "/" << den << endl;
}

bool equal(const rat& x, const rat& y)
{
    return x.numer()*y.denom() ==
           x.denom()*y.numer();
}

bool grthen(const rat& x, const rat& y)
{
    return x.numer()*y.denom() >
           x.denom()*y.numer();
}

rat maxrat(int n, rat x[])
{
    rat max = x[0];
    for(int i = 1; i < n; i++)
        if(grthen(x[i], max))
            max = x[i];
    return max;
}

// намиране на сумата на рационалните числа r1 и r2
rat sumrat(const rat& r1, const rat& r2)
{ 
    rat r; 
    r.makerat(r1.numer() * r2.denom() + r2.numer() * r1.denom(),
              r1.denom() * r2.denom());
    return r;
}

// намиране на разликата на рационалните числа r1 и r2
rat subrat(const rat& r1, const rat& r2)
{ 
    rat r;
    r.makerat(r1.numer() * r2.denom() - r2.numer() * r1.denom(),
              r1.denom() * r2.denom());
    return r;
}

// намиране на произведението на рационалните числа r1 и r2
rat multrat(const rat& r1, const rat& r2)
{ 
    rat r; 
    r.makerat(r1.numer()*r2.numer(),
              r1.denom()*r2.denom());
    return r;
}

// намиране на частното на рационалните числа r1 и r2
rat quotrat(const rat& r1, const rat& r2)
{
    rat r;
    r.makerat(r1.numer()*r2.denom(),
              r1.denom()*r2.numer());
    return r;
}

// решаване на системата
void rat_system(const rat& a, const rat& b,
                const rat& c, const rat& d,
                const rat& e, const rat& f)
{ 
    rat det = subrat(multrat(a, d), multrat(c, b)), zero;
    zero.makerat(0, 1);
    if(equal(det, zero))
    {
        if(equal(multrat(b, f), multrat(d, e)))
            cout << "Системата има безброй много решения.\n";
        else cout << "Системата няма решение.\n";
    }
    else
    { 
        rat x, y;
        x = quotrat(subrat(multrat(e, d), multrat(b, f)), det);
        y = quotrat(subrat(multrat(a, f), multrat(c, e)), det);
        x.printrat();
        y.printrat();
    }
}

int main()
{ 
    // дефиниране на коефициентите на системата
    rat a, b, c, d, e, f;
    // свързване на коефициентите на системата
    // със стойности
    a.makerat(1,2); b.makerat(-1,4);
    c.makerat(3,2); d.makerat(1,4);
    e.makerat(3,6); f.makerat(0,4);
    // решаване на системата
    rat_system(a, b, c, d, e, f);
    return 0;
}
