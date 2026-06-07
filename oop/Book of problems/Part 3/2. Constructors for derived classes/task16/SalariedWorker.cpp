#include "SalariedWorker.h"
#include <cstring>

//des/constructors
SalariedWorker::SalariedWorker(const char* _name, const double _amount, const char* _duty, const size_t _hours):Worker(_name, _amount)
{
    duty = new char[strlen(_duty) + 1];
    strcpy(duty, _duty);
    hours = _hours;
}
SalariedWorker::SalariedWorker(const SalariedWorker& other):Worker(other)
{
    duty = new char[strlen(other.duty) + 1];
    strcpy(duty, other.duty);
    hours = other.hours;
}
SalariedWorker::~SalariedWorker()
{
    delete[]duty;
}

//operators
SalariedWorker& SalariedWorker::operator=(const SalariedWorker& other)
{
    if (this != &other)
    {
        Worker::operator=(other);

        duty = new char[strlen(other.duty) + 1];
        strcpy(duty, other.duty);
        hours = other.hours;
    }
    return *this;
}

//getters
char* SalariedWorker::getDuty()const
{
    return duty;
}
size_t SalariedWorker::getHours()const
{
    return hours;
}

//setters
void SalariedWorker::setDuty(const char* _duty)
{
    if (duty != nullptr)
    {
        delete[]duty;
        duty = new char[strlen(_duty) + 1];
        strcpy(duty, _duty);
    }
    else
    {
        duty = new char[strlen(_duty) + 1];
        strcpy(duty, _duty);
    }
}
void SalariedWorker::setHours(const size_t _hours)
{
    hours = _hours;
}

//func
double SalariedWorker::getSalary()const
{
    return hours*getSalaryPerHour();
}
void SalariedWorker::print()const
{
    Worker::print();
    std::cout << "Duty: " << duty << std::endl;
    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Total salary: " << getSalary() << std::endl;
}