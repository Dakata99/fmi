#include <iostream.h>

class H
{
private:
    int a, b;

public:
    // конструктор с подразбиращи се параметри
    H(int = 1, int = 1);
    // конструктор за присвояване
    H(H const &);
    // член-функция за извеждане на член-данните на класа
    void display() const;
};

H::H(int x, int y)
{
    a = x;
    b = y;
}

H::H(H const &r)
{
    a = r.a;
    b = r.b;
}

void H::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    // създаване на  обектите e1, e2 и e3 чрез
    // конструктора с подразбиращи се параметри
    H e1, e2(6), e3(3, 8);

    // извеждане на обектите
    e1.display();
    e2.display();
    e3.display();

    // създаване на обект e4 чрез конструктора за присвояване
    H e4 = e3;

    // извеждане на обекта e4
    e4.display();
    return 0;
}
