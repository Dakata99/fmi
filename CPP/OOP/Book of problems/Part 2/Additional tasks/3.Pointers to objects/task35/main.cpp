#include <iostream>
#include "Polynom.cpp"

int main()
{
    Polynom p(3, 5), p2(4, -1);
    p.init();
    p2.init();
    std::cout << sum(p, p2) << std::endl;

    return 0;
}