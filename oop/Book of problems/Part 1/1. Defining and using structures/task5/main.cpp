#include <iostream>
#include <string>

struct Person
{
    std::string firstName, lastName;
};

struct Client
{
    Person person;
    double amount;
};

void init_person(Person& p)
{
    std::cin >> p.firstName;
    std::cin >> p.lastName;
}
void print_person(const Person& p)
{
    std::cout << "First name: " << p.firstName << std::endl;
    std::cout << "Last name: " << p.lastName << std::endl;
}

void init_client(Client& c)
{
    init_person(c.person);
    std::cin >> c.amount;
}
void print_client(const Client& c)
{
    print_person(c.person);
    std::cout << "Amount: " << c.amount << std::endl;
}

int main()
{
    size_t n;
    std::cout << "Enter number of clients: "; std::cin >> n;
    
    Client* cts = new Client[n];
    for (size_t i = 0; i < n; i++)
        init_client(cts[i]);   
    
    for(size_t i = 0; i < n; i++)
        print_client(cts[i]);

    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += cts[i].amount;

    std::cout << "Total amount: " << sum << std::endl;
    
    delete[]cts;

    return 0;
}

