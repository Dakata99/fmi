#include <iostream.h>

class G
{
private:
    int a, b;

public:
    // конструктор с подразбиращи се параметри
    G(int = 0, int = 0);
    // извеждане на член-данните на класа
    void display() const;
};

G::G(int x, int y)
{
    a = x;
    b = y;
}

void G::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    G e1, e2(1), e3(1, 2);
    e1.display();
    e2.display();
    e3.display();
    return 0;
}
