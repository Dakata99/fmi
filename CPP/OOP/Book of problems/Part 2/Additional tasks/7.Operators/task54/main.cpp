#include <iostream>
#include "Boolean.cpp"

int main()
{
    Bool b1 = TRUE, b2 = TRUE;
    Boolean bb1(b1), bb2(b2);
    Boolean res1 = bb1 && bb2;
    res1.print();

    Bool b3 = FALSE, b4 = TRUE;
    Boolean bb3(b3), bb4(b4), res2 = bb3 || bb4;
    res2.print();

    Boolean b5(b4);
    Boolean b6 = !b5;
    b6.print();

    return 0;
}