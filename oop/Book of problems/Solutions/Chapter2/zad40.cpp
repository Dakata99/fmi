#include <iostream.h>
#include <math.h>

const int MAX = 20;

class Vector
{
private:
    double x;                       // абсциса
    double y;                       // ордината
    double mag;                     // радиус
    double ang;                     // ъгъл (в радиани)
    char regime;                    // режим:'r' - правоъгълен,
                                    //       'p' - полярен

public:
    // конструктори
    Vector();
    Vector(double, double, char = 'r');
    // функции за достъп
    double xval() const             // намира абсцисата
    {
        return x;
    }
    double yval() const             // намира ординатата
    {
        return y;
    }
    double rval() const             // намира радиуса
    {
        return mag;
    }
    double aval() const             // намира ъгъла
    {
        return ang;
    }

    // мутатор на абсциса
    // по зададени радиус и ъгъл, намира абсцисата
    void set_x(double r, double a)
    { 
        x = r * cos(a);
    }

    // мутатор на ордината
    // по зададени радиус и ъгъл, намира ординатата
    void set_y(double r, double a)
    { 
        y = r * sin(a);
    }

    // мутатор на радиус
    // по зададени абсциса и ордината, намира радиуса
    void set_mag(double x, double y)
    { 
        mag = sqrt(x*x + y*y);
    }

    // мутатор на ъгъл
    // по зададени абсциса и ордината, намира ъгъла
    void set_ang(double x, double y)
    {
        ang = atan2(y, x);
    }

    // мутатор, активиращ полярен режим
    void polar_regime()
    {
        regime = 'p';
    }

    // мутатор, активиращ режим на правоъгълни координати
    void rect_regime()
    { 
        regime = 'r';
    }

    // мутатор на режим и координати
    void set(double, double, char = 'r');
    
    // операторни член-функции за събиране
    // и изваждане на два вектора
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;
    
    // операторни член-функции за умножение
    // на вектор с реално число
    Vector operator*(double) const;
    
    // приятелски дефиниран оператор за
    // умножение на реално число с вектор
    friend Vector operator*(double, const Vector &);
    
    // извеждане на вектор
    void print() const;
};

// конструктор по подразбиране
// задава 0-в вектор и режим на правоъгълни координати
Vector::Vector()
{ 
    x = y = mag = ang = 0.0;
    regime = 'r';
}

// Конструктор с три параметъра
// конструира вектор с правоъгълни координати
// ако режимът, зададен чрез параметъра m е ’r’;
// конструира вектор с полярни координати,
// ако режимът, зададен чрез параметъра m е ’p’
// и 0-в вектор, ако m не е нито ’r’, нито ’p’.
Vector::Vector(double a, double b, char m)
{ 
    set(a, b, m);
}

// мутатор на режим и координати
// Задава вектор с правоъгълни координати,
// ако режимът, указан чрез параметъра m е ’r’;
// задава вектор с полярни координати,
// ако режимът, указан чрез параметъра m е ’p’
// и 0-в вектор, ако m не е нито ’r’, нито ’p’
void Vector::set(double a, double b, char m)
{ 
    regime = m;
    if(m == 'r')
    {
        x = a;
        y = b;
        set_mag(x, y);
        set_ang(x, y);
    }
    else if(m == 'p')
    { 
        mag = a;
        ang = b;
        set_x(a, b);
        set_y(a, b);
    }
    else
    { 
        cout << " Неправилен режим.\n";
        x = y = 0.0;
        regime = 'r';
    }
}

// събиране на два вектора
Vector Vector::operator+(const Vector & b) const
{ 
    Vector r(x + b.x, y + b.y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// изваждане на два вектора
Vector Vector::operator-(const Vector & b) const
{
    Vector r(x - b.x, y - b.y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// умножение на вектор с реално число
Vector Vector::operator*(double n) const
{
    Vector r(n * x, n * y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// функция-приятел за умножение на реално число с вектор
Vector operator*(double n, const Vector & a)
{
    return a * n;
}

// Извеждане на правоъгълните координати на
// вектор,ако режимът е ’r’, или на полярните
// му координати, ако режимът е ’p’.
void Vector::print() const
{
    if(regime == 'r')
    {
        cout << "(x, y) = (" << x << ", " << y << ")\n";
    }
    else //if(regime == 'p')
    {
        cout << "(m, a) = (" << mag << ", " << ang << ")\n";
    }
}

int main()
{
    Vector v[MAX];            // редица от вектори
    int n;                    // дължина на редицата
    do
    {
        cout << "n от 1 до " << MAX  << ": ";
        cin >> n;
    } while(n < 1 || n > MAX);

    // въвеждане на правоъгълните координати
    // на векторите от редицата
    int i;
    for(i = 0; i < n; i++)
    {
        double x, y;
        cout << "Въведете правоъгълните координати на "
             << i << " –тия вектор: ";
        cin >> x >> y;
        v[i].set(x, y);
    }

    // извеждане на редицата от вектори
    for(i = 0; i < n; i++)
        v[i].print();

    // намиране на сумата на векторите от редицата
    Vector S = v[0];
    for(i = 1; i < n; i++)
        S = S + v[i];

    // извеждане на сумата на векторите от редицата
    cout << "Сумата на векторите от редицата е: ";
    S.print();

    // намиране на разликата на векторите от редицата
    Vector R = v[0];
    for(i = 1; i < n; i++)
        R = R - v[i];

    // извеждане на разликата на векторите от редицата
    cout << "Разликата на векторите от редицата е: ";
    R.print();

    // въвеждане на реалното число,
    // с което ще се умножава векторът S
    double t; cout << "t= "; cin >> t;

    // умножение на сумата на векторите с t и извеждане
    cout << "Произведението на сумата на векторите "
            "от редицата с t е: ";
    (S*t).print();

    // умножение на t със сумата на векторите и извеждане
    cout << "Произведението на t със сумата на "
            "векторите от редицата е: ";
    (t*S).print();

    // извеждане на полярните координати на
    // векторите от редицата
    cout << "Векторите от редицата в полярни координати: \n";
    for(i = 0; i < n; i++)
    {
        v[i]. polar_regime();
        v[i].print();
    }
    return 0;
}
