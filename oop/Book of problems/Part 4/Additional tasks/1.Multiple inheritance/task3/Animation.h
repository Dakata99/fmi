#pragma once

class Animation
{
private:
    char* name;
    size_t year;
    char* animator;
    char* copy(const char*);
public:
//des/constructors
    Animation(const char* = "", const size_t = 1999, const char* = "");
    Animation(const Animation&);
    ~Animation();
//operators
    Animation& operator=(const Animation&);
//getters
    char* getName()const;
    size_t getYear()const;
    char* getAnimator()const;
//setters
    void setName(const char*);
    void setYear(const size_t);
    void setAnimator(const char*);
//funcs
    void print()const;
};