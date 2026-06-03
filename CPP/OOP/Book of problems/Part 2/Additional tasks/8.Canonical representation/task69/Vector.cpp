#include "Vector.h"
#include <assert.h>

void Vector::copy(const Vector& other)
{
    size = other.size;
    capacity = other.capacity;
    vector = new double[capacity];
    for (size_t i = 0; i < size; i++)
    {
        vector[i] = other.vector[i];
    }
}
void Vector::fill(const size_t count, Vector& vec)
{
    for (size_t i = 0; i < count; i++)
    {
        vec.add(0);
    }
}

Vector::Vector(const size_t _size)
{
    size = 0;
    capacity = size;
    vector = new double[capacity];
}
Vector::Vector(const Vector& other)
{
    copy(other);
}
Vector::~Vector()
{
    delete[]vector;
}

Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        delete[]vector;
        copy(other);
    }
    return *this;
}

Vector Vector::operator+(Vector& other)
{
    if (size < other.size)
    {
        fill(other.size - size, *this);
    }
    else if(other.size < size)
    {
        fill(size - other.size, other);
    }
    Vector temp;
    for (size_t i = 0; i < size; i++)
    {
        temp.add(vector[i] + other.vector[i]);
    }
    return temp;
}
Vector Vector::operator-(Vector& other)
{
    if (size < other.size)
    {
        fill(other.size - size, *this);
    }
    else if(other.size < size)
    {
        fill(size - other.size, other);
    }
    Vector temp;
    for (size_t i = 0; i < size; i++)
    {
        temp.add(vector[i] - other.vector[i]);
    }
    return temp;
}
Vector Vector::operator*(const double k)
{
    Vector temp;
    for (size_t i = 0; i < size; i++)
    {
        temp.add(vector[i] * k);
    }
    return temp;
}
double Vector::operator*(Vector& other)
{
    if (size < other.size)
    {
        fill(other.size - size, *this);
    }
    else if(other.size < size)
    {
        fill(size - other.size, other);
    }
    double result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result += vector[i]*other.vector[i];
    }
    return result;
}
Vector Vector::operator/(const double k)
{
    for (size_t i = 0; i < size; i++)
    {
        vector[i] /= k;
    }
    return *this;
}
Vector Vector::operator++(int)
{
    for (size_t i = 0; i < size; i++)
    {
        vector[i]++;
    }
    return *this;
}
Vector Vector::operator--(int)
{
    for (size_t i = 0; i < size; i++)
    {
        vector[i]--;
    }
    return *this;
}
bool Vector::operator==(const Vector& other)const
{
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (vector[i] != other.vector[i])
        {
            return false;
        }
    }
    return true;
}
bool Vector::operator!=(const Vector& other)const
{
    return !(*this == other);
}
double Vector::operator[](const size_t index)const
{
    assert(index >= 1 && index <= size);
    return vector[index - 1];
}
Vector Vector::operator<<(const size_t count)
{
    return *this;
}
Vector Vector::operator>>(const size_t count)
{
    return *this;
}
size_t Vector::operator()()const
{
    return size;
}
bool Vector::operator||(const Vector& other)const 
{
    return false;
}
bool Vector::operator^(Vector& other)const
{
    Vector temp = *this;
    return temp * (other) == 0;
}

void Vector::add(const double element)
{
    if (size + 1 >= capacity)
    {
        capacity += 2;
        double* temp = new double[size];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = vector[i];
        }
        delete[]vector;
        vector = new double[capacity];
        for (size_t i = 0; i < size; i++)
        {
            vector[i] = temp[i];
        }
        delete[]temp;
    }
    vector[size++] = element;
}

void Vector::print()const
{
    std::cout << "( ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << ")\n";
}