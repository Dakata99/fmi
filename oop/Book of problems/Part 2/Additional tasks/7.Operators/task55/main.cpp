#include <iostream>
#include "Color.cpp"

int main()
{
    Color c(ORANGE), c2(BLUE), c4(RED), c5(ORANGE);
    c.print();
    c2.print();


    bool flag = c >= c2;
    std::cout << std::boolalpha << flag << std::endl;
    
    c5--;
    c5--;
    c5.print();
    c5--;
    c5--;
    c5.print();
    c5++;
    c5.print();
    
    c2++;
    c2++;
    c2++;
    c2++;
    c2.print();
    c2++;
    c2.print();
    c2--;
    c2.print();

    return 0;
}