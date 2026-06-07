#pragma once

class Vector
{
private:
    double* vector;
    size_t size, capacity;
    void copy(const Vector&);
    void fill(const size_t, Vector&);
public:
    Vector(const size_t = 1);
    Vector(const Vector&);
    ~Vector();

    Vector& operator=(const Vector&);

    Vector operator+(Vector&);
    Vector operator-(Vector&);
    Vector operator*(const double);
    double operator*(Vector&);
    Vector operator/(const double);
    Vector operator++(int);
    Vector operator--(int);
    bool operator==(const Vector&)const;
    bool operator!=(const Vector&)const;
    double operator[](const size_t)const;
    Vector operator<<(const size_t);
    Vector operator>>(const size_t);
    size_t operator()()const;
    bool operator||(const Vector&)const;
    bool operator^(Vector&)const;

    void add(const double);

    void print()const;
};
