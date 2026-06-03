#include "CarOwner.h"

//des/constructors
CarOwner::CarOwner(const PersonalData p, const Car c):PersonalData(p), Car(c){}
//operators

//getters

//setters

//funcs
void CarOwner::printCarOwner()const
{
    PersonalData::printPD();
    Car::printCar();
}