#ifndef DECRYPTOR_HEADER_INCLUDED
#define DECRYPTOR_HEADER_INCLUDED

#include <string.h>
#include "InputStream.h"

class Decryptor : public InputStream
{
public:
    Decryptor(InputStream* stream, const char * keyword);
    ~Decryptor();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();

protected:
    InputStream* streamPtr;
    char * keyword;
    size_t keywordLength;
    size_t keywordPosition;

private:
    Decryptor(const Decryptor&);
    void operator=(const Decryptor&);
};

#endif //DECRYPTOR_HEADER_INCLUDED
