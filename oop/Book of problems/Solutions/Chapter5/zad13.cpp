#include <iostream.h>

int main()
{
    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase | ios::uppercase);
    cout << 106 << endl;
    cout.unsetf(ios::uppercase);
    cout << 106 << endl;
    return 0;
}
