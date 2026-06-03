#include <iostream.h>

class N
{
private:
    int a;
    double b;

public:
    // конструктор
    N(int = 5, double = 2.5);
    // деструктор
    ~N();
    // член-функция за извеждане на обект
    void display() const;
};

N::N(int x, double y)
{
    a = x;
    b = y;
}

N::~N()
{
    cout << "~N()\n";
}

void N::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    N *p = NULL;
    p = new N(8);               // заделяне на памет за обект

    if(!p)                      // проверка дали памет е заделена
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }
    p -> display();             // извеждане на обекта, сочен от указателя p
    delete p;                   // освобождаване на паметта
    p = new N(1, 3.5);          // заделяне на памет за нов обект
    if(!p)                      // проверка дали памет е заделена
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }
    p -> display();              // извеждане на обекта, сочен от указателя p
    delete p;                    // освобождаване на паметта
    return 0;
}
