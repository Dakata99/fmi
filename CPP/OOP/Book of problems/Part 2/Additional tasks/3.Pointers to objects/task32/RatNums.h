#pragma once
#include "RatNum.h"

class RatNums
{
private:
    RatNum* nums;
    size_t current, max;
public:
    RatNums(const size_t = 1);
    RatNums(const RatNums&);
    ~RatNums();

    RatNums& operator=(const RatNums&);
    double operator[](const size_t);

    void setSize(const size_t);

    friend RatNums merge(const RatNums&, const RatNums&);

    void add(const RatNum&, const size_t);
    void remove(const size_t);

    void print()const;
};

