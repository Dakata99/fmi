#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

int main()
{
    char file_name[MAX_PATH_SIZE];
    cout << "Име на входен файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream f(file_name);
    if(!f)
    {
        cerr << "Не може да се отвори " << file_name << '\n';
        return 1;
    }
    char ch;
    f.seekg(7, ios::beg);
    f.get(ch);
    cout << "Символ 7-ми от началото: " << ch << endl;
    f.seekg(-7, ios::end);
    f.get(ch);
    cout << "Символ 7-ми от края: " << ch << endl;
    f.seekg(3, ios::cur);
    f.get(ch);
    cout << "Символ 3-ти от текущата позиция: " << ch << endl;
    f.close();
    return 0;
}
