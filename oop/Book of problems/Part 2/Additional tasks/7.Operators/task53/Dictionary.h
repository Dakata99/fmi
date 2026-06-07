#pragma once
#include <string>

struct Pair
{
    std::string word, value;
};

class Dictionary
{
private:
    Pair* words;
    size_t current, max;
    void sort();
    //char* copy(const std::string);
public:
    Dictionary(const size_t = 1);
    ~Dictionary();

    void operator[](const std::string);

    void add(const std::string, const std::string);

    void print();
};
