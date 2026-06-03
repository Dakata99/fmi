#include <iostream.h>
#include <fstream.h>

int main()
{ 
    ifstream InFile("Rab.dat", ios::in);
    if(!InFile)
    { 
        cout << "Rab.dat" << " не може да се отвори!\n";
        return 1;
    }
    int a;
    double x;
    char str[7];
    InFile.read((char*)&x, sizeof(double));
    InFile.read(str, 6); str[6] = '\0';
    InFile.read((char*)&a, sizeof(int));
    cout << x << " " << str << " " << a << endl;
    InFile.close();
    return 0;
}
