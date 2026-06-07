#pragma once
#include "ColPoint3.h"

template<class T, class U, class V>
class WeightColPoint3:public ColPoint3<T, U>
{
private:
    V weight;
public:
//des/constructors
    WeightColPoint3();
    WeightColPoint3(const ColPoint3<T, U>, const V = 0);
    WeightColPoint3(const WeightColPoint3<T, U, V>&);
//operators
    WeightColPoint3& operator=(const WeightColPoint3<T, U, V>&);
//getters  
    V getWeight()const;
//setters
    void setWeight(const V);
//funcs
    void printWeightColPoint3()const;
};