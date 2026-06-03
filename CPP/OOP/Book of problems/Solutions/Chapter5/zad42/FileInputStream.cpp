#include "FileInputStream.h"
#include <assert.h>

FileInputStream::FileInputStream(const char * fileName)
{ 
    assert(fileName);     // Задължително трябва да има име
    file.open(fileName, ios::in|ios::binary);
}

FileInputStream::~FileInputStream()
{
    if(file.is_open())
        file.close();
}

int FileInputStream::GetPosition()
{
    return CanGetPosition() ? (int)file.tellg() : -1;
} 

int FileInputStream::GetLength()
{
    if(!CanGetLength())
        return -1;
    int pos = file.tellg();
    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(pos, ios::beg);
    return len;
}

void FileInputStream::Seek(int position)
{
    if(CanSeek())
        file.seekg(position, ios::beg);
}

int FileInputStream::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sgetn((char *)buffer, size);
}

int FileInputStream::CanGetPosition()
{
    return file.tellg() >= 0;
}

int FileInputStream::CanGetLength()
{
    return CanGetPosition() && CanSeek();
}

int FileInputStream::CanSeek()
{
    file.seekg(0, ios::cur);
    if(file.fail())
    {
        file.clear(file.rdstate()&~ios::failbit);
        return 0;
    }
    return 1;
}
