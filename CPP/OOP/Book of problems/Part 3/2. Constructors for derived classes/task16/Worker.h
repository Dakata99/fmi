#ifndef _WORKER_H_
#define _WORKER_H_

class Worker
{
private:
    char* name;
    double salaryPerHour;
public:
//des/constructors
    Worker(const char* = "", const double = 0.0);
    Worker(const Worker&);
    ~Worker();

//operators
    Worker& operator=(const Worker&);

//getters
    double getSalaryPerHour()const;

//funcs
    void print()const;
};

#endif