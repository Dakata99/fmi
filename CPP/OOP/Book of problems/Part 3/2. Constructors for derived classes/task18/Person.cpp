#include <cstring>
#include "Person.h"

//des/constructors
Person::Person(const char* _name, const Date& _date):dob(_date)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
Person::Person(const Person& other):dob(other.dob)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}
Person::~Person()
{
    delete[]name;
}

//operators;
Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        dob = Date(other.dob);
        delete[]name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

//getters
const char* Person::getName()const
{
    return name;
}
Date Person::getDOB()const
{
    return dob;
}

//funcs
void Person::print()const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Date: "; dob.print();
}