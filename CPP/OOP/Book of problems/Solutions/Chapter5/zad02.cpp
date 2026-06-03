#include <iostream.h>

int main()
{
    ////à) 
    char str1[51];
    cin.read(str1, 50);
    str1[50] = '\0';
    cout << str1;

    ////á) 
    char str2[11];
    cin.get(str2, 11, '.');
    cout << str2;

    ////â) 
    char str3[11];
    cin.getline(str3, 11, '.');
    cout << str3;

    return 0;
}
