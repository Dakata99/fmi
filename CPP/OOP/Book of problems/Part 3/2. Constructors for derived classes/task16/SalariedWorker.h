#ifndef _SALARIEDWORKER_H_
#define _SALARIEDWORKER_H_

#include "Worker.h"

class SalariedWorker:public Worker
{
private:
    char* duty;
    size_t hours;
public:
//des/constructors
    SalariedWorker(const char* = "", const double = 0.0, const char* = "", const size_t = 0);
    SalariedWorker(const SalariedWorker&);
    ~SalariedWorker();

//operators
    SalariedWorker& operator=(const SalariedWorker&);

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