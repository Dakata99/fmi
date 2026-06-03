#pragma once

class Reader
{
private:
    char* name;
    char* address;
    char* reader_number;
    char* copy(const char*);
public:
    Reader(const char* = "", const char* = "", const char* = "");
    Reader(const Reader&);
    ~Reader();
    Reader& operator=(const Reader&);

    void print()const;
};