#include "Teacher.h"

//des/constructors
Teacher::Teacher(const PersonalData p, const Class c):PersonalData(p), Class(c){}
//operators

//getters

//setters

//funcs
void Teacher::printTeacher()const
{
    PersonalData::printPD();
    Class::printClass();
}