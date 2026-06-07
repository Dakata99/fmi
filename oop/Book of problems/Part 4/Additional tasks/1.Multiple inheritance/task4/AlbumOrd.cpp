#include "AlbumOrd.h"
#include <cstring>

//des/constructors
AlbumOrd::AlbumOrd(const char* _name, const size_t _year, const size_t _count)
                    :Album(_name, _year), count(_count){}
AlbumOrd::AlbumOrd(const Album& other, const size_t _count):Album(other), count(_count){}
AlbumOrd::AlbumOrd(const AlbumOrd& other):Album(other.name, other.year), count(other.count){}
//operators
AlbumOrd& AlbumOrd::operator=(const AlbumOrd& other)
{
    if (this != &other)
    {
        Album(other.name, other.year);
        count = other.count;
    }
    return *this;
}
//getters

//setters

//funcs
void AlbumOrd::print()const
{
    std::cout << "Ordinary album--------------------------------\n";
    Album::print();
    std::cout << "Number of horists: " << count << std::endl;
    std::cout << "----------------------------------------------\n";
}