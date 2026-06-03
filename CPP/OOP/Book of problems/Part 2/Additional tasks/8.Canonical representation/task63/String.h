#pragma once
#include <cstring>

class String
{
private:
    size_t len;
    char* str;
public:
    //Constructors
    String();
    String(const char*);
    String(const String&);
    
    //Destructors
    ~String();
    
    //Operator=
    String operator=(const String&);
    String operator=(const char*);

    //operator!=
    bool operator!=(const String&);
    bool operator!=(const char*);
    friend bool operator!=(const char*, const String&);

    //operator==
    bool operator==(const String&);
    bool operator==(const char*);
    friend bool operator==(const char*, const String&);

    //operator>=
    bool operator>=(const String&);
    bool operator>=(const char*);
    friend bool operator>=(const char*, const String&);
    
    //operator<=
    bool operator<=(const String&);
    bool operator<=(const char*);
    friend bool operator<=(const char*, const String&);
    
    //operator>
    bool operator>(const String&);
    bool operator>(const char*);
    friend bool operator>(const char*, const String&);
    
    //operator<
    bool operator<(const String&);
    bool operator<(const char*);
    friend bool operator<(const char*, const String&);

    //operator+=
    String operator+=(const String&);
    String operator+=(const char*);

    //Getters
    char* getString()const;
    size_t getLength()const;

    //Setters
    void setString(const char*);
    
    //Funcs
    void print()const;
};