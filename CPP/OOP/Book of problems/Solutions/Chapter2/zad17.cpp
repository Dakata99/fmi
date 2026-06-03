#include <iostream.h>
#include <string.h>

const int MAX_NAME = 24;
const int MAX_NUM = 16;

class BankAccount
{
private:
    char name[MAX_NAME];            // име на клиент
    char accountnum[MAX_NUM];       // номер на банкова сметка
    double balance;                 // баланс

public:
    // конструктор
    BankAccount(const char * = "", const char * = "0", double = 0.0);
    // член-функция, която извежда банкова сметка
    void print() const;
    // член-функция, която реализира внасяне
    // на сума в банкова сметка
    void put_in(double);
    // член-функция, която реализира теглене
    // на сума от банкова сметка
    void draw(double);
};

BankAccount::BankAccount(const char * cl, const char * n, double b)
{
    strncpy(name, cl, MAX_NAME-1);
    name[MAX_NAME-1] = '\0';
    strncpy(accountnum, n, MAX_NUM);
    accountnum[MAX_NUM] = '\0';
    balance = b;
}

void BankAccount::print() const
{
    cout << "Име на клиент: " << name << endl;
    cout << "Номер на сметка: " << accountnum << endl;
    cout << "Баланс: " << balance << endl;
}

void BankAccount::put_in(double cash)
{
    if(cash >= 0)
        balance = balance + cash;
    else
        cout << "Некоректен опит за внасяне на пари.\n";
}

void BankAccount::draw(double cash)
{
    if(cash < 0)
    {
        cout << " Некоректен опит за теглене на пари.\n ";
    }
    else
    {
        if(cash <= balance)
            balance = balance - cash;
        else
            cout << "Сметката не съдържа достатъчно пари.\n";
    }
}

int main()
{
    // създаване на банкови сметки x, y и z и
    // извеждане на банковите сметки
    BankAccount x;
    x.print();
    BankAccount y("Peter Ivanov", "PIvanov1923", 6123.65);
    y.print();
    BankAccount z = BankAccount("Georgi Petrov", "GPetrov3917", 819.60);
    z.print();

    // внасяне на сума в банкова сметка
    // x и извеждане на сметката
    x.put_in(20);
    x.print();
    
    // теглене на суми от банкови сметки y и z
    // и извеждане на сметките
    y.draw(250);
    y.print();
    z.draw(50);
    z.print();
    return 0;
}
