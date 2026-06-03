#include <iostream.h>
#include <iomanip.h>

struct Rectangle
{
    int length;			// дължина
    int width;			// широчина
};

////а)
void print_rectangle(Rectangle r)
{
    cout << setw(10) << r.length
         << setw(10) << r.width << endl;
}

////б)
void init_rectangle(Rectangle& r)
{
    do
    {
        cout << "length: "; 
        cin >> r.length;
        cout << "width: ";
        cin >> r.width;
    } while(r.length <= 0 || r.width <= 0);
}

////в)
Rectangle init_rectangle()
{
    Rectangle r;
    do
    {
        cout << "length: ";
        cin >> r.length;
        cout << "width: "; 
        cin >> r.width;
    } while(r.length <= 0 || r.width <= 0);
    return r;
}


int main()
{
    Rectangle r;
    r = init_rectangle();
    print_rectangle(r);
    init_rectangle(r);
    print_rectangle(r);
    return 0;
}
