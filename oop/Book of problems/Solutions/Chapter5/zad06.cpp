#include <iostream.h>

int main()
{
    unsigned int count = 0;
    int number;
    int sum = 0;
    cin.clear();   // задаване на добро начално състояние на cin
    cin >> number;
    while(cin.good())
    {
        sum += number;
        ++count;
        cin >> number;
    }
    cin.clear();  // възстановяване на добро състояние на потока
    if(count)
    {
        cout << "Средно аритметичното на въведените числа е "
             << (double)sum/count << endl;
    }
    else
    {
        cout << "Не са въведени числа." << endl;
    }
    return 0;
}
