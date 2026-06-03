#include <iostream.h>
#include <iomanip.h>

int main()
{
    //à)
    cout << "12345" << endl;
    cout.width(5); cout.fill('*');
    cout << 123 << endl;
    //á)
    cout << setw(10) << setfill('$') << 1000 ;
    cout << endl;
    //â)
    cout << setw(8) << setfill('$') 
         << setprecision(5) << 1024.987654;
    cout << endl;
    //ã)
    cout << setiosflags(ios::showbase) << oct << 99
         << endl << hex << 99;
    cout << dec << endl;
    //ä)
    cout << 10000 << endl
         << setiosflags(ios::showpos) << 10000;
    cout << endl;
    //å)
    cout << setfill('$') << setw(10) << setprecision(2)
         << setiosflags(ios::scientific) << 444.93738 << endl;
    return 0;
}
