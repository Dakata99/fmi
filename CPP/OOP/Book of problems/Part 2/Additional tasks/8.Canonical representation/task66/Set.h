#pragma once

class Set
{
private:
    int* data;
    size_t current, max;
public:
    Set();
    Set(const size_t num);
    Set(const Set& other);
    ~Set();

    Set& operator=(const Set& other);

    Set operator+(const Set&);
    Set operator+(const int);
    Set operator-(const Set&);
    Set operator-(const int);
    Set operator*(const Set&);
    Set operator^(const Set&);
    bool operator()(const int);
    bool operator==(const Set&);
    bool operator!=(const Set&);
    bool operator>(const Set&);
    bool operator<(const Set&);
    Set operator~();

    bool isInSet(const int _data)const;

    void add(const int _data);
    void remove(const int _data);
    
    size_t size()const;
    Set cut(const Set& other);
    Set merge(const Set& other);
    Set difference(const Set& other);
    Set symetricDiff(const Set& other);

    void print()const;
};