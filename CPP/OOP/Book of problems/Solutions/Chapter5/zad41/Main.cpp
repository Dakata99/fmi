#include "Archive.h"
#include <iostream.h>  // cerr, cout, endl
#include <stdlib.h>    // exit
#include <memory.h>    // memcpy
#include <conio.h>     // getch

void printHelp(char* exeName)
{
    cout << "Използване на архиватора: \n " << exeName
         << " <option> <archive name> <files>\n\n"
            " Валидни опции: \n"
            " -a  : добавя файлове към архив\n"
            " -n  : добавя файлове към нов архив \n"
            " -e  : извлича файлове в указана директория\n\n"
            " Примери :\n"
         << exeName << " -a test.arc file1.txt file2.txt file3.txt\n"
         << exeName << " -e test.arc dir1" << endl;
}

void error(const char* msg)
{
    cerr << "Грешка в архива! ";
    cerr << msg << endl;
}

char* readPassword()
{
    int max_size = 256;
    char* passwd = new char[max_size];
    int pos = 0;
    char ch;
    cout << "Парола: ";
    do
    {
        // Прочита един символ, без да го извежда на екрана
        ch = getch();
        if(ch != '\n' && ch != '\r')
        {
            cout << '*';
            passwd[pos++] = ch;
        }

        // Ако е запълнен заделеният буфер, се заделя нов по-голям
        if(pos == max_size-1)
        {
            max_size <<= 1;
            char* tmp = new char[max_size];
            memcpy(tmp, passwd, pos);
            delete[] passwd;
            passwd = tmp;
        }
    } while(ch != '\n' && ch != '\r');
    passwd[pos] = '\0';
    cout << endl;
    return passwd;
}

// Изпълнява указана команда
void doCommand(char command, char* archiveName,
               int filesCount, char* files[])
{
    // Командата не е сред познатите
    if(command != 'a' && command != 'e' && command != 'n')
    {
        error("Непозната опция");
        exit(EXIT_FAILURE);
    }

    char* keyword;

    // Отваряне на архива
    Archive arch(archiveName, command == 'n');
    // Ако ще се добавят или изваждат
    // файлове, се изисква парола
    keyword = filesCount ? readPassword() : NULL;
    if(command == 'a' || command == 'n')
    {
        for(int i = 0; i < filesCount; ++i)
        {
            cout << "добавяне на файла " << files[i] << " ... ";
            if(arch.AddFile(files[i], keyword))
            {
                cout << "УСПЕХ"<<endl;
            }
            else
            {
                cout << "ГРЕШКА"<<endl;
            }
        }
    }
    else if(command == 'e')
    {
        if(filesCount)
        {
            cout << "Извличане на файлове в " << files[0] << " ... ";
            if(arch.ExtractAll(files[0], keyword))
            {
                cout << "УСПЕХ" << endl;
            }
            else
            {
                cout << "ГРЕШКА" << endl;
            }
        }
    }
    delete[] keyword;
    cout << "Операцията е завършила!" << endl;
    cout << "Размер на файловете в архива: " 
         << arch.GetTotalSize() << endl;
}

int main(int argc, char * argv[])
{
    if(argc < 3)       // Минимален брой аргументи
    {
        error("Твърде малко аргументи!");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Първият аргумент трябва да е от вида -X,
    // където X е символ на команда
    if(argv[1][0] != '-' || argv[1][2])
    {
        error("Неправилно използване");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }

    doCommand(argv[1][1], argv[2], argc-3, argv+3);
    return 0;
}
