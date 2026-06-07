#include "Reader.h"
#include <cstring>

char* Reader::copy(const char* str)
{
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);

    return temp;
}
Reader::Reader(const char* _name, const char* addr, const char* readerNum)
{
    name = copy(_name);
    address = copy(addr);
    reader_number = copy(readerNum);

}
Reader::Reader(const Reader& other)
{
    name = copy(other.name);
    address = copy(other.address);
    reader_number = copy(other.reader_number);
}
Reader::~Reader()
{
    delete[]name;
    delete[]address;
    delete[]reader_number;
}

Reader& Reader::operator=(const Reader& other)
{
    if (this != &other)
    {
        delete[]name;
        delete[]address;
        delete[]reader_number;
        
        name = copy(other.name);
        address = copy(other.address);
        reader_number = copy(other.reader_number);
    }
    return *this;
}

void Reader::print()const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Reader number: " << reader_number << std::endl;
}