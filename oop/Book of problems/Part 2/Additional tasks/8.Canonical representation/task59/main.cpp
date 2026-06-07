#include <iostream>
#include "PersonInfo.cpp"

int main()
{
    PersonInfo p1("Daniel", 20), p2("Plamen", 44), p3 = p1, p4 = p2;
    p1.print();
    p2.print();
    p3.print();
    p4.print();

    return 0;
}