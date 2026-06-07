#pragma once
#include "Criminal.h"
#include "Animation.h"

class CriminalAnimation:public Criminal, public Animation
{
public:
//des/constructors
    CriminalAnimation(const char* = "", const size_t = 1999, const size_t = 0, const char* = "", const size_t = 1999, const char* = "");
    CriminalAnimation(const Criminal&, const Animation&);
    CriminalAnimation(const CriminalAnimation&);
    //~CriminalAnimation();
//operators
    CriminalAnimation& operator=(const CriminalAnimation&);
//getters

//setters

//funcs
    void print()const;
};
