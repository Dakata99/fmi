#pragma once

class Criminal
{
private:
    char* name;
    size_t year, dead;
    void copy(const char*);
public:
//des/constructors
    Criminal(const char* = "", const size_t = 1999, const size_t = 0);
    Criminal(const Criminal&);
    ~Criminal();
//operators
    Criminal& operator=(const Criminal&);
//getters
    char* getName()const;
    size_t getYear()const;
    size_t getDead()const;
//setters
    void setName(const char*);
    void setYear(const size_t);
    void setDead(const size_t);
//funcs
    void print()const;
};