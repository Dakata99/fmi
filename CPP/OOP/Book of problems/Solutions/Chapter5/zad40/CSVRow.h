#ifndef _CSW_ROW_HEADER_INCLUDED_
#define _CSW_ROW_HEADER_INCLUDED_

#include <iostream.h>

class CSVRow
{
public:
    CSVRow(char** fields = NULL, unsigned int n = 0);
    CSVRow(const CSVRow &row);
    ~CSVRow();
    CSVRow& operator=(const CSVRow &right);
    void addField(const char* name);
    void addValue(const char* v);
    const char* field(unsigned int n) const;
    const char* operator[](unsigned int n) const;
    const char* operator[](const char *f) const;
    void clearValues();

protected:    // помощни функции
    char** copyRow(char** const data, unsigned int cnt);
    void clearRow(char** row);
    void deleteRow(char** row);
    char** addToRow(char** row, const char* value);

protected:
    char** header;
    char** values;
    unsigned int fieldsCnt;
};

#endif //_CSW_ROW_HEADER_INCLUDED_
