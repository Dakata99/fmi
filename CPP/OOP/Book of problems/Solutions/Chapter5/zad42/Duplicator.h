#ifndef DUPLICATOR_HEADER_INCLUDED
#define DUPLICATOR_HEADER_INCLUDED

#include "OutputStream.h"

class Duplicator : public OutputStream
{
public:
    Duplicator(OutputStream* stream1, OutputStream* stream2);
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();

protected:
    OutputStream* stream1Ptr;
    OutputStream* stream2Ptr;

private:
    Duplicator(const Duplicator&);
    void operator=(const Duplicator&);
};

#endif //DUPLICATOR_HEADER_INCLUDED
