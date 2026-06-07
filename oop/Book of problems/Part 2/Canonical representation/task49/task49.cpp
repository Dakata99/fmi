#include <iostream>
#include <cstring>

class String
{
private:
    size_t len;
    char* str;
public:
    //Constructors
    String():len(0), str(nullptr){}
    String(const char* string)
    {
        len = strlen(string) + 1;

        str = new char[len];
        strcpy(str, string);
    }
    String(const String& string)
    {
        len = string.getLength();
        str = new char[len + 1];
        strcpy(str, string.getString());
    }
    
    //Destructors
    ~String()
    {
        delete[]str;
    }
    
    //Operator=
    String operator=(const String& string)
    {
        len = string.getLength() + 1;
        
        str = new char[len];
        strcpy(str, string.getString());

        return *this;
    }
    String operator=(const char* string)
    {
        len = strlen(string) + 1;

        str = new char[len];
        strcpy(str, string);

        return *this;
    }

    //operator!=
    bool operator!=(const String& string)
    {
        return !(str == string.getString());
    }
    bool operator!=(const char* string)
    {
        return !(str == string);
    }
    friend bool operator!=(const char* string, const String& str)
    {
        return !(string == str);
    }

    //operator==
    bool operator==(const String& string)
    {
        if(len == string.getLength())
        {
            for (size_t i = 0; i < len; i++)
            {
                if (str[i] != string.str[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    bool operator==(const char* string)
    {
        if (len == strlen(string) + 1)
        {
            for (size_t i = 0; i < len; i++)
            {
                if (str[i] != string[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    friend bool operator==(const char* string, const String& str)
    {
        if(strlen(string) + 1!= str.getLength())
            return false;

        for (size_t i = 0; i < str.getLength(); i++)
        {
            if (string[i] != str.str[i])
            {
                return false;
            }
        }
        return true;
    }

    //operator>=
    bool operator>=(const String& string)
    {
        return !(str <= string);
    }
    bool operator>=(const char* string)
    {
        return !(str <= string);
    }
    friend bool operator>=(const char* string, const String& str)
    {
        return !(string <= str);
    }
    
    //operator<=
    bool operator<=(const String& string)
    {
        if (len <= string.getLength())
        {
            return true;
        }
        for (size_t i = 0; i < len; i++)
        {
            if (str[i] <= string.str[i])
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const char* string)
    {
        if (len <= strlen(string) + 1)
        {
            return true;
        }
        for (size_t i = 0; i < len; i++)
        {
            if (str[i] <= string[i])
            {
                return true;
            }
        }
        return false;
    }
    friend bool operator<=(const char* string, const String& str)
    {
        if (strlen(string) + 1 <= str.getLength())
        {
            return true;
        }
        for (size_t i = 0; i < str.getLength(); i++)
        {
            if (string[i] <= str.str[i])
            {
                return true;
            }
        }
        return false;
    }
    
    //operator>
    bool operator>(const String& string)
    {
        return !(str < string);
    }
    bool operator>(const char* string)
    {
        return !(str < string);
    }
    friend bool operator>(const char* string, const String& str)
    {
        return !(string < str);
    }
    
    //operator<
    bool operator<(const String& string)
    {
        if (len < string.getLength())
        {
            return true;
        }
        for (size_t i = 0; i < len; i++)
        {
            if (str[i] < string.str[i])
            {
                return true;
            }
        }
        return false;
    }
    bool operator<(const char* string)
    {
        if (len < strlen(string) + 1)
        {
            return true;
        }
        for (size_t i = 0; i < len; i++)
        {
            if (str[i] < string[i])
            {
                return true;
            }
        }
        return false;
    }
    friend bool operator<(const char* string, const String& str)
    {
        if (strlen(string) + 1 < str.getLength())
        {
            return true;
        }
        for (size_t i = 0; i < str.getLength(); i++)
        {
            if (str.str[i] < string[i])
            {
                return true;
            }
        }
        return false;
    }

    //Getters
    char* getString()const
    {
        return str;
    }
    size_t getLength()const
    {
        return len;
    }

    //Setters
    void setString(const char* string)
    {
        len = strlen(string) + 1;
        
        if(str != nullptr)
            delete[]str;
        
        str = new char[len];
        strcpy(str, string);
    }
    //Funcs
    void print()const
    {
        for (size_t i = 0; i < len; i++)
        {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }
};


void myFunc()
{
    String s1("abracadabra"), s2("Aladin");
    s1.print();
    s2.print();

    //operator=
    String s3 = s1, s4 = s2;
    s3.print();
    s4.print();

    String s5 = "Daniel";
    s5.print();

    //operator !=
    bool flag = s1 != s3;
    std::cout << std::boolalpha << flag << std::endl;

    //operator ==
    flag = s1 == s4; //compare 2 strings
    std::cout << std::boolalpha << flag << std::endl;
    flag = s1 == "Daniel"; //compare string and const char*
    std::cout << std::boolalpha << flag << std::endl;
    flag = "Daniel" == s5; //compare const char* and string
    std::cout << std::boolalpha << flag << std::endl;

    //operator >=

    //operator <=

    //operator >
    String s6 = "Geeks", s7 = "forGeeks";
    if(s6 > s7)
        std::cout << "s6 is greater than s7" << std::endl;
    //operator <
    if(s6 < s7)
        std::cout << "s6 is smaller than s7" << std::endl;
    
}

void func()
{
    String a("Hello "), b;
    b = a;
    b.print();
    b = "Ivan and ";
    char str1[] = "Georgi!\n";
    b = str1;
    b.print();

    String c("Aneta"), d("Aneta");
    if(c == d) std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    if(c == "Aneta") std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    if("Aneta" == d) std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    String e("Aneta"), f("Anet");
    if(e > f)
        std::cout << "Aneta is longer than Anet\n";
    else
        std::cout << "Aneta is not longer than Aner\n";

    if(e > "Anet")
        std::cout << "Aneta is longer than Anet\n";
    else
        std::cout << "Aneta is not longer than Anet\n";

    if("Aneta" > f)
        std::cout << "Aneta is longer than Anet\n";
    else 
        std::cout << "Aneta is not longer than Anet\n";
}

int main()
{
    //myFunc();
    //func();

    return 0;
}