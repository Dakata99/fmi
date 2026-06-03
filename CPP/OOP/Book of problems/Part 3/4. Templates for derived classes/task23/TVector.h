#pragma once

#include "TVec.h"

template<class T>
class TVector:public TVec<T>
{
public:
//des/constructors
    TVector(const size_t  = 0, const size_t = 0);

//operators;
    T& operator[](const size_t);
//getters
    
//setters

//funcs

};