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

// проверява дали две комплексни числа са равни
bool equal(const complex& x, const complex& y)
{ 
    return x.get_Re() == y.get_Re() &&
           x.get_Im() == y.get_Im();
}

// решаване на системата
void complex_system(const complex& a, const complex& b,
                    const complex& c, const complex& d,
                    const complex& e, const complex& f )
{
    complex det = a.mult(d).sub(c.mult(b)), zero;
    zero.create(0, 0);
    if(equal(det, zero))
    {
        if(equal(b.mult(f), d.mult(e)))
            cout << "Системата има безброй много решения.\n";
        else 
            cout << "Системата няма решение.\n";
    }
    else
    { 
        complex x, y;
        x = e.mult(d).sub(b.mult(f)).quot(det);
        y = a.mult(f).sub(c.mult(e)).quot(det);
        x.print();
        y.print();
    }
}

int main()
{
    // дефиниране на коефициентите на системата
    complex a, b, c, d, e, f;
    // създаване на комплексните числа,
    // явяващи се коефициенти на системата
    a.create(1,2); b.create(-1,4);
    c.create(1,3); d.create(1,4);
    e.create(3,6); f.create(3,6);
    // решаване на системата
    complex_system(a, b, c, d, e, f);
    return 0;
}
