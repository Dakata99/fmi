#include "Archive.h"
#include <assert.h>    // assert
#include <string.h>

const int Archive::bufferSize = 1024;
const char Archive::pathSeparator = '/';

// Конструктор
Archive::Archive(const char* archiveName, bool deleteIfExist)
                 : totalSize(0)
{
    // Задължително трябва да се подаде име
    assert(archiveName);
    // Ако не искаме да бъде изтрит файлът
    if(!deleteIfExist)
    {
        file.open(archiveName, ios::binary|ios::in|ios::out|ios::nocreate);
    }

    // Ако не се е отворил файлът, опит за създаване
    if(!file.is_open())
    { 
        file.open(archiveName, ios::binary|ios::in|ios::out|ios::trunc);
        if(file.is_open())
        {
            // Ако е отворен, записване на общия размер в началото
            file.clear();
            file.write((char*)&totalSize, sizeof(totalSize));
            file.flush();
        }
    }
    else
    {
        if(file.good())
        { 
            // Ако е отворен съществуващ файл, се прочита общият размер
            file.read((char*)&totalSize, sizeof(totalSize));
        }
    }
}

// Деструктор
Archive::~Archive()
{
    if(file.is_open())
    {
        file.close();
    }
}

// Добавяне на файл в края на архива
// Връща истина при успех и лъжа при възникване на грешка
bool Archive::AddFile(const char* fileName,
                      const char* keyword)
{
    if(!file.is_open() || !fileName) return false;
    ifstream in(fileName, ios::in|ios::binary);
    if(!in) return false;

    // Записване на името на файла
    int startPosition  = writeName(fileName);
    size_t keyLen = keyword ? strlen(keyword) : 0;
    size_t keyPosition = 0;
    char buffer[bufferSize];
    int readed, total = 0;

    // Записване на съдържанието на файла
    while(in)
    {
        in.read(buffer, bufferSize);
        readed = in.gcount();
        codeBuffer(buffer, readed, keyword, keyLen, keyPosition);
        file.write(buffer, readed);
        total += readed;
    }

    // Отбелязване на новия общ размер
    actualizeSize(total, startPosition);
    file.flush();
    return true;
}

// Връщане на общия размер на всички файлове в архива
int Archive::GetTotalSize() const
{
    return totalSize;
}

// Изваждане на всички файлове от архива в дадена директория
// Връща истина при успех и лъжа при възникване на грешка
bool Archive::ExtractAll(const char *directoryName,
                         const char *keyword)
{
    if(!directoryName || !file) return false;
    unsigned int total = 0;

    // Позициониране преди първия файл
    file.seekg(sizeof(totalSize));

    while(total < totalSize)
    {
        total += extractFile(directoryName, keyword);
    }

    return true;
}

// Кодира или декодира даден буфер
// Тъй като използваният алгоритъм е симетричен,
// се използва една функция за двете операции
void Archive::codeBuffer(char *buffer, int size,
                         const char *keyword, size_t keyLen, size_t &keyPosition) const
{
    if(keyLen)
    {
        for(int i = 0; i < size; ++i)
        {
            buffer[i] ^= keyword[keyPosition];
            keyPosition = (keyPosition+1)%keyLen;
        }
    }
}

// Записване на името на файла в архива
// Оставя място за размера на файла
int Archive::writeName(const char*fileName)
{
    assert(fileName);
    file.seekp(0, ios::end);
    int position = file.tellp();
    int size = 0;
    file.write((char*)&size, sizeof(size));
    size = (int)strlen(fileName);
    file.write((char*)&size, sizeof(size));
    file.write(fileName, size);
    return position;
}

// Актуализиране на размера на файл и
// на общия размер на файловете в архива
void Archive::actualizeSize(int fileSize, int startPosition)
{
    file.seekp(startPosition);
    file.write((char*)&fileSize, sizeof(fileSize));
    totalSize += fileSize;
    file.seekp(0);
    file.write((char*)&totalSize, sizeof(totalSize));
}

// Изваждане на един файл от архива
int Archive::extractFile(const char* directoryName,
                         const char* keyword)
{
    assert(directoryName);
    int fileSize;
    file.read((char*)&fileSize, sizeof(fileSize));

    // Създаване на името на изходния файл
    char* outFileName = getOutputFileName(directoryName);
    ofstream out(outFileName, ios::binary|ios::trunc);
    delete[] outFileName;
    
    // Записване на съдържанието на файла
    if(out.is_open())
    {
        out.clear();
        char buffer[bufferSize];
        size_t keyLen = keyword ? strlen(keyword) : 0;
        size_t keyPosition = 0;
        int left = fileSize;
        int toRead;
        while(left)
        {
            toRead = bufferSize < left ? bufferSize : left;
            file.read(buffer, toRead);
            if(file.gcount() < toRead)
                break;
            left -= toRead;
            codeBuffer(buffer, toRead, keyword, keyLen, keyPosition);
            out.write(buffer, toRead);
        }
    }
    return fileSize;
}

// Създаване на името на изходния файл като към името на
// директорията се добавя името на файла от архива
char* Archive::getOutputFileName(const char* directoryName)
{
    assert(directoryName);
    int dirNameLen = (int)strlen(directoryName);
    int nameLen;
    file.read((char*)&nameLen, sizeof(nameLen));
    int totalNameLen = dirNameLen + nameLen;

    // Ако името на директорията не завършва с '\'
    if(directoryName[dirNameLen-1] != pathSeparator)
        totalNameLen += 1;
    char* name = new char[totalNameLen + 1];
    strncpy(name, directoryName, dirNameLen);
    
    // Ако няма '\', се добавя
    if(directoryName[dirNameLen-1] != pathSeparator)
    {
        name[dirNameLen] = pathSeparator;
        ++dirNameLen;
    }
    file.read(name + dirNameLen, nameLen);
    name[totalNameLen] = '\0';
    return name;
}
