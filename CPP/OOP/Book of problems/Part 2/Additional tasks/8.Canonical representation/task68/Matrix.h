#pragma once

class Matrix
{
private:
    double** matrix;
    size_t rows, columns;
    void copy(double**, const size_t, const size_t);
public:
    Matrix(const size_t = 1, const size_t  = 1);
    Matrix(double** = nullptr, const size_t = 0, const size_t = 0);
    Matrix(const Matrix&);
    ~Matrix();

    Matrix& operator=(const Matrix&);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const double);
    double operator()(const size_t, const size_t);
    double* operator[](const size_t);
    bool operator==(const Matrix&)const;
    bool operator!=(const Matrix&)const;
    //? operator/(const Matrix&);
    double operator()()const;

    friend Matrix inverse(const Matrix&);

    size_t getRows()const;
    size_t getColumns()const;

    void init();

    void change(const double, const size_t, const size_t);

    void print()const;
};
