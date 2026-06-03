#pragma once
#include "PersonalData.h"
#include "Class.h"

class Teacher:public PersonalData, public Class
{

public:
    Teacher(const PersonalData, const Class);
    
    void printTeacher()const;
};

