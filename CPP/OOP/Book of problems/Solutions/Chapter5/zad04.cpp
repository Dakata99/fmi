#include <iostream.h>
#include <fstream.h>

int main()
{ 
    ifstream f("numbers.txt", ios::in);
    if(!f)
    { 
        cerr << "Файлът не може да се отвори! \n";
        return 1;
    }
    char ch;
    while(!f.eof())
    { 
        f.get(ch);
        if(!f.good() && !f.eof())
        { 
            cout << "I/O грешка! Прекъсване!\n";
            return 1;
        }
        cout << ch;
    }
    return 0;
}
