#pragma once

template<class T>
class TVec
{
private:
    T* vector;
    size_t size;
protected:
    size_t upper, lower;
public:
//des/constructors
    TVec(const size_t = 1);
    TVec(const TVec&);
    ~TVec();
    
//operators
    TVec& operator=(const TVec&);
    T& operator[](const size_t);
//getters
    size_t lowerBound()const;
    size_t upperBound()const;
    size_t getSize()const;
//setters


//funcs

};