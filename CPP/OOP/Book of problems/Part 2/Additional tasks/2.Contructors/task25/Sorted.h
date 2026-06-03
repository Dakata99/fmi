#pragma once

class Sorted
{
private:
    int* arr;
    size_t current, max;
    void sort();
public:
    Sorted(const size_t = 1);
    Sorted(const Sorted&);
    ~Sorted();

    Sorted& operator=(const Sorted&);
    int operator[](const size_t);

    size_t size()const;

    bool member(const int)const;
    size_t getTimes(const int)const;
    void add(const int);
    void addBefore(const int, const size_t);
    void addAfter(const int, const size_t);
    void remove(const int);
    void remove(const size_t);
    Sorted intersection(const Sorted&);
    Sorted merge(const Sorted&);
    Sorted difference(const Sorted&);

    void print();
};

