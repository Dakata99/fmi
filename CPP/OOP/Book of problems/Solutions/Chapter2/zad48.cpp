#include <iostream.h>
#include <string.h>
#include <stdlib.h>

const int MAX = 100;         // максимална дължина на име и
const int MAXSIZE = 100;
char temp[MAXSIZE];          // помощен низ


// номер на банкова сметка
class BankAccount
{
private:
    char* name;              // име на клиент
    char* accountnum;        // номер на банкова сметка
    double balance;          // баланс

public:
    // канонично представяне
    // конструктор с подразбиращи се параметри
    BankAccount(const char* = "", const char* = "",
                double = 0.0);
    // конструктор за присвояване
    BankAccount(const BankAccount&);
    // деструктор
    ~BankAccount();
    // операторна функция за присвояване
    BankAccount& operator=(const BankAccount&);

    // извеждане на банкова сметка
    void print() const;
    // внасяне на сума в банкова сметка
    void put_in(double);
    // теглене на сума от банкова сметка
    void draw(double);
};

// конструктор с подразбиращи се параметри
BankAccount::BankAccount(const char* n, const char* an, double b)
{
    name = new char[strlen(n)+1];
    if(!name)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(name, n);
    accountnum = new char[strlen(an)+1];
    if(!accountnum)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(accountnum, an);
    balance = b;
}

// конструктор за присвояване
BankAccount::BankAccount(const BankAccount& b)
{ 
    name = new char[strlen(b.name)+1];
    if(!name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(name, b.name);
    accountnum = new char[strlen(b.accountnum)+1];
    if(!accountnum)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(accountnum, b.accountnum);
    balance = b.balance;
}

// деструктор
BankAccount::~BankAccount()
{ 
    delete [] accountnum;
    delete [] name;
}

// операторна функция за присвояване
BankAccount& BankAccount::operator=(const BankAccount& b)
{ 
    if(this != &b)
    { 
        delete [] accountnum;
        delete [] name;
        name = new char[strlen(b.name)+1];
        if(!name)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(name, b.name);
        accountnum = new char[strlen(b.accountnum)+1];
        if(!accountnum)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(accountnum, b.accountnum);
        balance = b.balance;
    }
    return *this;
}

// извеждане на сметка на клиент
void BankAccount::print() const
{ 
    cout << "Име на клиент: " << name << endl;
    cout << "Номер на сметка: " << accountnum << endl;
    cout << "Баланс: " << balance << endl;
}

// внасяне на пари в банкова сметка
void BankAccount::put_in(double cash)
{ 
    if(cash >= 0)
        balance = balance + cash;
    else
        cout << "Некоректен опит за внасяне на пари.\n";
}

// теглене на пари от банкова сметка
void BankAccount::draw(double cash)
{ 
    if(cash < 0)
    {
        cout << "Некоректен опит за теглене на пари.\n ";
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
    cout << "Име на клиент: ";
    char n1[MAX]; cin.getline(n1, MAX);
    cout << "Номер на сметка: ";
    char an1[MAX]; cin.getline(an1, MAX);
    double b1;
    cout << "Баланс: "; cin >> b1;

    cin.ignore();        // прескачане на знака за край на ред
    // създаване на банкова сметка
    BankAccount x(n1, an1, b1);
    // извеждане на банковата сметка
    x.print();
    // внасяне на сума в банкова сметка
    // и извеждане на сметката
    x.put_in(200);
    x.print();
    cout << "Име на клиент: ";
    char n2[MAX]; cin.getline(n2, MAX);
    cout << "Номер на сметка: ";
    char an2[MAX]; cin.getline(an2, MAX);
    double b2;
    cout << "Баланс: "; cin >> b2;
    cin.ignore();        // прескачане на знака за край на ред
    // създаване на нова банкова сметка
    BankAccount y(n2, an2, b2);
    // извеждане на банковата сметка
    y.print();
    // теглене на сума от банковата сметка
    // и извеждане на сметката
    y.draw(250);
    y.print();
    return 0;
}
