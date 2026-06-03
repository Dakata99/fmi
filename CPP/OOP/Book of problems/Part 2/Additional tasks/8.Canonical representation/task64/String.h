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
    String operator=(const String& string);
    String operator=(const char* string);

    //Getters
    const char* cstring()const;
    size_t length()const;

    //Setters
    void setString(const char* string);
    
    //Print
    void print()const;

    //Other funcs
    char& at(const size_t);
    int compareTo(const String&);
    const String& replaceFirst(const String&, const String&, int = 0);
    const String& insert(const String&, int);
    const String& deletee(int, int);
    void copy(const char*, size_t);
    const String& trim(const char);
    String* tokenize(char);
    String substring(const int, const int);
};