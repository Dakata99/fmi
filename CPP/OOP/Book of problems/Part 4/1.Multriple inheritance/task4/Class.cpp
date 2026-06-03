#include "Class.h"

//des/constructors
Class::Class(const size_t _year, const size_t _count, const size_t _id):year(_year), count(_count), id(_id){}
Class::Class(const Class& other)
    :year(other.year), count(other.count), id(other.id){}
//operators
Class& Class::operator=(const Class& other)
{
    if (this != &other)
    {
        year = other.year;
        count = other.count;
        id = other.id;
    }
    return *this;
}
//getters
size_t Class::getYear()const
{
    return year;
}
size_t Class::getCount()const
{
    return count;
}
size_t Class::getID()const
{
    return id;
}
//setters
void Class::setYear(const size_t _year)
{
    year = _year;
}
void Class::setCount(const size_t _count)
{
    count = _count;
}
void Class::setID(const size_t _id)
{
    id = _id;
}
//funcs
void Class::printClass()const
{
    std::cout << "Year of class: " << year << std::endl;
    std::cout << "Number of students: " << count << std::endl;
    std::cout << "ID of class: " << id << std::endl;
}