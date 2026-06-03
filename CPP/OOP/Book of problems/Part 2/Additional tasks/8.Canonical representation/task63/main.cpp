#include <iostream>
#include "String.cpp"

void myFunc()
{
    String s1("abracadabra"), s2("Aladin");
    s1.print();
    s2.print();

    //operator=
    String s3 = s1, s4 = s2;
    s3.print();
    s4.print();

    String s5 = "Daniel";
    s5.print();

    //operator !=
    bool flag = s1 != s3;
    std::cout << std::boolalpha << flag << std::endl;

    //operator ==
    flag = s1 == s4; //compare 2 strings
    std::cout << std::boolalpha << flag << std::endl;
    flag = s1 == "Daniel"; //compare string and const char*
    std::cout << std::boolalpha << flag << std::endl;
    flag = "Daniel" == s5; //compare const char* and string
    std::cout << std::boolalpha << flag << std::endl;

    //operator >=

    //operator <=

    //operator >
    String s6 = "Geeks", s7 = "forGeeks";
    if(s6 > s7)
        std::cout << "s6 is greater than s7" << std::endl;
    //operator <
    if(s6 < s7)
        std::cout << "s6 is smaller than s7" << std::endl;
    
}

void func()
{
    String a("Hello "), b;
    b = a;
    b.print();
    b = "Ivan and ";
    char str1[] = "Georgi!\n";
    b = str1;
    b.print();

    String c("Aneta"), d("Aneta");
    if(c == d) std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    if(c == "Aneta") std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    if("Aneta" == d) std::cout << "Names match" << std::endl;
    else std::cout << "Names do not match" << std::endl;

    String e("Aneta"), f("Anet");
    if(e > f)
        std::cout << "Aneta is longer than Anet\n";
    else
        std::cout << "Aneta is not longer than Aner\n";

    if(e > "Anet")
        std::cout << "Aneta is longer than Anet\n";
    else
        std::cout << "Aneta is not longer than Anet\n";

    if("Aneta" > f)
        std::cout << "Aneta is longer than Anet\n";
    else 
        std::cout << "Aneta is not longer than Anet\n";
}

int main()
{
    //myFunc();
    //func();
    String s1("Daniel"), s2(" Lyubenov");
    s1 += s2;
    s1.print();

    s2.print();
    s2 += " The best";
    s2.print();

    char str[] = " player";
    s2 += str;
    s2.print();
    
    return 0;
}