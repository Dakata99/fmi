#include "FileOutputStream.h"
#include <assert.h>

FileOutputStream::FileOutputStream(const char * fileName)
{
    assert(fileName);        // Задължително се подава име
    file.open(fileName, ios::out|ios::binary|ios::nocreate);
    if(file.fail())
    {
        file.open(fileName, ios::out|ios::binary|ios::trunc);
    }
}

FileOutputStream::~FileOutputStream()
{
    if(file.is_open()) file.close();
}

int FileOutputStream::GetPosition()
{
    return CanGetPosition() ? (int)file.tellp() : -1;
}

int FileOutputStream::GetLength()
{
    if(!CanGetLength())
        return -1;
    int pos = file.tellp();
    file.seekp(0, ios::end);
    int len = file.tellp();
    file.seekp(pos, ios::beg);
    return len;
}

void FileOutputStream::Seek(int position)
{
    if(CanSeek())
    {
        file.seekp(position, ios::beg);
    }
}

int FileOutputStream::Write(const unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sputn((char *)buffer, size);
}

int FileOutputStream::CanGetPosition()
{
    return file.tellp() >= 0;
}

int FileOutputStream::CanGetLength()
{
    return CanGetPosition() && CanSeek();
}

int FileOutputStream::CanSeek()
{
    file.seekp(0, ios::cur);
    if(file.fail())
    {
        file.clear(file.rdstate()&~ios::failbit);
        return 0;
    }
    return 1;
}

void FileOutputStream::Flush()
{
    file.flush();
}
