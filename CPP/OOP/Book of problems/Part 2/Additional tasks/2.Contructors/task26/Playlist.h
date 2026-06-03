#pragma once
#include "Song.h"

class Playlist
{
private:
    std::string name;
    size_t current, max;
    Song* songs;
public:
    Playlist(const std::string = "", const size_t = 1);
    Playlist(const Playlist&);
    ~Playlist();

    Playlist& operator=(const Playlist&);
    Song& operator[](const size_t);
    Song& operator()(const std::string);

    std::string getName()const;

    void add(const Song&);
    void searchByLength(const size_t, const size_t)const;
    void sortByName();
    void sortByGroup();
    size_t totalLenght()const;

    void print()const;
};
