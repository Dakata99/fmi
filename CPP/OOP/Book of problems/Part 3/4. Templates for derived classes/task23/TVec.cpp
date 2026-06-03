#include "TVec.h"

//des/constructors
    template<class T>
    TVec<T>::TVec(const size_t _size)
    {
        if (_size <= 0)
        {
            std::cout << "Invalid size!\n";
            exit(-1);
        }
        size = _size;
        lower = 0;
        upper = size - 1;
        vector = new T[size];
    }
    
    template<class T>
    TVec<T>::TVec(const TVec& other)
    {
        size = other.size;
        vector = new T[size];
        lower = other.lower;
        upper = other.upper;
        for (size_t i = 0; i < size; i++)
        {
            vector[i] = other.vector[i];
        }
    }
    
    template<class T>
    TVec<T>::~TVec()
    {
        delete[]vector;
    }

//operators
    template<class T>
    TVec<T>& TVec<T>::operator=(const TVec& other)
    { 
        if (this != &other)
        {
            delete[]vector;
            size = other.size;
            vector = new T[size];

            for (size_t i = 0; i < size; i++)
            {
                vector[i] = other.vector[i];
            }
            lower = other.lower;
            upper = other.upper;
        }
        return *this;
    }
    
    template<class T>
    T& TVec<T>::operator[](const size_t index)
    {
        if(index < 0 || index > upper - lower)
            std::cout << "Invalid index!\n"; exit(-1);
        
        return vector[index];
    }

//getters
    template<class T>
    size_t TVec<T>::lowerBound()const
    {
        return lower;
    }
    
    template<class T>
    size_t TVec<T>::upperBound()const
    {
        return upper;
    }
    
    template<class T>
    size_t TVec<T>::getSize()const
    {
        return size;
    }
//setters

//funcs