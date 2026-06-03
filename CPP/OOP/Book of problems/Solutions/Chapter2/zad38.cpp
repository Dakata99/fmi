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
    // конструктори
    Rat(int = 0, int = 1);
    Rat(const Rat&);
    // функция за извеждане на рационално число
    void print() const;
    // операторна функция за преобразуване
    // на рационално в реално число
    operator double() const;
    // операторни-функции за рационално-числова аритметика
    // на две рационални числа
    Rat operator+(const Rat&) const;
    Rat operator-(const Rat&) const;
    Rat operator*(const Rat&) const;
    Rat operator/(const Rat&) const;
    // операторни-функции за рационално-числова аритметика
    // на рационално с цяло число
    Rat operator+(int) const;
    Rat operator-(int) const;
    Rat operator*(int) const;
    Rat operator/(int) const;
    // приятелски функции, реализиращи рационално-числова
    // аритметика на цяло число с рационално число
    friend Rat operator+(int, const Rat&);
    friend Rat operator-(int, const Rat&);
    friend Rat operator*(int, const Rat&);
    friend Rat operator/(int, const Rat&);
    // функции за достъп до компонентите
    int numer() const;
    int denom() const;
    // мутатори
    void setNum(int);
    void setDen(int);

private:
    int num;                         // числител
    int den;                           // знаменател
};

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

int Rat::numer() const
{ 
    return num;
}

int Rat::denom() const
{
    return den;
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

void Rat::print() const
{ 
    cout << num << "/" << den;
}

////а)
// оператор за преобразуване на рационално в реално число
Rat::operator double() const
{ 
    return (double)num/den;
}

////б)
// събиране на рационални числа
Rat Rat::operator+(const Rat& r) const
{ 
    return Rat(num*r.den + den*r.num, den*r.den);
}

// изваждане на рационални числа
Rat Rat::operator-(const Rat& r) const
{ 
    return Rat(num*r.den - den*r.num, den*r.den);
}

// умножение на рационални числа
Rat Rat::operator*(const Rat& r) const
{ 
    return Rat(num*r.num, den*r.den);
}

// деление на рационални числа
Rat Rat::operator/(const Rat& r) const
{ 
    return Rat(num*r.den, den*r.num);
}

////в)
// събиране на рационално с цяло число
Rat Rat::operator+(int x) const
{ 
    return Rat(num + den*x, den);
}

// изваждане на цяло число от рационално число
Rat Rat::operator-(int x) const
{
    return Rat(num - den*x, den);
}
// умножение на рационално с цяло число
Rat Rat::operator*(int x) const
{ 
    return Rat(num*x, den);
}

// деление на рационално на цяло число
Rat Rat::operator/(int x) const
{ 
    return Rat(num, den*x);
}

// събиране на цяло с рационално число
Rat operator+(int x, const Rat& r)
{ 
    return Rat(x*r.den + r.num, r.den);
}

// изваждане на рационално от цяло число
Rat operator-(int x, const Rat& r)
{ 
    return Rat(x*r.den - r.num, r.den);
}

// умножение на цяло с рационално число
Rat operator*(int x, const Rat& r)
{ 
    return Rat(x*r.num, r.den);
}

// деление на цяло на рационално число
Rat operator/(int x, const Rat& r)
{ 
    return Rat(x*r.den, r.num);
}

int main()
{ 
    // създаване на рационалното число r
    int a, b;
    cout << "a, b= "; cin >> a >> b;
    Rat r(a, b);
    // преобразуване на r в реално число и извеждане
    cout << r << endl;
    // създаване на различното от 0 рационално число s
    int c, d;
    do
    { 
        cout << "c, d = "; 
        cin >> c >> d;
    } while(c == 0 || d == 0);
    Rat s(c, d);

    // въвеждане на различно от 0 цяло число
    int x; 
    do
    {
        cout << "Въведете различно от 0 цяло число: "; 
        cin >> x;
    } while(x == 0);

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

    // намиране на сумата, разликата, произведението и
    // частното на рационалнoто число r с цялото число x
    Rat sum1  = r + x;
    Rat sub1  = r - x;
    Rat mult1 = r * x;
    Rat div1  = r / x;

    // извеждане на сумата, разликата, произведението и
    // частното на рационалнoто число r с цялото число x
    r.print(); cout << " + " << x << " = ";
    sum1.print(); cout << endl;
    r.print(); cout << " - " << x << " = ";
    sub1.print(); cout << endl;
    r.print(); cout << " * " << x << " = ";
    mult1.print(); cout << endl;
    r.print(); cout << " / " << x << " = ";
    div1.print(); cout << endl;

    // намиране на сумата, разликата, произведението и
    // частното на цялото число x с рационалнoто число s
    Rat sum2  = x + s;
    Rat sub2  = x - s;
    Rat mult2 = x * s;
    Rat div2  = x / s;

    // извеждане на сумата, разликата, произведението и
    // частното на цялото число x с рационалнoто число s
    cout << x << " + "; s.print(); cout << " = ";
    sum2.print(); cout << endl;
    cout << x << " - "; s.print(); cout << " = ";
    sub2.print(); cout << endl;
    cout << x << " * "; s.print(); cout << " = ";
    mult2.print(); cout << endl;
    cout << x << " / "; s.print(); cout << " = ";
    div2.print(); cout << endl;

    return 0;
}
