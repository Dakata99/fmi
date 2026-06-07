#include "Date.h"

Date::Date(const size_t _day, const size_t _month, const size_t _year)
    :day(_day), month(_month), year(_year){}

Date::Date(const Date& other):day(other.day), month(other.month), year(other.year){}
Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

void Date::print()const
{
    std::cout << day << "." << month << "." << year << std::endl;
}