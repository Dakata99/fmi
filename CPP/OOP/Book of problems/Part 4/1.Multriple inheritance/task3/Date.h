#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date
{
private:
    size_t day, month, year;

public:
//Constructors
    Date(const size_t&, const size_t&, const size_t&);

//Getters
    size_t get_day(void) const;
    size_t get_month(void) const;
    size_t get_year(void) const;

//Setters
    void set_day(const size_t&);
    void set_month(const size_t&);
    void set_year(const size_t&);

//Funcs
    void print_date(void) const;
};

#endif
