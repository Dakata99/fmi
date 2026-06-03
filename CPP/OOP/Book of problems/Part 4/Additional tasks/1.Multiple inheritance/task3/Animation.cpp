#include "Animation.h"
#include <cstring>

char* Animation::copy(const char* str)
{
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);

    return temp; 
}
//des/constructors
Animation::Animation(const char* _name, const size_t _year, const char* _animator)
    :name(copy(_name)), year(_year), animator(copy(_animator)){}
Animation::Animation(const Animation& other)
{
    name = copy(other.name);
    year = other.year;
    animator = copy(other.animator);
}
Animation::~Animation()
{
    delete[]name;
    delete[]animator;
}
//operators
Animation& Animation::operator=(const Animation& other)
{
    if (this != &other)
    {
        delete[]name;
        name = copy(other.name);

        year = other.year;

        delete[]animator;
        animator = copy(other.animator);
    }
    return *this;
}
//getters
char* Animation::getName()const
{
    return name;
}
size_t Animation::getYear()const
{
    return  year;
}
char* Animation::getAnimator()const
{
    return animator;
}
//setters
void Animation::setName(const char* _name)
{
    name = copy(_name);
}
void Animation::setYear(const size_t _year)
{
    year = _year;
}
void Animation::setAnimator(const char* _animator)
{
    animator = copy(_animator);
}
//funcs
void Animation::print()const
{
    std::cout << "Animation movie with name: " << name << std::endl;
    std::cout << "Year of production: " << year << std::endl;
    std::cout << "Animators name: " << animator << std::endl;
}