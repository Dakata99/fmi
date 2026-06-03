#include <iostream>
#include "String.cpp"

int main()
{
    String s1("Daniel"), s2(" Lyubenov");

//at
    // std::cout << s1.at(0) << std::endl;
    // std::cout << s1.at(1) << std::endl;
    // std::cout << s1.at(2) << std::endl;
    // std::cout << s1.at(3) << std::endl;
    // std::cout << s1.at(4) << std::endl;
    // std::cout << s1.at(5) << std::endl;
    // std::cout << s1.at(6) << std::endl;
    // std::cout << s1.at(7) << std::endl;

//length
    // std::cout << s1.length() << std::endl;

//compareTo

//replaceFirst

//insert

//deletee
    String s3 = s1.deletee(2, 4);
    s3.print();
//cstring

//copy

//trim

//tokenize

//substring
    // String s3 = s1.substring(2, 4);
    // s3.print();

    return 0;
}