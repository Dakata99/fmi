#include <iostream.h>

class Fraction
{
private:
    int n, d;

public:
    // конструктор
    Fraction(int x, int y);
    // функции за достъп до компонентите
    int getN() const;
    int getD() const;
    // декларация на функция приятел на класа
    friend bool IsFraction(const Fraction& obj);
};

Fraction::Fraction(int x, int y)
{
    n = x;
    d = y;
}

int Fraction::getN() const
{ 
    return n;
}

int Fraction::getD() const
{ 
    return d;
}

// външна функция, приятел на класа Fraction
bool IsFraction(const Fraction& obj)
{ 
    return obj.n % obj.d != 0;
}

int main()
{ 
    // дефиниране на обект на класа Fraction
    int a, b;
    do
    { 
        cout << "a, b (b различно от 0): ";
        cin >> a >> b;
    } while(b == 0);

    Fraction f(a, b);
    // проверка дали първото цяло число на обекта f1
    // не се дели на второто цяло число
    if(IsFraction(f))
        cout << f.getN() << " не се дели на " << f.getD() << endl;
    else
        cout << f.getN() << " се дели на " << f.getD() << endl;
    return 0;
}
