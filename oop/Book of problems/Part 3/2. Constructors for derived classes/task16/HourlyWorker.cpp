#include "HourlyWorker.h"
#include <cstring>

//des/constructors
HourlyWorker::HourlyWorker(const char* _name, const double _amount, const char* _duty, const size_t _hours):Worker(_name, _amount)
{
    duty = new char[strlen(_duty) + 1];
    strcpy(duty, _duty);

    hours = _hours;
}
HourlyWorker::HourlyWorker(const HourlyWorker& other):Worker(other)
{
    duty = new char[strlen(other.duty) + 1];
    strcpy(duty, other.duty);

    hours = other.hours;
}
HourlyWorker::~HourlyWorker()
{
    delete[]duty;
}

//operators
HourlyWorker& HourlyWorker::operator=(const HourlyWorker& other)
{
    if (this != &other)
    {
        Worker::operator=(other);

        delete[]duty;
        duty = new char[strlen(other.duty) + 1];
        strcpy(duty, other.duty);

        hours = other.hours;
    }
    return *this;
}

//getters
char* HourlyWorker::getDuty()const
{
    return duty;
}
size_t HourlyWorker::getHours()const
{
    return hours;
}

//setters
void HourlyWorker::setDuty(const char* _duty)
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
void HourlyWorker::setHours(const size_t _hours)
{
    hours = _hours;
}

//funcs
double HourlyWorker::getSalary()const
{
    double result, x = getSalaryPerHour();
        if (hours <= 40)
        {
            result = hours*x;
        }
        else if (hours <= 60)
        {
            result = hours*x + (hours - 40)*1.5*x;
        }
        else
        {
            result = 40*x + 20*1.5*x + (hours - 60)*2*x;
        }
        
        return result;
}
void HourlyWorker::print()const
{
    Worker::print();
    std::cout << "Duty: " << duty << std::endl;
    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Total salary: " << getSalary() << std::endl;
}