#ifndef COPY_PROCESSOR_HEADER_INCLUDED
#define COPY_PROCESSOR_HEADER_INCLUDED

#include <string.h>
#include "InputStream.h"
#include "OutputStream.h"
#include "Processor.h"

class CopyProcessor : public Processor
{
public:
    CopyProcessor(InputStream* input, OutputStream* output);
    virtual void Process();

protected:
    InputStream * input;
    OutputStream * output;
    static const size_t buffer_size;
};

#endif // COPY_PROCESSOR_HEADER_INCLUDED
