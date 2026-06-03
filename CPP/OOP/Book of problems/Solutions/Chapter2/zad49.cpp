#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class String
{ 
public:
    // конструктор по подразбиране
    String();
    // конструктор за присвояване
    String(const String&);
    // конструктор с явен параметър
    String(const char*);
    // деструктор
    ~String();
    // член-функции за достъп до компонентите
    int length() const;
    const char* getString() const;
    // предефиниране на оператори
    String& operator=(const String&);
    const char* operator=(const char*);
    bool operator==(const String&) const;
    bool operator==(const char*) const;
    bool operator!=(const String&) const;
    bool operator!=(const char*) const;
    bool operator>(const String&) const;
    bool operator>(const char*) const;
    bool operator<(const String&) const;
    bool operator<(const char*) const;
    bool operator>=(const String&) const;
    bool operator>=(const char*) const;
    bool operator<=(const String&) const;
    bool operator<=(const char*) const;
    friend bool operator==(const char*, const String&);
    friend bool operator!=(const char*, const String&);
    friend bool operator> (const char*, const String&);
    friend bool operator< (const char*, const String&);
    friend bool operator>=(const char*, const String&);
    friend bool operator<=(const char*, const String&);
    void print() const
    { 
        for(int i = 0; i < len; i++)
            cout << str[i];
    }

private:
    char* str;        // символен низ
    int len;          // дължина на символен низ
};

// конструктор по подразбиране
String::String()
{ 
    str = NULL;
    len = 0;
}

