#include <iostream>
#include "Date.cpp"
#include "Person.cpp"
#include "Patient.cpp"
#include "Doctor.cpp"


void func()
{
    size_t n;
    do
    {
        std::cout << "Enter number of patients: ";std::cin >> n;
    } while (n < 0 || n > 100);

    Date DOB_Petrov(5, 10, 1975);

    Doctor d1("Petrov", DOB_Petrov, n);
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Name of patient: ";
        char name[20];std::cin >> name;
        
        int day, month, year;
        std::cout << "Enter day: ";std::cin >> day;
        std::cout << "Enter month: "; std::cin >> month;
        std::cout << "Enter year: "; std::cin >> year;
        
        Date dat(day, month, year);
        
        int visits;
        std::cout << "Enter visits: ";std::cin >> visits;
        
        Patient p(name, dat, visits);
        d1.add(p);
    }
    std::cout << "Average visits: " << d1.average() << std::endl;
    d1.printLimit(3);
    //d1.print();
}

int main()
{
    func();

    return 0;
}