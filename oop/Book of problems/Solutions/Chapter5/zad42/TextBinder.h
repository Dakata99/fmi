#ifndef TEXT_BINDER_HEADER_INCLUDED
#define TEXT_BINDER_HEADER_INCLUDED

#include "InputStream.h"

class TextBinder : public InputStream
{
public:
    TextBinder(InputStream* firstStream, InputStream* secondStream);
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Read(unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();

protected:
    InputStream* streams[2];
    // Първите символи на следващата дума
    unsigned char first[2];
    int position;
    int activeStream;

private:
    TextBinder(const TextBinder&);
    void operator=(const TextBinder&);
};

#endif // TEXT_BINDER_HEADER_INCLUDED
