#pragma once

#include "Person.h"
#include "Patient.h"

const size_t MAX_SIZE = 100;

class Doctor:public Person
{
private:
    Patient* pats;
    static size_t currentPatient;
    size_t registered;
public: 
//des/constructors
    Doctor(const char* = "", const Date = Date(), const size_t  = 5);
    ~Doctor();

//operators

//funcs
    void add(const Patient&);
    size_t average()const;
    void printLimit(const size_t limit)const;
    void print()const;
};