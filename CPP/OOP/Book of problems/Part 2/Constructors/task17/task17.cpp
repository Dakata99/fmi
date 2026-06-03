#include <iostream>

const int MAX_NAME = 24;
const int MAX_BANK = 16;

class BankAccount
{
private:
    char name[MAX_NAME];
    char bank[MAX_BANK];
    double amount;
public:
    BankAccount(const char* name = "", const char* bank = "", const double& amount = 0)
    {
        this->amount = amount;
    }
    void init()
    {
        std::cin >> name >> bank >> amount;
    }
    void print()const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "BankAcc: " << bank << std::endl;
        std::cout << "Amount: " << amount << std::endl;
    }
    void withdraw(const double& amount)
    {
        if (this->amount - amount >= 0)
        {
            this->amount -= amount;
            return;
        }
        return;
    }
    void deposit(const double& amount)
    {
        this->amount += amount;
    }
};

void func()
{
    BankAccount a1;
    a1.init();
    a1.print();
    a1.withdraw(1000);
    a1.print();
    a1.deposit(5000);
    a1.print();
}

int main()
{
    func();

    return 0;
}