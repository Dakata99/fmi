#include <iostream.h>
#include <fstream.h>

int main()
{
    const char* file_name = "Rab.dat";

    // отваряне на файл за записване в него
    ofstream OutFile(file_name, ios::out);
    if(!OutFile)
    {
        cout << file_name << " не може да се отвори!\n";
        return 1;
    }

    // въвеждане на елементите на масив
    int a[10], b, i;
    for(i = 0; i < 10; i++)
    { 
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // записване на елементите на масива във файла
    for(i = 0; i < 10; i++)
        OutFile.write((const char*)&a[i], sizeof(int));
    OutFile.close();

    // отваряне на файла за четене от него
    ifstream InFile(file_name, ios::in);
    if(!InFile)
    { 
        cout << file_name << " не може да се отвори!\n";
        return 1;
    } 
    i = 0; double s = 0;

    // сканиране на елементите на файла, извеждане
    // и намиране на средно аритметичното им
    InFile.read((char*)&b, sizeof(int));
    while(InFile.good())        // или !Infile.eof()
    {
        cout << b << " "; i++;
        s += b;
        InFile.read((char*)&b, sizeof(int));
    }
    // извеждане на средно аритметичното
    // на елементите на файла
    if(i)
    {
        cout << s/i << endl;
    }
    else
    {
        cout << "Няма числа във файла" << endl;
    }
    InFile.close();
    return 0;
}
