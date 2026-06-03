#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

int main()
{
    char file_name1[MAX_PATH_SIZE];

    cout << "Име на входен файл: ";
    cin.getline(file_name1, MAX_PATH_SIZE);
    ifstream in_file(file_name1);
    if(!in_file)
    {
        cerr << "Не може да се отвори " << file_name1 << '\n';
        return 1;
    }

    // сканиране на елементите на файла за намиране
    // на средно аритметичното на елементите му
    double numb,
           sum = 0.0,
           average = 0.0;
    int count = 0;
    while(in_file >> numb)
    {
        sum += numb;
        count++;
    }

    if(count > 0)
        average = sum/count;
    // подготовка на in_file за повторното сканиране
    in_file.clear();                // изчиства eof бита
    in_file.seekg(0, ios::beg);     // поставя get указателя в началото на файла
    
    char file_name2[MAX_PATH_SIZE];
    cout << "Име на изходен файл: ";
    cin.getline(file_name2, MAX_PATH_SIZE);
    ofstream out_file(file_name2);
    if(!out_file)
    {
        cerr << "Не може да се отвори " << file_name2 << '\n';
        in_file.close();
        return 1;
    }

    // създаване на файл, съдържащ разликата
    // на всяко число на дадения файл със
    // средно аритметичното число
    while(in_file >> numb)
        out_file << numb - average << endl;

    in_file.close();
    out_file.close();
    return 0;
}
