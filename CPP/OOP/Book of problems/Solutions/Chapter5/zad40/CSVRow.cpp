#include <string.h>
#include "CSVRow.h"

CSVRow::CSVRow(char **fields, unsigned int n) :
fieldsCnt(0), header(NULL), values(NULL)
{
    header = copyRow(fields, n);
    values = copyRow(NULL, n);
    fieldsCnt = n;
}

CSVRow::CSVRow(const CSVRow &row) :
fieldsCnt(0), header(NULL), values(NULL)
{
    header = copyRow(row.header, row.fieldsCnt);
    values = copyRow(row.values, row.fieldsCnt);
    fieldsCnt = row.fieldsCnt;
}

CSVRow& CSVRow::operator =(const CSVRow &right)
{
    if(&right != this)
    {
        deleteRow(header);
        header = copyRow(right.header, right.fieldsCnt);
        deleteRow(values);
        values = copyRow(right.values, right.fieldsCnt);
        fieldsCnt = right.fieldsCnt;
    }
    return * this;
}

CSVRow::~CSVRow()
{
    deleteRow(values);
    deleteRow(header);
}

void CSVRow::addField(const char *name)
{
    header = addToRow(header, name);
    values = addToRow(values, NULL);
    ++fieldsCnt;
}

void CSVRow::addValue(const char *v)
{
    if(!v) return;
    unsigned int i;
    for(i = 0; i < fieldsCnt; ++i)
    {
        if(!values[i]) break;
    }
    if(i < fieldsCnt)
    {
        values[i] = new char[strlen(v) + 1];
        strcpy(values[i], v);
    }
}

const char* CSVRow::field(unsigned int n) const
{
    return n < fieldsCnt ? header[n] : NULL;
}

const char* CSVRow::operator [](unsigned n) const
{
    return n < fieldsCnt ? values[n] : NULL;
}

const char* CSVRow::operator [](const char *f) const
{
    if(!f) return NULL;
    for(unsigned int i = 0; i < fieldsCnt; ++i)
    {
        if(!strcmp(header[i], f))
            return values[i];
    }
    return NULL;
}

void CSVRow::clearValues()
{
    clearRow(values);
}

char** CSVRow::copyRow(char** const data, unsigned int cnt)
{
    char** result = new char*[cnt];
    for(unsigned int i = 0; i < cnt; ++i)
    {
        if(data && data[i])
        {
            result[i] = new char[strlen(data[i])+1];
            strcpy(result[i], data[i]);
        }
        else
        {
            result[i] = NULL;
        }
    }
    return result;
}

void CSVRow::clearRow(char** row)
{
    for(unsigned int i = 0; i < fieldsCnt; ++i)
    {
        delete [] row[i];
        row[i] = NULL;
    }
}

void CSVRow::deleteRow(char** row)
{
    clearRow(row);
    delete [] row;
}

char** CSVRow::addToRow(char** row, const char* value)
{
    char** result = new char*[fieldsCnt+1];
    for(unsigned int i = 0; i < fieldsCnt; ++i)
    {
        result[i] = row[i];
    }
    if(value)
    {
        result[fieldsCnt] = new char[strlen(value)+1];
        strcpy(result[fieldsCnt], value);
    }
    else
    {
        result[fieldsCnt] = NULL;
    }
    delete[] row;
    return result;
}
