#include <iostream.h>
#include <iomanip.h>

int main()
{
    //à) 
    cout << setprecision(3) << 1.92 << endl
         << 1.925 << endl << 1.9258 << endl;

    //á)
    cout << setw(10) << setiosflags(ios::right)
         << 12345 << endl;

    //â)
    cout << setw(15) << setiosflags(ios::left)
         << 40000 << endl;

    //ã)
    cout << 250 << endl << setiosflags(ios::showpos)
         << 250 << endl;

    //ä)
    cout << hex << setiosflags(ios::showbase)
         << 100 << endl;

    //å)
    cout << setw(9) << setfill('0')
         << 1.234 << endl;

    //æ)
    for(int i = 1; i <= 5; i++)
        cout << setprecision(3+i) << 100.456273 << endl;

    return 0;
}
