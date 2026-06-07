#include <iostream.h>

int main()
{
    cout << -5234.809 << " C++ OOP " << 520 << endl;
    cout << 20 << " " << -40 << '\n';
    cout << 251.00 << "\n\n";
    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::scientific);
    cout << 18.345 << " C++ OOP " << 50 << endl;
    cout.setf(ios::showpos);
    cout << 18 << " " << -13 << endl;
    cout.unsetf(ios::scientific);
    cout.setf(ios::fixed);
    cout << 250.0 << " " << 18 << endl;
    return 0;
}
