#include <iostream.h>
#include <iomanip.h>

// дефиниране на манупулатора my
ostream& my(ostream& ostr)
{
    ostr << setw(12) << setprecision(3) 
         << setfill('#') << setiosflags(ios::fixed);
    return ostr;
}

int main()
{
    double x; cin >> x;
    cout << my << x << endl;
    return 0;
}
