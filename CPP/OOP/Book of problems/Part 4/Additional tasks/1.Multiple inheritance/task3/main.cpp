#include <iostream>
#include "Criminal.cpp"
#include "Animation.cpp"
#include "CriminalAnimation.cpp"

int main()
{
    Criminal c1("Murders", 1977, 5);
    c1.print();
    
    Animation a1("Micky Maus", 1988, "Disney");
    a1.print();

    CriminalAnimation ca1(c1, a1);
    ca1.print();

    return 0;
}