#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 256;

int main()
{
    char file_name[MAX_PATH_SIZE];
    ifstream file;
    cout << "Въведете име на файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    file.open(file_name, ios::nocreate);
    if(file.fail())
    {
        cout << "Файлът " << file_name << " не съществува." << endl;
    }
    else
    {
        cout << "Файлът " << file_name << " съществува." << endl;
    }
    file.close();
    return 0;
}
