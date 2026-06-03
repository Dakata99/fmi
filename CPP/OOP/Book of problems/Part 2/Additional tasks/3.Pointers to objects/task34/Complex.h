#pragma once

class Complex
{
private:
    int real, imaginary;
public:
    Complex(const int = 0, const int = 0);

    void setReal(const int);
    void setImaginary(const int);

    int getReal()const;
    int getImaginary()const;

    void print()const;
};

