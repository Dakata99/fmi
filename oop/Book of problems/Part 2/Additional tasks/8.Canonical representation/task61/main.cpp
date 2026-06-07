#include <iostream>
#include <cstring>

class StringType
{
private:
    char* string;
public:
    StringType(const char* = "");
    StringType(const StringType&);
    ~StringType();

    StringType& operator=(const StringType&);

    friend std::ostream& operator<<(std::ostream&, const StringType&);

    void print()const;
};

StringType::StringType(const char* str)
{
    string = new char[strlen(str) + 1];
    strcpy(string, str);
}
StringType::StringType(const StringType& other)
{
    string = new char[strlen(other.string) + 1];
    strcpy(string, other.string);   
}
StringType::~StringType()
{
    delete[]string;
}

StringType& StringType::operator=(const StringType& other)
{
    if (this != &other)
    {
        string = new char[strlen(other.string) + 1];
        strcpy(string, other.string); 
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const StringType& str)
{
    os << str.string << std::endl;
    return os;
}

void StringType::print()const
{
    std::cout << string << std::endl;
}

int main()
{
    StringType s("asdasfasd");
    StringType s2 = s;
    s.print();
    s2.print();

    std::cout << StringType("dasdas") << std::endl;

    return 0;
}