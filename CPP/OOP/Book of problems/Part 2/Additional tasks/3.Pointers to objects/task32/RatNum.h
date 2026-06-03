#pragma once

class RatNum
{
private:
    int numerator, denominator;
public:
    RatNum(const int = 0, const int = 1);
    RatNum(const RatNum&);

    RatNum& operator=(const RatNum&);

    void setNum(const int);
    void setDenom(const int);

    int getNum()const;
    int getDenom()const;

    void print()const;
};
