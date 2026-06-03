#include <iostream.h>

struct complex
{
private:
    double Re, Im;  // реална и имагинерна части
public:

    // създаване на комплексно число
    void create(double x, double y)
    {
        Re = x;
        Im = y;
    }

    // извеждане на комплексно число
    void print() const
    {
        cout << Re << (Im < 0 ? "" : "+") << Im << "i\n";
    }

    // намиране на реалната част на комплексно число
    double get_Re() const
    {
        return Re;
    }

    // намиране на имагинерната част на комплексно число
    double get_Im() const
    {
        return Im;
    }

    // проверка дали комплексно число е равно на 0
    bool IsZero() const
    {
        return (Re == 0) && (Im == 0);
    }

    // събиране на комплексни числа
    complex sum(const complex& c) const
    {
        complex p;
        p.create(Re + c.Re, Im + c.Im);
        return p;
    }

    // изваждане на комплексни числа
    complex sub(const complex& c) const
    {
        complex p;
        p.create(Re - c.Re, Im - c.Im);
        return p;
    }

    // умножение на комплексни числа
    complex mult(const complex& c) const
    {
        complex p;
        p.create(Re*c.Re - Im*c.Im, Re*c.Im + Im*c.Re);
        return p;
    }

    // деление на комплексни числа
    // предполага се, че делителят c
    // е различно от 0 комплексно число
    complex quot(const complex& c) const
    {
        complex p;
        double den = c.Re*c.Re + c.Im*c.Im;
        p.create((Re*c.Re + Im*c.Im)/den, (Im*c.Re - Re*c.Im)/den);
        return p;
    }
};

// намиране на стойността на полинома
complex Horner(int n, complex a[], complex x)
{ 
    complex s = a[0];
    for(int i = 1; i <= n; i++)
        s = s.mult(x).sum(a[i]);
    return s;
}

int main()
{
    complex x, a[10]; 

    // създаване на комплексното число x
    double p, q;
    cout << "Re, Im? ";
    cin >> p >> q;
    x.create(p, q);    

    // въвеждане на степента на полинома
    cout << "n= "; int n; cin >> n;

    // въвеждане на коефициентите на полинома
    for(int i = 0; i <= n; i++)
    { 
        cout << "Re, Im? ";
        cin >> p >> q;
        a[i].create(p, q);
    }

    // намиране и извеждане на стойността на полинома
    Horner(n, a, x).print();
    return 0;
}
