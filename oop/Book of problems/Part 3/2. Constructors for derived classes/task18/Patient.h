#pragma once
#include "Person.h"

class Patient:public Person
{
private:
    Person p;
    size_t visits;
public:
//des/constructors 
    Patient(const char* = "", const Date& = Date(), const size_t = 0);
    Patient(const Person&, const size_t);
    Patient(const Patient&);

//operators
    Patient& operator=(const Patient&);

//getters
    Person getPerson()const;
    size_t getVisits()const;

//setters

//funcs
    void print()const;
};