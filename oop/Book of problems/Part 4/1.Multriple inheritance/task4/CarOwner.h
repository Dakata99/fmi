#pragma once
#include "PersonalData.h"
#include "Car.h"

class CarOwner:public PersonalData, public Car
{
public:
//des/constructors
    CarOwner(const PersonalData, const Car);
//operators
    
//getters

//setters

//funcs
    void printCarOwner()const;
};

