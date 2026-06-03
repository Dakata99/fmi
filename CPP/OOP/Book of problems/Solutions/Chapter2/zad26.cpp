#include <iostream.h>

class L
{
private:
    int a;
    double b;

public:
    L(int = 5, double = 2.5);
    void display() const;
};

L::L(int x, double y)
{
    a = x;
    b = y;
}

void L::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    L *p;
    p = new L(8);            // заделяне на памет за обекта
    if(!p)                   // проверка дали е заделена памет
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }
    p -> display();          // извеждане на обекта, сочен от p
    delete p;                // освобождаване на паметта
    p = new L(1, 3.5);       // заделяне на памет за нов обект
    if(!p)                   // проверка дали е заделена памет
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }
    p -> display();          // извеждане на обекта, сочен от p
    delete p;                // освобождаване на паметта
    return 0;
}
