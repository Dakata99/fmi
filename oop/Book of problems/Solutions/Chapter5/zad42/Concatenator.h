#ifndef CONCATENATOR_HEADER_INCLUDED
#define CONCATENATOR_HEADER_INCLUDED

#include "InputStream.h"
class Concatenator : public InputStream
{
public:
    Concatenator(InputStream* firstStream, InputStream* secondStream);
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();

protected:
    InputStream* first;
    InputStream* second;
    int position;
    int len;

private:
    Concatenator(const Concatenator&);
    void operator=(const Concatenator&);
};

#endif //CONCATENATOR_HEADER_INCLUDED
