#include <iostream.h>
#include <string.h>

// дефиниране на манупулатора inptext
istream& inptext(istream& istr)
{
    cout << "\a" << "Въведете текст: ";
    return istr;
}

int main()
{
    char str[80];
    do
    {
        cin >> inptext >> str;
    } while(strcmp(str, "star123"));
    return 0;
}
