#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

void make_format(ifstream&, ofstream&, int, int);

int main()
{
    char file_name1[MAX_PATH_SIZE];
    cout << "Име на входния файл: ";
    cin.getline(file_name1, MAX_PATH_SIZE);
    ifstream f1(file_name1);
    if(!f1)
    {
        cerr << "Не може да се отвори " << file_name1 << '\n';
        return 1;
    }
    char file_name2[MAX_PATH_SIZE];
    cout << "Име на изходния файл: ";
    cin.getline(file_name2, MAX_PATH_SIZE);
    ofstream f2(file_name2);
    if(!f2)
    {
        cerr << "Не може да се отвори " << file_name2 << '\n';
        return 1;
    }
    make_format(f1, f2, 5, 12);
    cout << "Край на програмата.\n";
    f1.close();
    f2.close();
    return 0;
}

void make_format(ifstream& f1, ofstream& f2, 
                 int num_after_decimalpoint, int field_width)
{
    f2.setf(ios::fixed);
    f2.setf(ios::showpoint);
    f2.setf(ios::showpos);
    f2.precision(num_after_decimalpoint);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(num_after_decimalpoint);
    double number;
    while(f1 >> number)
    { 
        f2 << setw(field_width) << number << endl;
        cout << setw(field_width) << number << endl;
    }
}
