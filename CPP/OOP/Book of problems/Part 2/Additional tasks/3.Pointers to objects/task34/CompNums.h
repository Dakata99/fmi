#pragma once
#include "Complex.h"

class CompNums
{
private:
    Complex* arr;
    size_t current, max;
public:
    CompNums(const size_t = 1);
    ~CompNums();

    Complex operator[](const size_t);

    friend CompNums merge(CompNums&, CompNums&);

    void setSize(const size_t);
    void init();

    void print()const;
};
