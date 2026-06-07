#include "WeightColPoint3.h"

//des/constructors
template<class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(){}

template<class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(const ColPoint3<T, U> p, const V wei):ColPoint3<T, U>(p), weight(wei){}

template<class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(const WeightColPoint3<T, U, V>& other)
{
    setColor(other.getColor());
    weight = other.weight;
}

//operators
template<class T, class U, class V>
WeightColPoint3<T, U, V>& WeightColPoint3<T, U, V>::operator=(const WeightColPoint3<T, U, V>& other)
{
    if (this != &other)
    {
        ColPoint3<T, U>::setColor(other.getColor());
        weight = other.weight;
    }
    return *this;
}
//getters
template<class T, class U, class V>
V WeightColPoint3<T, U, V>::getWeight()const
{
    return weight;
}

//setters
template<class T, class U, class V>
void WeightColPoint3<T, U, V>::setWeight(const V wei)
{
    weight = wei;
}

//funcs
template<class T, class U, class V>
void WeightColPoint3<T, U, V>::printWeightColPoint3()const
{
    ColPoint3<T, U>::printColPoint3();
    std::cout << "Weight: " << weight << std::endl;
}
