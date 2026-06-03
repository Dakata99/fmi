#include <iostream.h>
#include <fstream.h>

void checkstatus(ifstream& f)
{ 
    int stat = f.rdstate();
    if(stat & ios::eofbit)
        cout << "EOF е активен!\n";
    else if(stat & ios::failbit)
        cout << "I/O грешка\n";
    else if(stat & ios::badbit)
        cout << "Фатална I/O грешка";
}

int main()
{
    ifstream f("numbers.txt", ios::in);
    if(!f)
    {
        cerr << "Файлът не може да се отвори! \n";
        return 1;
    }
    char ch;
    while(f.get(ch))
    {
        cout << ch;
        checkstatus(f);    
    }
    checkstatus(f);
    return 0;
}
