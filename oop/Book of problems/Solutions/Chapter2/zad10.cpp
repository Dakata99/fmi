#include <iostream.h>

class F
{
private:
    int a, b;

public:
    // конструктор по подразбиране
    F();
    // конструктор с един параметър
    F(int);
    // конструктор с два параметъра
    F(int, int);
    // извеждане на член-данните на класа
    void display() const;
};

F::F()
{
    a = b = 0;
}

F::F(int x)
{
    a = x;
}

F::F(int x, int y)
{
    a = x;
    b = y;
}

void F::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    F e1, e2(1), e3(1, 2);
    e1.display();
    e2.display();
    e3.display();
    return 0;
}
