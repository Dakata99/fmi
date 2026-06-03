#ifndef _CSV_READER_HEADER_INCLUDED_
#define _CSV_READER_HEADER_INCLUDED_

#include <fstream.h>
#include "CSVRow.h"

class CSVReader
{
public:
    CSVReader(const char* f);
    fstream& input();
    void input(const char* f);
    CSVRow readHeader();
    void readRow(CSVRow& r);

protected:
    unsigned int readLine(char**& row);
    char* getElement();
    void append(char**& row, char* elem, unsigned int cnt) const;

protected:
    fstream file;

private:
    // «абран€ва се копирането на обекти от този клас.
    CSVReader(const CSVReader&);
    void operator=(const CSVReader&);
};

#endif //_SCV_READER_HEADER_INCLUDED_
