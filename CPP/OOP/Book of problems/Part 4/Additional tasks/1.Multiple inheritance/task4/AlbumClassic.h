#pragma once
#include "Album.h"

class AlbumClassic:public Album
{
private:
    char* dirigent;
public:
//des/constructors
    AlbumClassic(const char* = "", const size_t = 1999, const char* = "");
    AlbumClassic(const Album&, const char* = "");
    AlbumClassic(const AlbumClassic&);

//operators
    AlbumClassic& operator=(const AlbumClassic&);
//getters

//setters

//funcs
    void print()const;
};
