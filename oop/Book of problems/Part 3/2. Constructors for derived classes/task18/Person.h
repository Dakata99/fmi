#ifndef _PERSON_H_
#define _PERSON_H_

#include "Date.h"

class Person
{
private:
    char* name;
    Date dob;
public:
//des/constructors
    Person(const char* = "", const Date& = Date());
    Person(const Person&);
    ~Person();

//operators
    Person& operator=(const Person&);

//getters
    const char* getName()const;
    Date getDOB()const;

//funcs
    void print()const;
};

#endif
