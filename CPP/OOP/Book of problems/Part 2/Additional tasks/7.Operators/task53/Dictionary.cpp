#include "Dictionary.h"
#include <cstring>

void Dictionary::sort()
{
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < current; j++)
        {
            if (words[i].word <= words[j].word)
            {
                std::swap(words[i].word, words[j].word);
                std::swap(words[i].value, words[j].value);
            }
        }
    }
}

Dictionary::Dictionary(const size_t num)
{
    current = 0;
    max = num;
    words = new Pair[max];
}
Dictionary::~Dictionary()
{
    delete[]words;
}

void Dictionary::operator[](const std::string str) //not sure if it has to be like this
{
    for (size_t i = 0; i < current; i++)
    {
        if (words[i].word == str)
        {
            std::cout << words[i].word << " - " << words[i].value << std::endl;
        }
    }
}

void Dictionary::add(const std::string word, const std::string val)
{
    if (current >= max)
    {
        max += 2;
        Pair* temp = new Pair[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i].word = words[i].word;
            temp[i].value = words[i].value;
        }
        delete[]words;
        words = new Pair[max];
        for (size_t i = 0; i < current; i++)
        {
            words[i].word = temp[i].word;
            words[i].value = temp[i].value;
        }
        delete[]temp;
    }
    words[current].word = word;
    words[current].value = val;
    current++;
    sort();
}

void Dictionary::print()
{
    sort();
    for (size_t i = 0; i < current; i++)
    {
        std::cout << words[i].word << " - " << words[i].value << std::endl;
    }
}