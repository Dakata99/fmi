#include "Date.h"

//Constructors
Date::Date(const size_t& _day = 1, const size_t& _month = 1, const size_t& _year = 1999) : day(_day), month(_month), year(_year)
{
    if (day > 31) { day = 1; month++; }
    if (month > 12) { month = 1; year++; }
}

//getters
size_t Date::get_day(void) const { return day; }
size_t Date::get_month(void) const { return month; }
size_t Date::get_year(void) const { return year; }

//setters
void Date::set_day(const size_t& day) { this->day = day; }
void Date::set_month(const size_t& month) { this->month = month; }
void Date::set_year(const size_t& year) { this->year = year; }

//Funcs
void Date::print_date(void) const
{
    std::cout << "Date: ";

    if (day < 10)  std::cout << "0" << day << ".";
    else std::cout << day << ".";
    
    if (month < 10) std::cout << "0" << month << ".";
    else std::cout << month << ".";

    std::cout << year << std::endl;
}
