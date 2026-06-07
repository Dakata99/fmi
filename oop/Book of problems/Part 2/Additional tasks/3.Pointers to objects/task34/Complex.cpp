#include "Complex.h"

Complex::Complex(const int r, const int im):real(r), imaginary(im){}

void Complex::setReal(const int r)
{
    real = r;
}
void Complex::setImaginary(const int im)
{
    imaginary = im;
}

int Complex::getReal()const
{
    return real;
}
int Complex::getImaginary()const
{
    return imaginary;
}

void Complex::print()const
{
    std::cout << real << " + i" << imaginary << std::endl;
}