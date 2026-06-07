#include "TextBinder.h"
#include <assert.h>
#include <ctype.h> //isspace

TextBinder::TextBinder(InputStream * stream1, InputStream * stream2) :
                       position(0), activeStream(0)
{
    assert(stream1);
    assert(stream2);
    first[0] = first[1] = 0;
    streams[0] = stream1;
    streams[1] = stream2;
    streams[0]->Seek(0);
}

int TextBinder::GetPosition()
{
    return position;
}

int TextBinder::GetLength()
{
    return -1;
}

void TextBinder::Seek(int position)
{
}

int TextBinder::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    const static unsigned char space = ' '; // разделител
    unsigned char ch;
    static bool one_stream = false;
    for(int i = 0; i < size; ++i)
    {
        // Ако има запомнен символ, използва се
        if(first[activeStream])
        {
            ch = first[activeStream];
            first[activeStream] = 0;
        }
        else
        {
            if(!streams[activeStream]->Read(&ch, 1))
            { 
                // Ако единият поток е свършил
                activeStream = 1-activeStream;
                if(one_stream)  // и двата са свършили
                { 
                    position += i;
                    return i;
                }
                else 
                { 
                    one_stream = true; 
                    --i;  // заради увеличаването на i в цикъла
                    continue;
                }
            }
        }
        if(isspace(ch))  // Ако е интервал
        { 
            buffer[i] = space;
            int res;
            // прескачат се празните символи
            while(isspace(ch) && (res = streams[activeStream]->Read(&ch, 1)))
                ;
            first[activeStream] = res ? ch : 0;
            // Ако има данни в другия поток, сменят се потоците
            if(!one_stream)
            {
                activeStream = 1 - activeStream;
            }
        }
        else
        { 
            buffer[i] = ch;
        }
    }
    position += size;
    return size;
}

int TextBinder::CanGetPosition()
{
    return true;
}

int TextBinder::CanGetLength()
{
    return false;
}

int TextBinder::CanSeek()
{
    return false;
}
