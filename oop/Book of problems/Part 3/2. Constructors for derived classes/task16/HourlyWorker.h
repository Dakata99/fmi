#ifndef _HOURLYWORKER_H_
#define _HOURLYWORKER_H_

#include "Worker.h"

class HourlyWorker:public Worker
{
private:
    char* duty;
    size_t hours;
public:
//des/constructors
    HourlyWorker(const char* = "", const double = 0.0, const char* = "", const size_t = 0);
    HourlyWorker(const HourlyWorker&);
    ~HourlyWorker();

//operators
    HourlyWorker& operator=(const HourlyWorker&);

//getters
    char* getDuty()const;
    size_t getHours()const;

//setters
    void setDuty(const char*);
    void setHours(const size_t);

//func
    double getSalary()const;
    void print()const;
};

#endif