#include <iostream>
#include "Complex.cpp"
#include "CompNums.cpp"

int main()
{
    CompNums c(2);
    c.init();
    c.print();

    CompNums c2(3);
    c2.init();
    c2.print();
    
    CompNums c3 = merge(c, c2), c4 = merge(c2, c);
    c3.print();
    c4.print();

    std::cout << c[0].getReal() << std::endl;


    return 0;
}