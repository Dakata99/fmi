#include "RatNum.h"

RatNum::RatNum(const int num, const int denom)
{
    numerator = num;
    denominator = denom == 0? 1 : denom;
}
RatNum::RatNum(const RatNum& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}

RatNum& RatNum::operator=(const RatNum& other)
{
    if (this != &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

void RatNum::setNum(const int num)
{
    numerator = num;
}
void RatNum::setDenom(const int denom)
{
    denominator = denom == 0? 1 : denom;
}

int RatNum::getNum()const
{
    return numerator;
}
int RatNum::getDenom()const
{
    return denominator;
}

void RatNum::print()const
{
    std::cout << numerator << "/" << denominator << std::endl;
}