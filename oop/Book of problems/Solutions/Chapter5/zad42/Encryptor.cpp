#include "Encryptor.h"
#include <assert.h>
#include <string.h>

Encryptor::Encryptor(OutputStream * stream, const char * keyword) :
                     keywordPosition(0),
                     keyword(0),
                     streamPtr(stream)
{
    assert(stream);
    assert(keyword);
    keywordLength = strlen(keyword);
    this->keyword = new char[keywordLength + 1];
    strcpy(this->keyword, keyword);
}

Encryptor::~Encryptor()
{
    delete[] keyword;
}

int Encryptor::GetPosition()
{
    return streamPtr->GetPosition();
}

int Encryptor::GetLength()
{
    return streamPtr->GetLength();
}

void Encryptor::Seek(int position)
{
    if(CanSeek())
    {
        keywordPosition = keywordLength ? position%keywordLength : 0;
        streamPtr->Seek(position);
    }
}

int Encryptor::Write(const unsigned char * buffer, int size)
{
    assert(buffer);
    if(!keywordLength) // Няма парола
    {
        return streamPtr->Write(buffer, size);
    }
    unsigned char ch;
    for(int i = 0; i < size; ++i)
    {
        ch = buffer[i]^keyword[keywordPosition];
        if(!streamPtr->Write(&ch, 1))
            return i;
        keywordPosition = (keywordPosition+1)%keywordLength;
    }
    return size;
}

int Encryptor::CanGetPosition()
{
    return streamPtr->CanGetPosition();
}

int Encryptor::CanGetLength()
{
    return streamPtr->CanGetLength();
}

int Encryptor::CanSeek()
{
    return streamPtr->CanSeek();
}

void Encryptor::Flush()
{
    streamPtr->Flush();
}
