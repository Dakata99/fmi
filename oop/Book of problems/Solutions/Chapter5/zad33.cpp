#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

int main()
{
    char file_name[MAX_PATH_SIZE];
    cout << "Име на входен файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ofstream f(file_name, ios::ate|ios::nocreate);
    if(!f)
    {
        cerr << "Не може да се отвори " << file_name << '\n';
        return 1;
    }
    char ch;
    cout << "ch= "; cin >> ch;
    f.seekp(7, ios::beg);
    f.put(ch);
    f.seekp(-7, ios::end);
    f.put(ch);
    f.close();
    return 0;
}
