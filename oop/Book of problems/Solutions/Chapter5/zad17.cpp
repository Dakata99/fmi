#include <iostream.h>

int main()
{
    long i = cout.flags();
    if(i & ios::skipws) cout << "skipws on\n";
    else cout << "skipws off\n";
    if(i & ios::left) cout << "left on\n";
    else cout << "left off\n";
    if(i & ios::right) cout << "right on\n";
    else cout << "right off\n";
    if(i & ios::internal) cout << "internal on\n";
    else cout << "internal off\n";
    if(i & ios::dec) cout << "dec on\n";
    else cout << "dec off\n";
    if(i & ios::oct) cout << "oct on\n";
    else cout << "oct off\n";
    if(i & ios::hex) cout << "hex on\n";
    else cout << "hex off\n";
    if(i & ios::showbase) cout << "showbase on\n";
    else cout << "showbase off\n";
    if(i & ios::showpoint) cout << "showpoint on\n";
    else cout << "showpoint off\n";
    if(i & ios::showpos) cout << "showpos on\n";
    else cout << "showpos off\n";
    if(i & ios::uppercase) cout << "uppercase on\n";
    else cout << "uppercase off\n";
    if(i & ios::scientific) cout << "scientific on\n";
    else cout << "scientific off\n";
    if(i & ios::fixed) cout << "fixed on\n";
    else cout << "fixed off\n";
    if(i & ios::unitbuf) cout << "unitbuf on\n";
    else cout << "unitbuf off\n";
    return 0;
}
