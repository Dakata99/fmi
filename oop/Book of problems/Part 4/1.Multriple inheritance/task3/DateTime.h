#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_

#include <iostream>
#include <cstring>

#include "Date.h"
#include "Time.h"

class DateTime : public Date, public Time
{
private:
    char* date_time;

public:
    DateTime(const size_t&, const size_t&, const size_t&, const size_t&, const size_t&, const size_t&);
    DateTime(const Date&, const Time&);

    void print_date_time(void) const;
};

#endif
