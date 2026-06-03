#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 256;

int main()
{
    char file_name[MAX_PATH_SIZE];
    // отваряне на входния файл
    cout << "Име на входния файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream in_file(file_name);
    if(!in_file)
    {
        cerr << "Не може да се отвори файлът "
            << file_name << '\n';
        return 1;
    }
    // отваряне на изходния файл
    cout << "Име на изходния файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ofstream out_file(file_name);
    if(!out_file)
    {
        cerr << "Не може да се отвори файлът " 
            << file_name << '\n';
        in_file.close();
        return 1;
    }

    char ch;
    // записване в изходния файл на всеки символ
    // от входния файл, който не е интервал
    while(in_file.get(ch))
        if(ch != ' ') out_file.put(ch);
    in_file.close();
    out_file.close();
    return 0;
}
