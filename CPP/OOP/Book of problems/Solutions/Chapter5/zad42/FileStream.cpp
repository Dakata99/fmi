#include "FileStream.h"
#include <assert.h>

FileStream::FileStream(const char * fileName)
{
    assert(fileName);
    file.open(fileName, ios::binary|ios::nocreate);
    if(file.fail())
    {
        file.open(fileName, ios::binary|ios::trunc);
    }
}

FileStream::~FileStream()
{
    if(file.is_open()) file.close();
}    

// За позиция се приема позицията за четене
// Това би могло да е проблем при файлове с двойно
// буфериране (файлове, при които има отделни буфери за четене
// и за запис). Възможно решение, което читателят може да опита
// да реализира е да се стреми да поддържа и двата указателя
// в една позиция (при всеки запис указателят за четене
// изкуствено се премества и обратно).
int FileStream::GetPosition()
{
    return CanGetPosition() ? (int)file.tellg() : -1;
}

// Дължината се базира на буфера за четене.
// Това е реалната дължина на файла, тъй като всичко
// от буфера за запис се записва чрез извикване на функцията flush.
int FileStream::GetLength()
{
    if(!CanGetLength())
        return -1;
    file.flush();
    int pos = file.tellg();
    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(pos, ios::beg);
    return len;
}

// При позициониране се преместват и двата указателя,
// тъй като не се знае коя ще е следващата операция.
void FileStream::Seek(int position)
{
    if(CanSeek())
    {
        file.seekp(position, ios::beg);
        file.seekg(position, ios::beg);
    }
}

int FileStream::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sgetn((char *)buffer, size);
}

int FileStream::Write(const unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sputn((char *)buffer, size);
}

int FileStream::CanGetPosition()
{
    return file.tellg() >= 0;
}

int FileStream::CanGetLength()
{
    return CanGetPosition() && CanSeek();
}

int FileStream::CanSeek()
{
    file.seekg(0, ios::cur);
    if(file.fail())
    {
        file.clear(file.rdstate()&~ios::failbit);
        return 0;
    }
    return 1;
}

void FileStream::Flush()
{
    file.flush();
}
