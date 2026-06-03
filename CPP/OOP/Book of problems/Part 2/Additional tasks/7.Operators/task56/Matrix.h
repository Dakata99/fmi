#pragma once

class Matrix
{
private:
    double** mat;
    size_t size, left, right;
public:
    Matrix(const size_t = 1, const size_t = 0, const size_t  = 1);
    ~Matrix();

    void init();
    //void add(const double);
    //void add(const double, const size_t);
    void change(const double, const size_t, const size_t);

    void print()const;
};
