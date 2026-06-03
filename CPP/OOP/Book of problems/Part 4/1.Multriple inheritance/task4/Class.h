#pragma once

class Class
{
private:
    size_t year, count, id;
public:
//des/constructors
    Class(const size_t = 0, const size_t = 0, const size_t = 0);
    Class(const Class&);
//operators
    Class& operator=(const Class&);
//getters
    size_t getYear()const;
    size_t getCount()const;
    size_t getID()const;
//setters
    void setYear(const size_t = 0);
    void setCount(const size_t = 0);
    void setID(const size_t = 0);
//funcs
    void printClass()const;
};
