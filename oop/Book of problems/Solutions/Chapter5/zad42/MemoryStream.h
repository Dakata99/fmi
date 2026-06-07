#ifndef MEMORY_STREAM_HEADER_INCLUDED
#define MEMORY_STREAM_HEADER_INCLUDED

#include <string.h>
#include "InputStream.h"
#include "OutputStream.h"

class MemoryStream : public OutputStream,
                     public InputStream
{
public:
    MemoryStream();
    MemoryStream(const unsigned char* buffer, int size);
    MemoryStream(const MemoryStream&);
    MemoryStream& operator=(const MemoryStream&);
    ~MemoryStream();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();
    void GetBuffer(unsigned char *& buffer, size_t& size);

protected:
    unsigned char * buffer;
    int bufferSize;
    int position;
    int length;
    static const size_t defaultSize;

private:
    void EnsureSize(int size);
};

#endif //MEMORY_STREAM_HEADER_INCLUDED
