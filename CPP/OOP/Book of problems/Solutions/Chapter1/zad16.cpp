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

// намиране на стойността на полинома
rat Horner(int n, rat a[], const rat& x)
{ 
    rat s;
    s = a[0];
    for(int i = 1; i <= n; i++)
        s = sumrat(multrat(s, x), a[i]);
    return s;
}

int main()
{
    rat x, a[10]; 
    // създаване на рационалното число x
    int p, q;
    do
    { 
        cout << "x_numer, x_denom? ";
        cin >> p >> q;
    } while(q == 0);
    x.makerat(p, q);  

    // въвеждане на степента на полинома
    cout << "n= "; int n; cin >> n;

    // въвеждане на коефициентите на полинома
    for(int i = 0; i <= n; i++)
    { 
        do
        { 
            cout << "numer, denom? ";
            cin >> p >> q;
        } while(q == 0);
        a[i].makerat(p, q);
    }

    // намиране и извеждане на стойността на полинома
    Horner(n, a, x).printrat();
    return 0;
}
