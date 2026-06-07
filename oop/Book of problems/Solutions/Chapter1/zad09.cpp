#include <iostream.h>
#include <iomanip.h>

struct Rectangle
{ 
    int length;            // дължина
    int width;             // широчина
};

int main()
{
    //а)
    Rectangle r = {15, 20};
    Rectangle *p = &r;

    //б)
    cout << setw(10) << p->length
         << setw(10) << p->width << endl;

    return 0;
}
