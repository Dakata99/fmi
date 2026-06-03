#include "Patient.h"

//des/constructors
Patient::Patient(const char* name, const Date& date, const size_t _visits):p(name, date), visits(_visits){}
Patient::Patient(const Person& other, const size_t _visits):p(other), visits(_visits){}
Patient::Patient(const Patient& other):p(other.p), visits(other.visits){}

//operators
Patient& Patient::operator=(const Patient& other)
{
    if (this != &other)
    {
        p = other.p;
        visits = other.visits;
    }
    return *this;
}
//getters
Person Patient::getPerson()const
{
    return p;
}
size_t Patient::getVisits()const
{
    return visits;
}

//funcs
void Patient::print()const
{
    p.print();
    std::cout << "Number of visits: " << visits << std::endl;
}