#include <iostream.h>
#include <string.h>
#include <fstream.h>

int main()
{
    ofstream OutFile("Rab.dat", ios::out);
    if(!OutFile)
    {
        cout << "Rab.dat" << " не може да се отвори!\n";
        return 1;
    }
    double x = 8.25;
    char str[] = "string";
    int a = 235;
    OutFile.write((const char*)&x, sizeof(double));
    OutFile.write(str, strlen(str));
    OutFile.write((const char*)&a, sizeof(int));
    OutFile.close();
    return 0;
}
