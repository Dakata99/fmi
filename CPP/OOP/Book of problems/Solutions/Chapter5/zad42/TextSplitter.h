#ifndef TEXT_SPLITTER_HEADER_INCLUDED
#define TEXT_SPLITTER_HEADER_INCLUDED

#include "OutputStream.h"

class TextSplitter : public OutputStream
{
public:
    TextSplitter(OutputStream* stream1, OutputStream* stream2);
    virtual int  GetPosition();
    virtual int  GetLength();
    virtual void Seek(int position);
    virtual int  Write(const unsigned char *buffer, int size);
    virtual int  CanGetPosition();
    virtual int  CanGetLength();
    virtual int  CanSeek();
    virtual void Flush();

protected:
    OutputStream* streams[2];
    int activeStream;

private:
    TextSplitter(const TextSplitter&);
    void operator=(const TextSplitter&);
};

#endif //TEXT_SPLITTER_HEADER_INCLUDED
