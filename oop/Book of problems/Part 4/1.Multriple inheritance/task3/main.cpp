#include <iostream>

#include "Date.h"
#include "Time.h"
#include "DateTime.h"

int main(void)
{
    DateTime d1(Date(3, 12, 1999), Time(23, 60, 60));
    d1.print_date_time();

    DateTime d2(3, 12, 1999, 23, 60, 60);
    d2.print_date_time();

    DateTime d3(21, 11, 8, 4, 35, 12); /* day, month, year, hours, minutes, seconds */
    d3.print_date_time();

    return 0;
}
