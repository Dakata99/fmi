#pragma once

class Album
{
protected:
    char* name;
    size_t year;
    void copy(const char*);
public:
//des/constructors
    Album(const char* = "", const size_t = 1999);
    Album(const Album&);
    ~Album();
//operators
    Album& operator=(const Album&);
//getters

//setters

//funcs
    void print()const;
};