#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 256;

// прочита от поток един ред и връща дължината му
int get_row_length(istream & in)
{
    int length = 0;
    char ch = in.get();
    if(!in) return -1;
    while(ch != '\n' && in)
    {
        ++length;
        ch = in.get();
    }
    return length;
}

int main()
{
    char file_name[MAX_PATH_SIZE];
    cout << "Име на входен файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream in_file(file_name);
    if(!in_file)
    {
        cerr << "Не може да се отвори " << file_name << '\n';
        return 1;
    }
    int max_length  = -1,
        longest_row = -1;
    int row_index, row_length;
    for(row_index = 1;
        (row_length = get_row_length(in_file)) >= 0; 
        ++row_index)
    {
        if(row_length > max_length)
        {
            max_length = row_length;     
            longest_row = row_index;
        }
    }
    in_file.close();
    if(longest_row >= 0)
    {
        cout << "Номер на най-дългия ред " << longest_row << endl;
    }
    else
    {
        cout << "Файлът е празен." << endl;
    }
    return 0;
}
