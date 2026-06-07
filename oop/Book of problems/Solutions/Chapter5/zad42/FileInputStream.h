#ifndef FILE_INPUT_SREAM_HEADER_INCLUDED
#define FILE_INPUT_SREAM_HEADER_INCLUDED

#include <iostream.h>
#include <fstream.h>
#include "InputStream.h"

class FileInputStream : public InputStream
{ 
public:
    FileInputStream(const char* fileName);
    ~FileInputStream();
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();

protected:
    ifstream file;

private:
    FileInputStream(const FileInputStream&);
    void operator=(const FileInputStream&);
};

#endif //FILE_INPUT_SREAM_HEADER_INCLUDED
