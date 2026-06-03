#include "Worker.h"
#include <cstring>

Worker::Worker(const char* _name, const double _amount)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);

    salaryPerHour = _amount;
}
Worker::Worker(const Worker& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    salaryPerHour = other.salaryPerHour;
}
Worker::~Worker()
{
    delete[]name;
}

Worker& Worker::operator=(const Worker& other)
{
    if (this != &other)
    {
        delete[]name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        salaryPerHour = other.salaryPerHour; 
    }

    return *this;
}

double Worker::getSalaryPerHour()const
{
    return salaryPerHour;
}
void Worker::print()const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Salary per hour: " << salaryPerHour << std::endl;
}
