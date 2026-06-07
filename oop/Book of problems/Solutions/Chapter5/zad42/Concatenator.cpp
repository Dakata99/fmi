#include "Concatenator.h"
#include <assert.h>

Concatenator::Concatenator(InputStream * stream1, InputStream * stream2) :
                           first(stream1), second(stream2)
{
    assert(first);
    assert(second);
    assert(first->CanGetPosition() && first->CanGetLength());
    position = first->GetPosition();
    len = first->GetLength();
}

int Concatenator::GetPosition()
{
    return position;
}

int Concatenator::GetLength()
{
    // След създаване на конкатенатора, в първия
    // поток не би трябвало да се записва
    assert(len == first->GetLength());
    if(CanGetLength())
        return len + second->GetLength();
    return -1;
}

void Concatenator::Seek(int position)
{
    // След създаване на конкатенатора, в първия
    // поток не би трябвало да се записва
    assert(len == first->GetLength());
    if(CanSeek())
    {
        if(GetLength() < position)
        {
            position = GetLength();
        }
        if(position < len)
        {
            first->Seek(position);
        }
        else
        {
            second->Seek(position - first->GetLength());
        }
        this->position = position;
    }
}

int Concatenator::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    // След създаване на конкатенатора, в първия
    // поток не би трябвало да се записва
    assert(len == first->GetLength());
    int bytesRead = 0;
    if(position < len)
    { 
        int bytesLeft = len - position;
        int bytesToRead = bytesLeft < size ? bytesLeft : size;
        bytesRead = first->Read(buffer, bytesToRead);
        position += bytesRead;
        if(bytesRead < bytesToRead || bytesRead == size)
        {
            return bytesRead;
        }
        size -= bytesRead;
        buffer += bytesRead;
    }
    return bytesRead + second->Read(buffer, size);
}

int Concatenator::CanGetPosition()
{
    return true;
}

int Concatenator::CanGetLength()
{
    return second->CanGetLength();
}

int Concatenator::CanSeek()
{
    return first->CanSeek() && second->CanSeek();
}
