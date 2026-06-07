#pragma once

class Polynom
{
private:
    double x;
    double* coeff;
    size_t max;
public:
    Polynom(const size_t = 1, const double = 0);
    ~Polynom();

    double operator[](const size_t index)const;

    void init();
    void setDegree(const size_t);

    friend double sum(const Polynom&, const Polynom&);
};
