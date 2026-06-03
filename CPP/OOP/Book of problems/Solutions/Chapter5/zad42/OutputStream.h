#ifndef OUTPUT_STREAM_HEADER_INCLUDED
#define OUTPUT_STREAM_HEADER_INCLUDED

class OutputStream
{ 
public:
    virtual int GetPosition() = 0;
    virtual int GetLength() = 0;
    virtual void Seek(int position) = 0;
    virtual int Write(const unsigned char *buffer, int size) = 0;
    virtual int CanGetPosition() = 0;
    virtual int CanGetLength() = 0;
    virtual int CanSeek() = 0;
    virtual void Flush() = 0;
};


#endif //OUTPUT_STREAM_HEADER_INCLUDED
