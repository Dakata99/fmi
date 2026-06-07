#include "Matrix.h"
#include <cassert>

void Matrix::copy(double** mat, const size_t rows, const size_t columns)
{
    this->rows = rows;
    this->columns = columns;
    matrix = new double*[this->rows];
    for (size_t i = 0; i < this->rows; i++)
    {
        matrix[i] = new double[this->columns];
    }
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->columns; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
}

Matrix::Matrix(const size_t rows, const size_t columns)
{
    this->rows = rows;
    this->columns = columns;
    matrix = new double*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
}
Matrix::Matrix(double** mat, const size_t rows, const size_t columns)
{
    copy(mat, rows, columns);
}
Matrix::Matrix(const Matrix& other)
{
    copy(other.matrix, other.rows, other.columns);
}
Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete[]matrix[i];
        }
        delete[]matrix;
        copy(other.matrix, other.rows, other.columns);
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
    assert(rows == other.rows && columns == other.columns);
    Matrix temp(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator-(const Matrix& other)
{
    assert(rows == other.rows && columns == other.columns);
    Matrix temp(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*(const Matrix& other)
{
    assert(columns == other.rows);
    Matrix temp(this->rows, other.columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < other.columns; j++)
        {
            double res = 0;
            for (size_t k = 0; k < rows; k++)
            {
                res += matrix[i][k]*other.matrix[k][j];
            }
            temp.matrix[i][j] = res;
        }
    }
    return temp;
}
Matrix Matrix::operator*(const double k)
{
    Matrix temp(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            temp.matrix[i][j] = matrix[i][j] * k;
        }
    }
    return temp;
}
double Matrix::operator()(const size_t indexI, const size_t indexJ)
{
    assert(indexI >= 1 && indexI <= rows && indexJ >= 1 && indexJ <= columns);
    return matrix[indexI - 1][indexJ - 1];
}
double* Matrix::operator[](const size_t line)
{
    assert(line >= 1 && line <= rows);
    return matrix[line - 1];
}
bool Matrix::operator==(const Matrix& other)const
{
    assert(rows == other.rows && columns == other.columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (matrix[i][j] != other.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix& other)const
{
    return !(*this == other);
}
//? Matrix::operator/(const Matrix& other);
double Matrix::operator()()const
{
    assert(rows == columns);
    double result = 0;
    for (size_t i = 0; i < rows; i++)
    {
        /* code */
    }
    return result;
}

Matrix inverse(const Matrix& other)
{
    return Matrix(3, 3);
}

size_t Matrix::getRows()const
{
    return rows;
}
size_t Matrix::getColumns()const
{
    return columns;
}

void Matrix::init()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            double x;
            std::cin >> x;
            matrix[i][j] = x;
        }
    }
}

void Matrix::change(const double data, const size_t indexI, const size_t indexJ)
{
    assert(indexI >= 1 && indexI <= rows && indexJ >= 1 && indexJ <= columns);
    matrix[indexI- 1][indexJ - 1] = data;
}

void Matrix::print()const
{
    std::cout << "Matrix is:\n";
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}