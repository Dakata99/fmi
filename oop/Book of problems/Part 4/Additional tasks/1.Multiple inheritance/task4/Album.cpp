#include "Album.h"
#include <cstring>

void Album::copy(const char* str)
{
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}
//des/constructors
Album::Album(const char* _name, const size_t _year)
{
    copy(_name);
    year = _year;
}
Album::Album(const Album& other)
{
    copy(other.name);
    year = other.year;
}
Album::~Album()
{
    delete[]name;
}
//operators
Album& Album::operator=(const Album& other)
{
    if (this != &other)
    {
        delete[]name;
        copy(other.name);
        year = other.year;
    }
    return *this;
}
//getters

//setters

//funcs
void Album::print()const
{
    std::cout << "Name of album: " << name << std::endl;
    std::cout << "Year of album: " << year << std::endl;
}