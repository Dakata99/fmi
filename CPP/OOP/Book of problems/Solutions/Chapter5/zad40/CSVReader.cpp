#include "CSVReader.h"
#include <string.h>

// Ограничение за максимален размер на един запис
// Използва се при четене. С минимално усилие кодът
// може да се модифицира така, че да може да чете
// произволно дълги елементи.
// Да се направи тази модификация за упражнение.
const unsigned int MAX_ELEMENT_LEN = 1024;

CSVReader::CSVReader(const char *f)
{ 
    input(f);
}

fstream& CSVReader::input()
{ 
    return file;
}

void CSVReader::input(const char *f)
{ 
    if(file.is_open())
        file.close();
    file.open(f, ios::in);
}

CSVRow CSVReader::readHeader()
{ 
    char** row = NULL;
    unsigned int cnt = readLine(row);
    CSVRow result(row, cnt);
    for(unsigned int i = 0; i < cnt; ++i)
    {
        delete[] row[i];
    }
    delete[] row;
    return result;
}

void CSVReader::readRow(CSVRow& r)
{ 
    char** row = NULL;
    unsigned int cnt = readLine(row);
    if(r.field(cnt) || !r.field(cnt-1))
    {
        return;
    }
    r.clearValues();
    for(unsigned int i = 0; i < cnt; ++i)
    {
        r.addValue(row[i]);
        delete[] row[i];
    }
    delete[] row;
}

// Помощни функции за четене от файла
unsigned int CSVReader::readLine(char**& row)
{
    char* element;
    unsigned int cnt = 0;
    char ch;
    do
    {
        element = getElement();
        append(row, element, cnt);
        ++cnt;
        // След всеки елемент има символ ',' или '\n'
        ch = file.get();
    } while(file.good() && ch != '\n');
    return cnt;
}

char* CSVReader::getElement()
{
    char buffer[MAX_ELEMENT_LEN];
    // Прескачане на символи до отварящата кавичка
    file.ignore(MAX_ELEMENT_LEN, '\"');
    if(file.eof()) return NULL;
    // Четене до затварящата кавичка
    file.getline(buffer, MAX_ELEMENT_LEN, '"');
    char* result = new char[strlen(buffer) + 1];
    return strcpy(result, buffer);
}

void CSVReader::append(char**& row, char* elem, unsigned cnt) const
{
    char** res = new char*[cnt+1];
    for(unsigned int i = 0; i < cnt; ++i)
    {
        res[i] = row[i];
    }
    res[cnt] = elem;
    delete row;
    row = res;
}
