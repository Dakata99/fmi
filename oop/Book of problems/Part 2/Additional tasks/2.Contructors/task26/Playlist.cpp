#pragma once
#include "Playlist.h"

Playlist::Playlist(const std::string _name, const size_t num)
{
    name = _name;
    current = 0;
    max = num;
    songs = new Song[max];
}
Playlist::Playlist(const Playlist& other)
{
    name = other.name;
    current = other.current;
    max = other.max;
    songs = new Song[max];
    for (size_t i = 0; i < current; i++)
    {
        songs[i] = other.songs[i];
    }
}
Playlist::~Playlist()
{
    delete[]songs;
}

Playlist& Playlist::operator=(const Playlist& other)
{
    if (this != &other)
    {
        delete[]songs;
        name = other.name;
        current = other.current;
        max = other.current;
        songs = new Song[max];
        for (size_t i = 0; i < current; i++)
        {
            songs[i] = other.songs[i];
        }
    }
    return *this;
}
Song& Playlist::operator[](const size_t index)
{
    if (index >= current - 1)
    {
        return songs[0];
    }
    return songs[index];
}
Song& Playlist::operator()(const std::string name)
{
    for (size_t i = 0; i < current; i++)
    {
        if (songs[i].getName() == name)
        {
            return songs[i];
        }
    }
    return songs[0];
}

std::string Playlist::getName()const
{
    return name;
}

void Playlist::add(const Song& song)
{
    if (current >= max - 1)
    {
        max++;
        Song* temp = new Song[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = songs[i];
        }
        delete[]songs;
        songs = new Song[max];
        for (size_t i = 0; i < current; i++)
        {
            songs[i] = temp[i];
        }
        delete[]temp;
    }
    songs[current++] = song;
}
void Playlist::searchByLength(const size_t min, const size_t max)const
{
    for (size_t i = 0; i < current; i++)
    {
        if (songs[i].getLength() >= min && songs[i].getLength() <= max)
        {
            songs[i].print();
        }
    }
}
void Playlist::sortByName()
{
    // for (size_t i = 0; i < current; i++)
    // {
    //     for (size_t j = i + 1; j < current; j++)
    //     {
    //         if (songs[i].getName() > songs[j].getName())
    //         {
    //             std::swap(songs[i].getName(), songs[j].getName());
    //         }
    //     }
    // }
}
void Playlist::sortByGroup()
{
    // for (size_t i = 0; i < current; i++)
    // {
    //     for (size_t j = i + 1; j < current; j++)
    //     {
    //         if (songs[i].getAlbum() > songs[j].getAlbum())
    //         {
    //             std::swap(songs[i].getAlbum(), songs[j].getAlbum());
    //         }
    //     }
    // }    
}
size_t Playlist::totalLenght()const
{
    size_t counter = 0;
    for (size_t i = 0; i < current; i++)
    {
        counter += songs[i].getLength();
    }
    return counter;
}

void Playlist::print()const
{
    for (size_t i = 0; i < current; i++)
    {
        std::cout << i << ". "; songs[i].print();
    }
}