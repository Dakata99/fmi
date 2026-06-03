#include "String.h"

//Constructors
String::String():len(0), str(nullptr){}
String::String(const char* string)
{
    len = strlen(string) + 1;

    str = new char[len];
    strcpy(str, string);
}
String::String(const String& string)
{
    len = string.length() + 1;
    str = new char[len];
    strcpy(str, string.cstring());
}
    
//Destructors
String::~String()
{
    delete[]str;
}
    
//Operator=
String String::operator=(const String& string)
{
    len = string.length() + 1;
        
    str = new char[len];
    strcpy(str, string.cstring());

    return *this;
}
String String::operator=(const char* string)
{
    len = strlen(string) + 1;

    str = new char[len];
    strcpy(str, string);

    return *this;
}

//Getters
const char* String::cstring()const
{
    return str;
}
size_t String::length()const
{
    return len - 1;
}

//Setters
void String::setString(const char* string)
{
    len = strlen(string) + 1;
    
    if(str != nullptr)
        delete[]str;
    
    str = new char[len];
    strcpy(str, string);
}

//Print
void String::print()const
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

//Other funcs
char& String::at(const size_t index)
{
    if (index <= 0 || index >= len)
        return str[len];

    return str[index - 1];
}
int String::compareTo(const String& other)
{
    if(strcmp(str, other.str) == 0)
        return 0;
    
    return -1;
}
const String& String::replaceFirst(const String& first, const String& second, int index)
{
    return *this;
}
const String& String::insert(const String& string, int index)
{
    if (index < 0 || index > len)
    {
        return *this;
    }
    return *this;
}
const String& String::deletee(const int left, const int right)
{
    if (left > right)
    {
        *this = String("");
        return *this;
    }
    String temp, temp2 = this->substring(left, right);
    temp.len = right - left + 1;
    temp.str = new char[len];
    for (size_t i = 0; i < temp.len; i++)
    {
        for (size_t j = 0; j < temp2.length(); j++)
        {
            if (str[i] != temp2.str[j])
            {
                temp.str[i] = temp2.str[j];
            }
        }
    }
    *this = temp;
    return *this;
}
void String::copy(const char*, size_t)
{

}
const String& String::trim(const char)
{
    return *this;
}
String* String::tokenize(char)
{
    String* temp;
    return temp;
}
String String::substring(const int left, const int right)
{
    if (left > right)
    {
        return String("");
    }
    else if (left == right)
    {
        // char* x = new char(at(left));
        // String temp(x);
        return String(new char(at(left)));
    }
    String temp;
    temp.len = right - left + 1;
    temp.str = new char[temp.len];
    for (size_t i = left - 1; i < right; i++)
    {
        temp.str[i - left + 1] = str[i];
    }

    return temp;
}