#include "TextSplitter.h"
#include <assert.h>
#include <ctype.h> //isspace

TextSplitter::TextSplitter(OutputStream* stream1, OutputStream* stream2) :
                           activeStream(0)
{
    assert(stream1);
    assert(stream2);
    streams[0] = stream1;
    streams[1] = stream2;
}

int TextSplitter::GetPosition()
{
    return -1;
}

int TextSplitter::GetLength()
{
    return -1;
}

void TextSplitter::Seek(int position)
{
}

int TextSplitter::Write(const unsigned char * buffer, int size)
{
    assert(buffer);
    const static unsigned char space = ' '; // Символ разделител
    for(int i = 0; i < size; ++i)
    {
        if(isspace(buffer[i]))
        {
            streams[activeStream]->Write(&space, 1);
            activeStream = 1-activeStream;
            while(isspace(buffer[i]) && i < size)
                ++i;
        }
        if(i < size)
        {
            if(!streams[activeStream]->Write(buffer+i, 1))
            {
                return i;
            }
        }
    }
    return size;
}

int TextSplitter::CanGetPosition()
{
    return 0;
}

int TextSplitter::CanGetLength()
{
    return 0;
}

int TextSplitter::CanSeek()
{
    return 0;
}

void TextSplitter::Flush()
{
    streams[0]->Flush();
    streams[1]->Flush();
}
