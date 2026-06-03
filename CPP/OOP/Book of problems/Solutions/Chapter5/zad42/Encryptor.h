#ifndef ENCRYPTOR_HEADER_INCLUDED
#define ENCRYPTOR_HEADER_INCLUDED

#include <string.h>
#include "OutputStream.h"

class Encryptor : public OutputStream
{
public:
    Encryptor(OutputStream *stream, const char *keyword);
    ~Encryptor();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();

protected:
    OutputStream * streamPtr;
    char * keyword;
    size_t keywordLength;
    size_t keywordPosition;

private:
    Encryptor(const Encryptor&);
    void operator=(const Encryptor&);
};

#endif //ENCRYPTOR_HEADER_INCLUDED

