#include "RatNums.h"

RatNums::RatNums(const size_t size)
{
    current = 0;
    max = size;
    nums = new RatNum[max];
}
RatNums::RatNums(const RatNums& other)
{
    current = other.current;
    max = other.max;
    nums = other.nums;
}
RatNums::~RatNums()
{
    delete[]nums;
}

RatNums& RatNums::operator=(const RatNums& other)
{
    if (this != &other)
    {
        delete[]nums;
        current = other.current;
        max = other.max;
        nums = other.nums;
    }
    return *this;
}
double RatNums::operator[](const size_t index)
{
    if (index > current - 1)
    {
        return 0;
    }
    return (double)nums[index].getNum()/nums[index].getDenom();
}

void RatNums::setSize(const size_t size)
{
    max = size;
}

RatNums merge(const RatNums& first, const RatNums& second)
{
    RatNums temp;
    temp.max = first.max + second.max;
    temp.nums = new RatNum[temp.max];
    for (size_t i = 0; i < first.current; i++)
    {
        temp.add(first.nums[i], i);
    }
    for (size_t i = first.current; i < first.current + second.current; i++)
    {
        temp.add(second.nums[i - first.current], i);
    }
    
    return temp;
}

void RatNums::add(const RatNum& number, const size_t index)
{
    if (index > max - 1)
    {
        return;
    }
    current++;
    nums[index] = number;
}
void RatNums::remove(const size_t index)
{
    if (index < 0 || index > current - 1)
    {
        return;
    }
    
    RatNum* temp = new RatNum[current - 1];
    for (size_t i = 0; i < index; i++)
    {
        temp[i] = nums[i];
    }
    for (size_t i = index + 1; i < current; i++)
    {
        temp[i - 1] = nums[i];
    }
    delete[]nums;
    nums = temp;
    current--;    
}

void RatNums::print()const
{
    std::cout << "Rational numbers are:\n";
    for (size_t i = 0; i < current; i++)
    {
        nums[i].print();
    }
    std::cout << std::endl;
}