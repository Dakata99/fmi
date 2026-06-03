#pragma once
#include "Album.h"

class AlbumOrd:public Album
{
private:
    size_t count;
public:
//des/constructors
    AlbumOrd(const char* = "", const size_t = 1999, const size_t = 0);
    AlbumOrd(const Album&, const size_t = 0);
    AlbumOrd(const AlbumOrd&);
//operators
    AlbumOrd& operator=(const AlbumOrd&);
//getters

//setters

//funcs
    void print()const;
};
