#include "Song.h"

Song::Song(const std::string _name, const std::string _author, const std::string _album, const size_t len)
        :name(_name), author(_author), album(_album), length(len){}

Song::Song(const Song& other)
{
    name = other.name;
    author = other.author;
    album = other.album;
    length = other.length;
}
Song::~Song(){}

Song& Song::operator=(const Song& other)
{
    if (this != &other)
    {
        name = other.name;
        author = other.author;
        album = other.album;
        length = other.length;
    }
    return *this;
}

std::string Song::getName()const
{
    return name;
}
std::string Song::getAuthor()const
{
    return author;
}
std::string Song::getAlbum()const
{
    return album;
}
size_t Song::getLength()const
{
    return length;
}

void Song::setName(const std::string _name)
{
    name = _name;
}
void Song::setAuthor(const std::string _author)
{
    author = _author;
}
void Song::setAlbum(const std::string _album)
{
    album = _album;
}
void Song::setLength(const size_t len)
{
    length = len;
}

void Song::print()const
{
    std::cout << name << " - " << author << " - " << album << " - " << length << std::endl;
}