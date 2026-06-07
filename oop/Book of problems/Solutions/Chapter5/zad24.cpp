#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>  // system();

// Функцията чете всички символи на поток и търси кой символ колко пъти се среща.
// Тази информация се записва в масива histogram.
// Връща общия брой символи във файла.
unsigned int count_symbols(ifstream& file, unsigned int histogram[])
{
    char ch;
    unsigned int total = 0;
    for(int i = 0; i <= 255; ++i)
        histogram[i] = 0;
    while(!file.eof())
    {
        file.get(ch);
        if (file)
        {
            ++histogram[(unsigned char)ch];
            ++total;
        }
    }
    return total;
}

// Извежда на екрана събраната в histogram информация.
void print(unsigned int histogram[], unsigned int total)
{
    int rows = 0;
    cout << "CHAR\tCODE\tTIMES\tPERCENTS\n";
    for(int i = 0; i <= 255; ++i)
    {
        cout << (char)i << '\t' << i << '\t' 
             << histogram[i] << '\t'
             << ((double)histogram[i] * 100) / total
             << endl;
        if(!((i+1) % 23))
        { 
            system("pause");    // Изпълнява командата pause
            cout << "CHAR\tCODE\tTIMES\tPERCENTS\n";
        }
    }
}

int main()
{
    const char * file_name = "test.txt";
    ifstream file(file_name);
    if(!file)
    {
        cerr << "Не може да се отвори файлът "
             << file_name << '\n';
        return 1;
    }
    unsigned int histogram[256];
    unsigned int total = count_symbols(file, histogram);
    file.close();
    print(histogram, total);
    return 0;
}
