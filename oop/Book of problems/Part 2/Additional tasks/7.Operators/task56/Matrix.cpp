#include "Matrix.h"

Matrix::Matrix(const size_t n, const size_t first, const size_t last)
{
    size = n;
    left = first - 1;
    right = last - 1;
    mat = new double*[size];
    for (size_t i = 0; i < size; i++)
    {
        mat[i] = new double[size];
    }
}
Matrix::~Matrix()
{
    for (size_t i = 0; i < size; i++)
    {
        delete[]mat[i];
    }
    delete[]mat;
}

void Matrix::init()
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            double x;
            std::cin >> x;
            mat[i][j] = x;
        }
    }
}

void Matrix::change(const double data, const size_t _i, const size_t _j)
{
    if (_i < 1 || _j > size)
    {
        std::cout << "Invalid indexes!\n";
        return;
    }
    mat[_i - 1][_j - 1] = data;
}

void Matrix::print()const
{
    std::cout << "Matrix is:\n";
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}