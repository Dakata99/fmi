#pragma once
#include "Playlist.h"

class Playlists
{
private:
    Playlist* plists;
    size_t current, max;
public:
    Playlists(const size_t = 1);
    Playlists(const Playlists&);
    ~Playlists();

    Playlists& operator=(const Playlists&);

    void add(const Playlist&);

    void print()const;
};
