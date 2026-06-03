#ifndef FILE_STREAM_HEADER_INCLUDED
#define FILE_STREAM_HEADER_INCLUDED

#include <iostream.h>
#include <fstream.h>
#include "InputStream.h"
#include "OutputStream.h"

class FileStream : public OutputStream,
                   public InputStream
{
public:
    FileStream(const char* fileName);
    ~FileStream();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();

protected:
    fstream file;

private:
    FileStream(const FileStream&);
    void operator=(const FileStream&);
};

#endif //FILE_STREAM_HEADER_INCLUDED
