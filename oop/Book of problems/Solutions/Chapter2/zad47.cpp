#include <iostream.h>
#include <iomanip.h>
#include <math.h>

class Expr
{ 
public:
    // конструктор
    Expr(int, double);
    // Член-функция за намиране на S1
    double Ex1() const;
    // Член-функция за намиране на S2
    double Ex2() const;
    // Член-функция за намиране на S3
    double Ex3() const;

private:
    int n;
    double x;
};

Expr::Expr(int m, double y)
{ 
    n = m;
    x = y;
}

double Expr::Ex1() const
{ 
    double S = 1, x1 = 1;
    for(int i = 1; i <= n; i++)
    { 
        x1 = x1*x/i;
        S += x1;
    }
    return S;
}

double Expr::Ex2() const
{ 
    double S = 1, x1 = 1;
    for(int i = 1; i <= 2*n; i = i+2)
    { 
        x1 = -x1*x*x/(i*(i+1));
        S += x1;
    }
    return S;
}

double Expr::Ex3() const
{ 
    double S = x, x1 = x;
    for(int i = 2; i <= 2*n; i = i+2)
    { 
        x1 = -x1*x*x/(i*(i+1));
        S += x1;
    }
    return S;
}

int main()
{
    int n;
    // въвеждане на стойност на n
    do
    {
        cout << "n= ";
        cin >> n;
    } while (n < 0);

    double x;
    // въвеждане на стойност на x
    do
    {
        cout << "x= ";
        cin >> x;
    } while(fabs(x) > 1);

    // дефиниране на обект t на класа Expr
    Expr t(n, x);

    cout << setiosflags(ios::fixed) << setprecision(6);
    // дефиниране на указател към
    // член-функция на класа Expr
    double (Expr::*ptr)() const;
    char ch;
    cout << "Изберете функция, чиято стойност \n"
         << "желаете да бъде пресметната: \n"
         <<  "exp --> a \n"
             "cos --> b \n"
             "sin --> c \n";
    cin >> ch;

    // избор на член-функция за изпълнение
    switch (ch)
    { 
    case 'a': ptr = &Expr::Ex1;
        cout << "exp(" << x << ")= ";
        break;
    case 'b': ptr = &Expr::Ex2;
        cout << "cos(" << x << ")= ";
        break;
    case 'c': ptr = &Expr::Ex3;
        cout << "sin(" << x << ")= ";
    }

    // намиране и извеждане на стойността
    // на съответната член-функция
    cout << (t.*ptr)() << endl;
    return 0;
}
