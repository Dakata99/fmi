#include "Criminal.h"
#include <cstring>

void Criminal::copy(const char* str)
{
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}
//des/constructors
    Criminal::Criminal(const char* _name, const size_t _year, const size_t _dead)
    {
        copy(_name);

        year = _year;
        dead = _dead;
    }
    Criminal::Criminal(const Criminal& other)
    {
        copy(other.name);
        year = other.year;
        dead = other.dead;
    }
    Criminal::~Criminal()
    {
        delete[]name;
    }
//operators
    Criminal& Criminal::operator=(const Criminal& other)
    {
        if (this != &other)
        {
            delete[]name;
            copy(other.name);
            year = other.year;
            dead = other.dead;
        }
        return *this;
    }
//getters
    char* Criminal::getName()const
    {
        return name;
    }
    size_t Criminal::getYear()const
    {
        return year;
    }
    size_t Criminal::getDead()const
    {
        return dead;
    }
//setters
    void Criminal::setName(const char* _name)
    {
        copy(_name);
    }
    void Criminal::setYear(const size_t _year)
    {
        year = _year;
    }
    void Criminal::setDead(const size_t _dead)
    {
        dead = _dead;
    }
//funcs
    void Criminal::print()const
    {
        std::cout << "Criminal movie with name: " << name << std::endl;
        std::cout << "Year of production: " << year << std::endl;
        std::cout << "Number of dead people in movie: " << dead << std::endl;
    }