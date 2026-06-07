#include "Polynom.h"
#include <cmath>

Polynom::Polynom(const size_t num, const double X)
{
    x = X;
    max = num + 1;
    coeff = new double[max];
}
Polynom::~Polynom()
{
    delete[]coeff;
}

double Polynom::operator[](const size_t index)const
{
    if (index < 0 || index > max - 1)
    {
        return 0;
    }
    return coeff[index];
}

void Polynom::init()
{
    for (size_t i = 0; i < max; i++)
    {
        double x;
        std::cin >> x;
        coeff[i] = x;
    }
}
void Polynom::setDegree(const size_t deg)
{
    max = deg;
}

double sum(const Polynom& first, const Polynom& second)
{
    double res1 = 0;
    for (size_t i = 0, j = first.max - 1; i < first.max && j > 0; i++, j--)
    {
        res1 += first.coeff[i]*pow(first.x, j);
    }
    res1 += first.coeff[first.max - 1];
    
    double res2 = 0;
    for (size_t i = 0, j = second.max - 1; i < second.max && j > 0; i++, j--)
    {
        res2 += second.coeff[i]*pow(second.x, j);
    }
    res2 += second.coeff[second.max - 1];

    return res1 + res2;
}