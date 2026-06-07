#include "Decryptor.h"
#include <assert.h>
#include <string.h>

Decryptor::Decryptor(InputStream * stream, const char * keyword) :
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

Decryptor::~Decryptor()
{
    delete[] keyword;
}

int Decryptor::GetPosition()
{
    return streamPtr->GetPosition();
}

int Decryptor::GetLength()
{
    return streamPtr->GetLength();
}

void Decryptor::Seek(int position)
{
    if(CanSeek())
    {
        keywordPosition = keywordLength ? position%keywordLength : 0;
        streamPtr->Seek(position);
    }
}

int Decryptor::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    if(!keywordLength) // Няма парола
    {
        return streamPtr->Read(buffer, size);
    }
    unsigned char ch;
    for(int i = 0; i < size; ++i)
    {
        if(!streamPtr->Read(&ch, 1))
            return i;
        buffer[i] = ch^keyword[keywordPosition];
        keywordPosition = (keywordPosition+1)%keywordLength;
    }
    return size;
}

int Decryptor::CanGetPosition()
{
    return streamPtr->CanGetPosition();
}

int Decryptor::CanGetLength()
{
    return streamPtr->CanGetLength();
}

int Decryptor::CanSeek()
{
    return streamPtr->CanSeek();
}
