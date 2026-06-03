#ifndef _ARCHIVE_HEADER_INCLUDED_
#define _ARCHIVE_HEADER_INCLUDED_

#include <iostream.h>
#include <fstream.h>

class Archive
{
public:
    Archive(const char* archiveName, bool deleteIfExist = true);
    ~Archive();
    bool AddFile(const char* fileName, const char* keyword = NULL);
    int GetTotalSize() const;
    bool ExtractAll(const char* directoryName, const char* keyword = NULL);
protected:
    void codeBuffer(char* buffer, int size,
                    const char* keyword, 
                    size_t keyLen, size_t& keyPosition) const;
    int writeName(const char* fileName);
    void actualizeSize(int fileSize, int startPosition);
    int extractFile(const char *directoryName, const char *keyword);
    char* getOutputFileName(const char *directoryName);

protected:
    // Файл на архива
    fstream file;
    // Общ размер на файловете в архива
    unsigned int totalSize;
    // Размер на буфера за четене/записване
    static const int bufferSize;
    // Символ – разделител на пътя
    static const char pathSeparator;

private:
    // Забранява се копирането
    Archive(const Archive&);
    void operator=(const Archive&);
};

#endif //_ARCHIVE_HEADER_INCLUDED_
