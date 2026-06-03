#include <iostream>
#include <cstring>

struct Pair
{
    char* word1, *word2;
};

class Dictionary
{
private:
    Pair pairs[5];
    size_t current = 0;
public:
    void add(const char*, const char*);
    void remove(const char*);
    void search(const char*);
    void translate(const char*);
};

void Dictionary::add(const char* word1, const char* word2)
{
    if (current + 1 == 5)
    {
        std::cout << "Max number reached - cannot add more words!\n";
        return;
    }
    pairs[current].word1 = new char[strlen(word1) + 1];
    strcpy(pairs[current].word1, word1);

    pairs[current].word2 = new char[strlen(word2) + 1];
    strcpy(pairs[current].word2, word2);

    current++;
}

void Dictionary::remove(const char* word)
{
    for (size_t i = 0; i < current; i++)
    {
        if ((strcmp(pairs[i].word1, word) == 0) || (strcmp(pairs[i].word2, word) == 0))
        {
            pairs[i].word1 = new char[1];
            strcmp(pairs[i].word1, "");

            pairs[i].word2 = new char[1];
            strcmp(pairs[i].word2, "");
        }
    }
}

void Dictionary::search(const char* word)
{
    for (size_t i = 0; i < current; i++)
    {
        if (!(strcmp(pairs[i].word1, word) == 0 || strcmp(pairs[i].word2, word) == 0))
        {
            std::cout << "Word is not in dictionary\n";
            return;
        }
    }
    std::cout << "Found\n";
}

void Dictionary::translate(const char* word)
{
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(pairs[i].word1, word) == 0)
        {
            std::cout << pairs[i].word2 << std::endl;
            return;
        }
        else if (strcmp(pairs[i].word2, word) == 0)
        {
            std::cout << pairs[i].word1 << std::endl;
            return;
        }
    }
    std::cout << "Word is not in dictionary\n";
    return;
}

int main()
{
    Dictionary d;
    d.add("dog", "куче");

    d.translate("dog");
    d.remove("dog");
    d.search("dog");

    d.add("cat", "котка");
    d.translate("cat");
    d.search("cat");


    return 0;
}

