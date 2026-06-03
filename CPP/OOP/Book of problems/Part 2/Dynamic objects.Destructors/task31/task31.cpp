#include <iostream>
#include <cstring>

class BankAccount
{
private:
    char* name;
    char* accNum;
    double amount;
public:
    BankAccount():name(nullptr), accNum(nullptr), amount(0.0){}
    BankAccount(const char* name = "", const char* acc = "", const double amount = 0)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->accNum = new char[strlen(acc) + 1];
        strcpy(accNum, acc);

        this->amount = amount;
    }
    BankAccount(const BankAccount& b)
    {
        this->name = new char[strlen(b.getName()) + 1];
        strcpy(this->name, b.getName());
    }
    ~BankAccount()
    {
        delete[]name;
        delete[]accNum;
    }
    
    //getters
    char* getName()const
    {
        return name;
    }
    //funcs
    void print()const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Bank acc: " << accNum << std::endl;
        std::cout << "Amount: " << amount << std::endl;
    }
    void deposit(const double amount)
    {
        this->amount += amount;
    }
    void withdraw(const double amount)
    {
        if (this->amount - amount >= 0)
        {
            this->amount -= amount;
            return;
        }
        std::cout << "Not enough funds!" << std::endl;
        return;
    }
};

void func()
{
    BankAccount b1("Daniel Lyubenov", "a1h3j4kd", 500.0);
    b1.print();
    b1.deposit(1000);
    b1.print();
    b1.withdraw(2000);
    
}

int main()
{
    func();

    return 0;
}