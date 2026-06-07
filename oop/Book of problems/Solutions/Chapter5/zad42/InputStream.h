#ifndef INPUT_STREAM_HEADER_INCLUDED
#define INPUT_STREAM_HEADER_INCLUDED

class InputStream
{ 
public:
    virtual int GetPosition() = 0;
    virtual int GetLength() = 0;
    virtual void Seek(int position) = 0;
    virtual int Read(unsigned char *buffer, int size) = 0;
    virtual int CanGetPosition() = 0;
    virtual int CanGetLength() = 0;
    virtual int CanSeek() = 0;
}; 


#endif //INPUT_STREAM_HEADER_INCLUDED
