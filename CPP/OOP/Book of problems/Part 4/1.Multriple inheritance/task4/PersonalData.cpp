#include <cstring>
#include "PersonalData.h"

char* PersonalData::copy(const char* str)
{
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);

    return temp;
}
//des/constructors
PersonalData::PersonalData(const char* _name, const size_t _birthYear)
{
    name = copy(_name);

    birthYear = _birthYear;
}
PersonalData::PersonalData(const PersonalData& other)
{
    name = copy(other.name);

    birthYear = other.birthYear;
}
PersonalData::~PersonalData()
{
    delete[]name;
}

//operators
PersonalData& PersonalData::operator=(const PersonalData& other)
{
    if (this != &other)
    {
        delete[]name;
        name = copy(other.name);

        birthYear = other.birthYear;
    }
    return *this;
}

//getters
char* PersonalData::getName()const
{
    return name;
}
size_t PersonalData::getYear()const
{
    return birthYear;
}

//setters
void PersonalData::setName(const char* _name)
{
    name = copy(_name);
}
void PersonalData::setYear(const size_t _birthYear)
{
    birthYear = _birthYear;
}

//funcs
void PersonalData::printPD()const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Year of birth: " << birthYear << std::endl;
}