#include <string.h>
#include "CSVWriter.h"

CSVWriter::CSVWriter(const char* f)
                     : fieldsCnt(0), header(NULL)
{ 
    output(f);
}

CSVWriter::~CSVWriter()
{
    for(unsigned int i = 0; i < fieldsCnt; ++i)
        delete[] header[i];
    delete[] header;
}

fstream& CSVWriter::output()
{
    return file;
}

void CSVWriter::output(const char* f)
{
    if(file.is_open())
    {
        file.close();
    }
    file.open(f, ios::out|ios::trunc);
}

void CSVWriter::addField(const char *n)
{
    if(!n) return;
    char** tmp = new char*[fieldsCnt + 1];
    for(unsigned int i = 0; i < fieldsCnt; ++i)
        tmp[i] = header[i];
    delete[] header;
    tmp[fieldsCnt] = new char[strlen(n) + 1];
    strcpy(tmp[fieldsCnt], n);
    header = tmp;
    ++fieldsCnt;
}

void CSVWriter::writeHeader()
{
    if(!fieldsCnt) return;
    file << '\"' << header[0] << '\"';
    for(unsigned int i = 1; i < fieldsCnt; ++i)
        file << ", \"" << header[i] << '\"';
    file << endl;
}

void CSVWriter::writeRow(const CSVRow &r)
{
    if(!fieldsCnt) return;
    file << '\"' << (r[0u] ? r[0u] : "NULL") << '\"';
    for(unsigned int i = 1; i < fieldsCnt; ++i)
        file << ", \"" << (r[i] ? r[i] : "NULL") << '\"';
    file << endl;
}
