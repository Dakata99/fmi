#pragma once

class DoubleVec
{
private:
    double* vector;
    size_t size;
protected:
    size_t upper, lower;
public:
//des/constructors
    DoubleVec(const size_t = 1);
    DoubleVec(const DoubleVec&);
    ~DoubleVec();

//operators
    DoubleVec& operator=(const DoubleVec&);
    double& operator[](const size_t);
//getters
    size_t lowerBound()const;
    size_t upperBound()const;
    size_t getSize()const;
//setters

//funcs

};