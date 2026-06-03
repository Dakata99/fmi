#include "AlbumClassic.h"
#include <cstring>

//des/constructors
AlbumClassic::AlbumClassic(const char* _name, const size_t _year, const char* _dir):Album(_name, _year)
{
    dirigent = new char[strlen(_dir) + 1];
    strcpy(dirigent, _dir);
}
AlbumClassic::AlbumClassic(const Album& other, const char* _dir):Album(other)
{
    dirigent = new char[strlen(_dir) + 1];
    strcpy(dirigent, _dir);
}
AlbumClassic::AlbumClassic(const AlbumClassic& other):Album(other.name, other.year)
{
    dirigent = new char[strlen(other.dirigent) + 1];
    strcpy(dirigent, other.dirigent);
}
//operators
AlbumClassic& AlbumClassic::operator=(const AlbumClassic& other)
{
    if (this != &other)
    {
        Album(other.name, other.year);
        dirigent = new char[strlen(other.dirigent) + 1];
        strcpy(dirigent, other.dirigent);
    }
    return *this;
}
//getters

//setters

//funcs
void AlbumClassic::print()const
{
    std::cout << "Classic album--------------------------------\n";
    Album::print();
    std::cout << "Name of dirigend: " << dirigent << std::endl;
    std::cout << "---------------------------------------------\n";
}