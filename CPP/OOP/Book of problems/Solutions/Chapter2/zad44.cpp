#include <iostream.h>
#include <iomanip.h>
#include <string.h>

const int MaxLenWord = 15;            // максимална дължина на дума
const int MaxLenInterpret = 100;      // максимална дължина на
// тълкуването на дума
const int MaxPairs = 300;             // максимален брой на двойките на речник

// дефиниция на клас Pair, реализиращ
// двойка дума-тълкуване
class Pair
{
private:
    char word[MaxLenWord + 1];              // дума
    char interpret[MaxLenInterpret + 1];    // тълкуване на дума

public:
    // конструктор
    Pair();
    // член-функция за извеждане на член-данните на класа
    void print() const;
    // член-функция за инициализиране на двойка дума-тълкуване
    void insert(const char*, const char*);
    // член-функция за проверка дали думата k е равна на думата word
    bool equal(const char* k) const;
};

Pair::Pair()
{
    strcpy(word, "");
    strcpy(interpret, "");
}

void Pair::print() const
{
    cout << word << " - "
        << interpret << endl;
}

void Pair::insert(const char* w, const char* d)
{
    strcpy(word, w);
    strcpy(interpret, d);
}

bool Pair::equal(const char* w) const
{ 
    return strcmp(w, word) == 0;
}

// декларация на класа итератор на класа Dictionary
class DictIter;

// дефиниция на клас Dictionary, реализиращ
// тълковен речник като масив от двойки
class Dictionary
{   
    friend class DictIter;
    Pair pairs[MaxPairs+1];    // масив от двойки дума-тълкуване
    int count;                 // брой на елементите на масива

public:
    // конструктор на речник
    Dictionary()
    { 
        count = 0;
    }
    // член-функция за извеждане на речник
    void print() const;
    // член-функция за включване на двойка дума-тълкуване в речник
    void insert(const char*, const char*);
    // член-функция за изключване на думата w и нейното тълкуване от речник
    void remove(const char* w);
    // предефиниране на оператора [] за търсене на думата w в речник
    void operator[](const char* w) const;
};

void Dictionary::print() const
{ 
    for(int i = 0; i < count; i++)
        pairs[i].print();
}

void Dictionary::insert(const char* w, const char* d)
{ 
    if(count < MaxPairs)
        pairs[count++].insert(w, d);
    else
        cout << count << " е по-голямо от MaxPairs. \n";
}

void Dictionary::remove(const char* w)
{ 
    int i = 0;
    // последователно търсене
    while(i < count && !pairs[i].equal(w))
        i++;

    // изтриване на двойката
    if(pairs[i].equal(w))
    { 
        for(int j = i+1; j < count; j++)
            pairs[j-1] = pairs[j];
        count--;
    }
    else
    {
        cout << w << " не е в речника.\n";
    }
}

void Dictionary::operator[](const char* w) const
{ 
    int i = 0;
    // последователно търсене
    while(i < count)
    {
        if(pairs[i].equal(w))
        { pairs[i].print();
        break;
        }
        else
        {
            i++;
        }
    }
    if(i == count)
    {
        cout << w << " не е в речника.\n";
    }
}

// дефиниране на класа DictIter - итератор за класа Dictionary
class DictIter
{ 
private:
    int current;            // текущ елемент, сочен от dict
    Dictionary* dict;       // указател към елементa с индекс
    // current на речника

public:
    // конструктор на итератора
    DictIter(Dictionary& d)
    { 
        // dict указва елемента с индекс 0 на речника d, а current е 0
        dict = &d;
        current = 0;
    }
    // предефиниция на оператора () за използването му като итератор
    Pair* operator()();
};

Pair* DictIter::operator()()
{ 
    if(current >= dict->count)
        return NULL;
    return &dict->pairs[current++];
}

int main()
{ 
    // създаване на тълковен речник
    Dictionary d;
    // включване на елементи в речника
    d.insert("pixel", "A pixel is the smallest piece of " "information in an image.");
    d.insert("diode",  "A diode is a two-terminal device.");
    d.insert("recursion", "Recursion is a method of defining "
        "functions in which the function "
        "being defined is applied within "
        "its own definition.");
    d.insert("computer",  "A computer is a machine that "
                          "manipulates data according to a list of instructions.");
    d.insert("monitor", "A computer monitor is an electronic "
                        "device that shows pictures.");
    // извеждане на речника
    d.print(); cout << endl;
    cout << "използване на оператора []\n";
    d["diode"];
    d["monitori"];
    cout << "\nИзползване на оператора ()\n";
    // създаване на итератор dint за речника d
    // установяващ указател към първия елемент
    // на речника d
    DictIter dint(d);
    Pair* ptr = NULL;
    // указателят ptr сочи елементите на речника от
    // първия до последния му и за всеки елемент се
    // активира член-функцията print() на класа Pair
    // операторът за цикъл извършва действия
    // еквивалентни на d.print()
    while(ptr = dint())
        ptr->print();
    cout << endl;
    // изтриване на елементи от речника
    d.remove("diode");    
    d.remove("monitor");
    // извеждане на речника
    d.print(); cout << endl;
    return 0;
}
