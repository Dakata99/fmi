#pragma once

class Indexed
{
private:
    int* arr;
    size_t current, max;
public:
    Indexed(const size_t = 1);
    Indexed(const Indexed&);
    ~Indexed();

    Indexed& operator=(const Indexed&);
    int operator[](const size_t);

    size_t size()const;

    bool member(const int)const;
    size_t getTimes(const int)const;
    void add(const int);
    void addBefore(const int, const size_t);
    void addAfter(const int, const size_t);
    void remove(const int);
    void remove(const size_t);
    Indexed intersection(const Indexed&);
    Indexed merge(const Indexed&);
    Indexed difference(const Indexed&);

    void print()const;
};

