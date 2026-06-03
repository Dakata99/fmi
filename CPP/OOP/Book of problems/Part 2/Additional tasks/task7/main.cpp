#include <iostream>
#include <cstring>

class Card
{
private:
    char* title, *author;
    size_t count;
public:
    void init(const char*, const char*, const size_t);
    void print()const;
};

void Card::init(const char* _title, const char* _author, const size_t _count)
{
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);

    author = new char[strlen(_author) + 1];
    strcpy(author, _author);

    count = _count;
}
void Card::print()const
{
    std::cout << "Title of book: " << title << std::endl;
    std::cout << "Author of book: " << author << std::endl;
    std::cout << "Number of copies: " << count << std::endl;
}

int main()
{
    Card a;
    a.init("The magicians", "Daniel Lyubenov", 50);
    a.print();

    return 0;
}
