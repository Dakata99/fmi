#include <iostream.h>
#include <iomanip.h>

// дефиниране на манупулатора outp
ostream& outp(ostream& ostr)
{
    ostr << "Ќеотрицателното ц€ло число принадлежи "
         << "на интервала [1, 100]!\n";
    return ostr;
}

int main()
{
    cout << outp << endl;
    return 0;
}
