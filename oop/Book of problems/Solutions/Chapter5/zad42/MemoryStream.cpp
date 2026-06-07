#include "MemoryStream.h"
#include <memory.h>

// Подразбиращ се размер на буфера, както и стъпка за нарастване
const size_t MemoryStream::defaultSize = 1024;

MemoryStream::MemoryStream(): bufferSize(defaultSize),
                              position(0), length(0)
{
    buffer = new unsigned char[bufferSize]; 
}

MemoryStream::MemoryStream(const unsigned char* buffer, int size) : buffer(0),
                           bufferSize(0), position(0), length(0)
{
    if(buffer && size > 0)
    {
        EnsureSize(size);
        memcpy(this->buffer, buffer, size);
    }
}

MemoryStream::MemoryStream(const MemoryStream & stream) :
                           position(stream.position),
                           bufferSize(stream.bufferSize),
                           length(stream.length)
{
    buffer = new unsigned char[bufferSize];
    memcpy(buffer, stream.buffer, length);
}

MemoryStream& MemoryStream::operator=(const MemoryStream& rhs)
{
    if(&rhs != this)
    {
        delete[] buffer;
        position = rhs.position;
        bufferSize = rhs.bufferSize;
        length = rhs.length;
        buffer = new unsigned char[bufferSize];
        memcpy(buffer, rhs.buffer, length);
    }
    return * this;
}

MemoryStream::~MemoryStream()
{
    delete[] buffer;
}

int MemoryStream::GetPosition()
{
    return position;
}

int MemoryStream::GetLength()
{
    return length;
}

void MemoryStream::Seek(int position)
{
    if(position < 0) 
    {
        position = 0;
    }
    else if(position > length)
    {
        position = length;
    }
    this->position = position;
}

int MemoryStream::Read(unsigned char * buffer, int size)
{
    if(size < 0) return 0;
    if(position + size > length)
    {
        size = length - position;
    }
    if(size)
    {
        memcpy(buffer, this->buffer+position, size);
    }
    position += size;
    return size;
}

int MemoryStream::Write(const unsigned char * buffer, int size)
{
    if(size < 0) size = 0;
    EnsureSize(size + position);
    memcpy(this->buffer+position, buffer, size);
    position += size;
    length = position > length ? position : length;
    return size;
}

int MemoryStream::CanGetPosition()
{
    return 1;
}

int MemoryStream::CanGetLength()
{
    return 1;
}

int MemoryStream::CanSeek()
{ 
    return 1;
}

// Функцията връща копие на буфера. Осъществява
// се заделяне на памет, така че задължение на
// извикващия е освобождаването й.
void MemoryStream::GetBuffer(unsigned char *&buffer, size_t &size)
{
    buffer = new unsigned char[length];
    size = length;
    memcpy(buffer, this->buffer, size);
}

void MemoryStream::Flush()
{
    // Няма какво да се извършва (всичко е в паметта)
}

// Подсигурява буферът, с който се работи да има
// поне определен размер. Това се използва при
// записване на информация с цел разширяване,
// ако е необходимо.
void MemoryStream::EnsureSize(int size)
{
    if(size > bufferSize)
    {
        while(bufferSize < size)
            bufferSize += defaultSize;
        unsigned char* new_buffer = new unsigned char[bufferSize];
        memcpy(new_buffer, buffer, length);
        delete [] buffer;
        buffer = new_buffer;
    }
}
