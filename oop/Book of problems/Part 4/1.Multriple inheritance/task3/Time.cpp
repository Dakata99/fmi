#include "Time.h"

// Constructors
Time::Time(const size_t& _hours = 0, const size_t& _mins = 0, const size_t& _secs = 0)
    				: hours(_hours), minutes(_mins), seconds(_secs)
{
    if (seconds >= 60) { seconds -= 60; minutes++; }
    if (minutes >= 60) { minutes -= 60; hours++; }
    if (hours >= 24) { hours -= 24; }
}

// Getters
size_t Time::get_hours(void) const { return hours; }
size_t Time::get_minutes(void) const { return minutes; }
size_t Time::get_seconds(void) const { return seconds; }

// Setters
void Time::set_hours(const size_t& hours) { this->hours = hours; }
void Time::set_minutes(const size_t&) { this->minutes = minutes; }
void Time::set_seconds(const size_t& seconds) { this->seconds = seconds; }

// Funcs
void Time::print_time(void) const
{
    std::cout << "Time: ";
    
    if (hours < 10)
        std::cout << "0" << hours << ":";
    else
        std::cout << hours << ":";
    
    if (minutes < 10)
        std::cout << "0" << minutes << ":";
    else
        std::cout << minutes << ":";
    
    if (seconds < 10) 
    	std::cout << "0" << seconds << std::endl;
    else 
    	std::cout << seconds << std::endl;
}

