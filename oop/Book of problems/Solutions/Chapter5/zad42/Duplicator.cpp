#include "Duplicator.h"
#include <assert.h>

Duplicator::Duplicator(OutputStream* stream1, OutputStream* stream2) :
                       stream1Ptr(stream1), stream2Ptr(stream2)
{
    assert(stream1);
    assert(stream2);
}

int Duplicator::GetPosition()
{
    return -1;
}

int Duplicator::GetLength()
{
    return -1;
}

void Duplicator::Seek(int position)
{
    // Тук не може да се реализира позициониране
}

// Записват се данните последователно в двата подадени потока
// Ако в първия не може да се запишат всички данни, във втория
// се записват толкова, колкото са записани в първия.
int Duplicator::Write(const unsigned char * buffer, int size)
{
    int written = stream1Ptr->Write(buffer, size);
    return stream2Ptr->Write(buffer, written);
}

int Duplicator::CanGetPosition()
{
    return 0;
}

int Duplicator::CanGetLength()
{
    return 0;
}

int Duplicator::CanSeek()
{
    return 0;
}

void Duplicator::Flush()
{
    stream1Ptr->Flush();
    stream2Ptr->Flush();
}
