#include "DoubleVec.h"

//des/constructors
    DoubleVec::DoubleVec(const size_t _size)
    {
        if (_size <= 0)
        {
            std::cout << "Invalid size!\n";
            exit(-1);
        }
        size = _size;
        lower = 0;
        upper = size - 1;
        vector = new double[size];
    }
    DoubleVec::DoubleVec(const DoubleVec& other)
    {
        size = other.size;
        vector = new double[size];
        lower = other.lower;
        upper = other.upper;
        for (size_t i = 0; i < size; i++)
        {
            vector[i] = other.vector[i];
        }
    }
    DoubleVec::~DoubleVec()
    {
        delete[]vector;
    }

//operators
    DoubleVec& DoubleVec::operator=(const DoubleVec& other)
    {
        if (this != &other)
        {
            delete[]vector;
            size = other.size;
            vector = new double[size];

            for (size_t i = 0; i < size; i++)
            {
                vector[i] = other.vector[i];
            }
            lower = other.lower;
            upper = other.upper;
        }
        return *this;
    }
    double& DoubleVec::operator[](const size_t index)
    {
        if(index < 0 || index > upper - lower)
            std::cout << "Invalid index!\n"; exit(-1);
        
        return vector[index];
    }

//getters
    size_t DoubleVec::lowerBound()const
    {
        return lower;
    }
    size_t DoubleVec::upperBound()const
    {
        return upper;
    }
    size_t DoubleVec::getSize()const
    {
        return size;
    }
//setters

//funcs