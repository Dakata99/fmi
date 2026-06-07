#pragma once
#include <string>

class Song
{
private:
    std::string name, author, album;
    size_t length;
public:
    Song(const std::string = "", const std::string = "", const std::string = "", const size_t = 0);
    Song(const Song&);
    ~Song();

    Song& operator=(const Song&);

    std::string getName()const;
    std::string getAuthor()const;
    std::string getAlbum()const;
    size_t getLength()const;

    void setName(const std::string);
    void setAuthor(const std::string);
    void setAlbum(const std::string);
    void setLength(const size_t);

    void print()const;
};

