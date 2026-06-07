#include "PersonInfo.h"
#include <cstring>

PersonInfo::PersonInfo(const char* str, int _age)
{
    name = new char[strlen(str) + 1];
    strcpy(name, str);
    age = _age;
}
PersonInfo::PersonInfo(const PersonInfo& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
}
PersonInfo::~PersonInfo()
{
    delete[]name;
}
PersonInfo& PersonInfo::operator=(const PersonInfo& other)
{
    if (this != &other)
    {
        delete[]name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }
    return *this;
}

void PersonInfo::print()const
{
    std::cout << name << " - " << age << std::endl;
}