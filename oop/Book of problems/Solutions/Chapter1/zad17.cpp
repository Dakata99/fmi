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

int main()
{
    complex c1, c2; 

    // създаване на комплексното число c1
    double a, b;
    cout << "Re, Im? "; cin >> a >> b;
    c1.create(a, b);    

    // създаване на комплексното число     c2
    cout << "Re, Im? "; cin >> a >> b;
    c2.create(a, b);         

    // намиране на c1+c2 и извеждане
    c1.sum(c2).print();    
    // намиране на c1-c2 и извеждане 
    c1.sub(c2).print();
    // намиране на c1*c2 и извеждане
    c1.mult(c2).print();
    // намиране на c1/c2 и извеждане

    if(!c2.IsZero())
        c1.quot(c2).print();
    else 
        cout << "Комплексното число c2 е равно на 0.";
    return 0;
}
