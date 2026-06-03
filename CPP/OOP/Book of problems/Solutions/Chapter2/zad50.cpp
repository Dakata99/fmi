#include <iostream.h>

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
    cout << "~BankAccount()\n";
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

template <class T>
void swap(T & x, T & y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    //// а)
    int a = 4, b = 9;
    swap(a, b);    // шаблонна процедура swap(int&, int&)
    cout << a << " " << b << endl;

    //// б)
    double p = 1.5, q = -5.6;
    swap(p, q);     // шаблонна процедура swap(double&, double&)
    cout << p << " " << q << endl;

    //// в)
    char c = 'a', d = 'd';
    swap(c, d);    // шаблонна процедура swap(char&, char&)
    cout << c << " " << d << endl;

    //// г)
    BankAccount bacc_1("Йордан Димитров","jd100", 1500),
        bacc_2("Симеон Петров", "sp504", 2000);
    swap(bacc_1, bacc_2); // шаблонна процедура swap(BankAccount&, BankAccount&)
    bacc_1.print(); bacc_2.print();
    return 0;
}
