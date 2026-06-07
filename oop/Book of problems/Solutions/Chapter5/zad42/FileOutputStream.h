#ifndef FILE_OUTPUT_STREAM_HEADER_INCLUDED
#define FILE_OUTPUT_STREAM_HEADER_INCLUDED

#include <iostream.h>
#include <fstream.h>
#include "OutputStream.h"

class FileOutputStream : public OutputStream
{ 
public:
    FileOutputStream(const char* fileName);
    ~FileOutputStream();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();

protected:
    ofstream file;

private:
    FileOutputStream(const FileOutputStream&);
    void operator=(const FileOutputStream&);
};

#endif //FILE_OUTPUT_STREAM_HEADER_INCLUDED