// конструктор за присвояване
String::String(const String& r)
{ 
    if(r.str)
    { 
        str = new char[r.len+1];
        if(!str)
        {
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(str, r.str);
        len = r.len;
    }
    else
    {
        str = NULL;
        len = 0;
    }
}

// еднопараметричен конструктор
String::String(const char* s)
{ 
    if(s)
    { 
        len = strlen(s);
        str = new char[len+1];
        if(!str)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(str, s);
    }
    else
    {
        str = NULL;
        len = 0;
    }
}

// деструктор
String::~String()
{ 
    if(len != 0) delete [] str;
}

// достъп до дължината на низ
int String::length() const
{ 
    return len;
}

// достъп до низ
const char* String::getString() const
{ 
    return str;
}

// предефиниране на оператора за присвояване,
// който на обект от класа String присвоява
// обект от същия клас
String& String::operator=(const String& r)
{ 
    if(r.str)
    { 
        if(r.str != str)
        { 
            len = r.len;
            if(str) delete [] str;
            str = new char[len+1];
            if(!str)
            { 
                cout << "Грешка при заделяне на памет!\n";
                exit(1);
            }
            strcpy(str, r.str);
        }
    }
    else if(str)
    { 
        delete [] str;
        str = NULL;
        len = 0;
    }
    return *this;
}

// предефиниране на оператора за присвояване, който
// на обект от класа String присвоява символен низ
const char* String::operator=(const char* r)
{ 
    if(r)
    { 
        if(r != str)
        { 
            if(str) delete [] str;
            len = strlen(r);
            str = new char[len+1];
            if(!str)
            { 
                cout << "Грешка при заделяне на памет!\n";
                exit(1);
            }
            strcpy(str, r);
        }
    }
    else 
    {
        if(str)
        { 
            delete [] str;
            str = NULL;
            len = 0;
        }
    }
    return str;
}

// предефиниране на оператора ==, който
// сравнява за == неявния обект с обекта r
bool String::operator==(const String& r) const
{ 
    return !strcmp(str, r.getString());
}

// предефиниране на оператора ==, който
// сравнява за == неявния обект с низа r
bool String::operator==(const char* r) const
{ 
    return !strcmp(str, r);
}

// функция приятел, която предефинира оператора ==
// за сравнение за == на символния низ s с обекта r
bool operator==(const char* s, const String& r)
{ 
    return !strcmp(s, r.getString());
}

// предефиниране на оператора !=, който
// сравнява за != неявния обект с обекта r
bool String::operator!=(const String& r) const
{ 
    return strcmp(str, r.getString()) != 0;
}

// предефиниране на оператора !=, който
// сравнява за != неявния обект с низа r
bool String::operator!=(const char* r) const
{ 
    return strcmp(str, r) != 0;
}

// функция приятел, която предефинира оператора !=
// за сравнение за != на символния низ s с обекта r
bool operator!=(const char* s, const String& r)
{ 
    return strcmp(s, r.getString()) != 0;
}

// предефиниране на оператора >, който проверява
// дали неявният обект е > от обекта r
bool String::operator>(const String& r) const
{ 
    return strcmp(str, r.getString()) > 0;
}

// предефиниране на оператора >, който проверява
// дали неявният обект е > от низа r
bool String::operator>(const char* r) const
{
    return strcmp(str, r) > 0;
}

// функция приятел, която предефинира оператора >,
// проверяващ дали символният низ s е > от обекта r
bool operator>(const char* s, const String& r)
{
    return strcmp(s, r.getString()) > 0;
}

// предефиниране на оператора <, който проверява
// дали неявният обект е < от обекта r
bool String::operator<(const String& r) const
{
    return strcmp(str, r.getString()) < 0;
}

// предефиниране на оператора <, който проверява
// дали неявният обект е < от низа r
bool String::operator<(const char* r) const
{
    return strcmp(str, r) < 0;
}

// функция приятел, която предефинира оператора <,
// проверяващ дали символният низ s е < от обекта r
bool operator<(const char* s, const String& r)
{
    return strcmp(s, r.getString()) < 0;
}

// предефиниране на оператора >=, който проверява
// дали неявният обект е >= на обекта r
bool String::operator>=(const String& r) const
{
    return strcmp(str, r.getString()) >= 0;
}

// предефиниране на оператора >=, който проверява
// дали неявният обект е >= на низа r
bool String::operator>=(const char* r) const
{
    return strcmp(str, r) >= 0;
}

// функция приятел, която предефинира оператора >=,
// проверяващ дали символният низ s е >= на обекта r
bool operator>=(const char* s, const String& r)
{
    return strcmp(s, r.getString()) >= 0;
}

// предефиниране на оператора <=, който проверява
// дали неявният обект е <= на обекта r
bool String::operator<=(const String& r) const
{
    return strcmp(str, r.getString()) <= 0;
}

// предефиниране на оператора <=, който проверява
// дали неявният обект е <= на низа r
bool String::operator<=(const char* r) const
{
    return strcmp(str, r) <= 0;
}

// функция приятел, която предефинира оператора <=,
// проверяващ дали символният низ s е <= на обекта r
bool operator<=(const char* s, const String& r)
{
    return strcmp(s, r.getString()) <= 0;
}

int main()
{
    // оператор "="
    String a("Здравейте "), b;
    b = a;
    b.print();
    b = "Иван и ";
    b.print();
    char str1[] = "Георги!\n";
    b = str1;
    b.print();
    // оператор "=="
    String c("Анета"), d("Анета");
    if(c == d) cout << "Имената съвпадат.\n";
    else cout << "Имената не съвпадат.\n";
    if(c == "Анета") cout << "Имената съвпадат.\n";
    else cout << "Имената не съвпадат.\n";
    if("Анета" == d) cout << "Имената съвпадат.\n";
    else cout << "Имената не съвпадат.\n";
    // оператор ">" 
    String e("Анета"), f("Анет");
    if(e > f)
        cout << "Името Анета е по-голямо от името Анет.\n";
    else
        cout << "Името Анета не е по-голямо от името Анет.\n";
    if(e > "Анет")
        cout << "Името Анета е по-голямо от името Анет.\n";
    else
        cout << "Името Анета не е по-голямо от името Анет.\n";
    if("Анета" > f)
        cout << "Името Анета е по-голямо от името Анет.\n";
    else
        cout << "Името Анета не е по-голямо от името Анет.\n";
    // аналогично за другите оператори за сравнение
    return 0;
}
