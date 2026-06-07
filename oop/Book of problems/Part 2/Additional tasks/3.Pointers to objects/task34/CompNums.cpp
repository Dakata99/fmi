#include "CompNums.h"
#include <iostream>

CompNums::CompNums(const size_t size)
{
    current = 0;
    max = size;
    arr = new Complex[max];
}
CompNums::~CompNums()
{
    delete[]arr;
}

Complex CompNums::operator[](const size_t index)
{
    if (index < 0 || index > current)
    {
        return Complex(0, 0);
    }
    current++;
    return arr[index];
}

CompNums merge(CompNums& first, CompNums& second)
{
    CompNums temp(first.current + second.current);
    temp.current = first.current + second.current;
    for (size_t i = 0; i < first.current; i++)
    {
        temp.arr[i] = first.arr[i];
    }
    for (size_t i = first.current; i < first.current + second.current; i++)
    {
        temp.arr[i] = second.arr[i - first.current];
    }
    
    return temp;
}

void CompNums::setSize(const size_t size)
{
    max = size;
}
void CompNums::init()
{
    while(current < max)
    {
        int x;
        std::cin >> x;
        arr[current].setReal(x);
        std::cin >> x;
        arr[current].setImaginary(x);
        current++;
    }
}
void CompNums::print()const
{
    std::cout << "Complex numbers are:\n";
    for (size_t i = 0; i < current; i++)
    {
        arr[i].print();
    }
    std::cout << std::endl;
}