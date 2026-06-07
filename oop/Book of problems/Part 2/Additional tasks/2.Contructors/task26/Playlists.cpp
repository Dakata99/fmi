#include "Playlists.h"

Playlists::Playlists(const size_t num)
{
    current = 0;
    max = num;
    plists = new Playlist[max];
}
Playlists::Playlists(const Playlists& other)
{
    current = other.current;
    max = other.max;
    plists = new Playlist[max];
    for (size_t i = 0; i < current; i++)
    {
        plists[i] = other.plists[i];
    }
}
Playlists::~Playlists()
{
    delete[]plists;
}

Playlists& Playlists::operator=(const Playlists& other)
{
    if (this != &other)
    {
        delete[]plists;
        current = other.current;
        max = other.max;
        plists = new Playlist[max];
        for (size_t i = 0; i < current; i++)
        {
            plists[i] = other.plists[i];
        }
    }
    return *this;
}

void Playlists::add(const Playlist& other)
{
    if (current >= max - 1)
    {
        max++;
        Playlist* temp = new Playlist[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = plists[i];
        }
        delete[]plists;
        plists = new Playlist[max];
        for (size_t i = 0; i < current; i++)
        {
            plists[i] = temp[i];
        }
        delete[]temp;
    }
    plists[current++] = other;
}

void Playlists::print()const
{
    for (size_t i = 0; i < current; i++)
    {
        std::cout << i << ") " << plists[i].getName() << " ---------------------\n";
        plists[i].print();
    }
}