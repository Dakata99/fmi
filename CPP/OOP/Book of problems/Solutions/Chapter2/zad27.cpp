#include <iostream.h>

class M
{
private:
    int a;
    double b;

public:
    M(int = 5, double = 2.5);
    void set(int, double);
    void display() const;
};

// конструктор
M::M(int x, double y)
{
    a = x;
    b = y;
}

// мутатор
void M::set(int x, double y)
{
    a = x;
    b = y;
}

// член-функция за извеждане на обект на класа
void M::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    M *p;
    // заделяне на памет за масив от 5 обекта
    p = new M[5];
    if(!p)
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }

    int i;
    // извеждане на масива, заделен динамично
    for(i = 0; i < 5; i++)
        p[i].display();
    
    // променяне на компонентите на обектите
    // на масива, заделен динамично
    for(i = 0; i < 5; i++)
        p[i].set(i, i+1.5);
    
    // извеждане на масива
    for(i = 0; i < 5; i++)
        p[i].display();
    
    // освобождаване на заделената за масива памет
    delete [] p;
    return 0;
}
