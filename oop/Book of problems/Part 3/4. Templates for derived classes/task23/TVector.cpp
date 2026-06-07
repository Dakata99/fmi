#include "TVector.h"

//des/constructors
    template<class T>
    TVector<T>::TVector(const size_t  low, const size_t up):TVec<T>(up - low + 1)
    {
        TVec<T>::lower = low;
        TVec<T>::upper = up;
    }

//operators;
    template<class T>
    T& TVector<T>::operator[](const size_t index)
    {
        return TVec<T>::operator[](index - TVec<T>::lower);
    }

    