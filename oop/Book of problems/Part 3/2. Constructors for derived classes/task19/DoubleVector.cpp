#include "DoubleVector.h"

//des/constructors
    DoubleVector::DoubleVector(const size_t  low, const size_t up):DoubleVec(up - low + 1)
    {
        lower = low;
        upper = up;
    }

//operators;
    double& DoubleVector::operator[](const size_t index)
    {
        return DoubleVec::operator[](index - lower);
    }