#include <iostream.h>
#include <math.h>

// намира най-голям общ делител на x и y
int gcd(int x, int y)
{ 
    if(y == 0) return x;
    return gcd(y, x % y);
}

class Rat
{ 
public:
    // конструктор с подразбиращи се параметри
    Rat(int = 0, int = 1);
    // конструктор за присвояване
    Rat(const Rat&);
    // член-функции за аритметика с рационални числа
    Rat sum (const Rat&) const;
    Rat mult(const Rat&) const;
    Rat sub (const Rat&) const;
    Rat div (const Rat&) const;
    // член-функция за извеждане на рационално число
    void print() const;
    // функции за достъп
    int numer() const;
    int denom() const;
    // мутатори
    void setNum(int);
    void setDen(int);

private:
    int num;                         // числител
    int den;                         // знаменател
};

// външни функции, предефиниращи операторите +, -, * и /
Rat operator+(const Rat &, const Rat &);
Rat operator*(const Rat &, const Rat &);
Rat operator-(const Rat &, const Rat &);
Rat operator/(const Rat &, const Rat &);

Rat::Rat(int n, int d)
{ 
    if(d == 0)
    { 
        cout << "Неправилен знаменател: 0!"
             << "Заменя се с 1.\n";
        num = n;
        den = 1;
    }
    else
    { 
        if(n == 0)
        { 
            num = 0;
            den = 1;
        }
        else
        { 
            int g = gcd(abs(n), abs(d));
            if(n > 0 && d > 0 || n < 0 && d < 0)
            { 
                num = abs(n)/g;
                den = abs(d)/g;
            }
            else
            { 
                num = -abs(n)/g;
                den =  abs(d)/g;
            }
        }
    }
}

Rat::Rat(const Rat& p)
{
    num = p.num;
    den = p.den;
}

int Rat::numer() const
{ 
    return num;
}

int Rat::denom() const
{
    return den;
}

void Rat::print() const
{ 
    cout << num << "/" << den;
}

void Rat::setNum(int n)
{ 
    num = n;
}

void Rat::setDen(int d)
{ 
    if(d != 0)
    {
        den = d;
    }
    else
    { 
        cout << "Неправилен знаменател: 0!"
             << "Заменя се с 1." << endl;
        den = 1;
    }
}

// събиране на рационални числа
Rat Rat::sum(const Rat &r) const
{ 
    return Rat(num*r.den + den*r.num, den*r.den);
}

// изваждане на рационални числа
Rat Rat::sub(const Rat &r) const
{
    return Rat(num*r.den - den*r.num, den*r.den);
}

// умножаване на рационални числа
Rat Rat::mult(const Rat &r) const
{ 
    return Rat(num*r.num, den*r.den);
}

// деление на рационални числа
Rat Rat::div(const Rat &r) const
{
    return Rat(num*r.den, den*r.num);
}

// оператор за събиране на рационални числа
Rat operator+(const Rat &r, const Rat &s)
{
    return r.sum(s);
}

// оператор за изваждане на рационални числа
Rat operator-(const Rat &r, const Rat &s)
{
    return r.sub(s);
}

// оператор за умножаване на рационални числа
Rat operator*(const Rat &r, const Rat &s)
{
    return r.mult(s);
}

// оператор за деление на рационални числа
Rat operator/(const Rat &r, const Rat &s)
{
    return r.div(s);
}

int main()
{
    // създаване на рационалното число r
    int a, b;
    cout << "a, b= "; cin >> a >> b;
    Rat r(a, b);
    // създаване на различното от 0 рационално число s
    int c, d;

    do
    { 
        cout << "c, d = "; 
        cin >> c >> d;
    } while(c == 0 || d == 0);

    Rat s(c, d);
    // намиране на сумата, разликата, произведението
    // и частното на рационалните числа r и s
    Rat sum  = r + s;
    Rat sub  = r - s;
    Rat mult = r * s;
    Rat div  = r / s;

    // извеждане на сумата, разликата, произведението
    // и частното на рационалните числа r и s
    r.print(); cout << " + "; s.print();
    cout << " = "; sum.print(); cout << endl;
    r.print(); cout << " - "; s.print();
    cout << " = "; sub.print(); cout << endl;
    r.print(); cout << " * "; s.print();
    cout << " = "; mult.print(); cout << endl;
    r.print(); cout << " / "; s.print(); 
    cout << " = "; div.print(); cout << endl;

    // промяна на рационалното число r
    r.setNum(5);
    r.setDen(7);
    r.print(); cout << endl;
    return 0;
}
