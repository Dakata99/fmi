#ifndef NAME_H_
#define NAME_H_

#include <iostream>

class Time
{
private:
    size_t hours, minutes, seconds;

public:
// Constructors
    Time(const size_t&, const size_t&, const size_t&);
    
// Getters
    size_t get_hours(void) const;
    size_t get_minutes(void) const;
    size_t get_seconds(void) const;

// Setters
    void set_hours(const size_t&);
    void set_minutes(const size_t&);
    void set_seconds(const size_t&);

// Funcs
    void print_time(void) const;
};

#endif
