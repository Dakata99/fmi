#include <iostream.h>

class P
{
private:
    int a;
    double b;

public:
    P(int = 5, double = 2.5);
    ~P();
    void display() const;
};

P::P(int x, double y)
{
    a = x;
    b = y;
}

P::~P()
{
    cout << "~P()\n";
}

void P::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    P *p;
    // заделяне на памет за масив от 5 обекта на клас P
    p = new P[5];
    if(!p)
    {
        cout << "Грешка при заделяне на памет!\n";
        return 1;
    }
    int i;
    // извеждане на масива, заделен динамично
    for(i = 0; i < 5; i++)
        p[i].display();
    // освобождаване на заделената за масива памет
    delete [] p;
    return 0;
}
