#ifndef _CSV_WRITER_HEADER_INCLUDED_
#define _CSV_WRITER_HEADER_INCLUDED_

#include <fstream.h>
#include "CSVRow.h"

class CSVWriter
{
public:
    CSVWriter(const char* f);
    ~CSVWriter();
    fstream& output();
    void output(const char* f);
    void addField(const char* n);
    void writeHeader();
    void writeRow(const CSVRow& r);

protected:
    char** header;
    unsigned int fieldsCnt;
    fstream file;

private:
    // Забранява се копирането на обекти
    CSVWriter(const CSVWriter &);
    void operator=(const CSVWriter &);
};

#endif //_CSV_WRITER_HEADER_INCLUDED_
