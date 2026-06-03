#pragma once

class Bag
{
private:
    int* arr;
    size_t current, max;
public:
//des/constructors
    Bag(const size_t);
    Bag(const Bag&);
    ~Bag();

//operators
    Bag& operator=(const Bag&);

//getters
    size_t size()const;
//setters

//funcs
    bool isInBag(const int)const;
    size_t getTimes(const int)const;
    void add(const int);
    void remove(const int);
    Bag cut(const Bag&);
    Bag merge(const Bag&);
    Bag diff(Bag&);
    Bag symDiff(Bag&);

    void print()const;
};
