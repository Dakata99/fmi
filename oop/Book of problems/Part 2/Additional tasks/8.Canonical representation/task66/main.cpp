#include <iostream>
#include "Set.cpp"

void func1()
{
    Set s(3);
    s.add(1);
    //s.print();

    s.add(2);
    //s.print();

    s.add(3);
    //s.print();

    s.add(5);
    //s.print();

    s.add(4);
    //s.print();
    
    s.add(5);
    s.print();

    std::cout << "Size: " << s.size() << std::endl;

    s.print();
    s.remove(3);
    s.print();

    Set s2(5);
    s2.add(6);
    s2.add(2);
    s2.add(1);
    s2.add(4);
    s2.add(9);
    s2.print();

    std::cout << "Cut set of s and s2 is: "; Set ss = s.cut(s2); ss.print();
    std::cout << "Cut set of s2 and s is: "; Set ss2 = s2.cut(s);  ss2.print();

    std::cout << "Merge set of s and s2 is: "; Set s4 = s.merge(s2); s4.print();

    std::cout << "Symmetric difference of s and s2 is: "; Set s5 = s.symetricDiff(s2);s5.print();
    std::cout << "Symmetric difference of s2 and s is: "; Set s6 = s2.symetricDiff(s);s6.print();

    std::cout << "Difference of s and s2 is: "; Set s7 = s.difference(s2);s7.print();
    std::cout << "Differemce of s2 and s is: "; Set s8 = s2.difference(s);s8.print();
}

void func2()
{
    Set s(3);
    s+1;
    //s.print();

    s+2;
    //s.print();

    s+3;
    //s.print();

    s+5;
    //s.print();

    s+4;
    //s.print();
    
    s+5;
    s.print();

    std::cout << "Size: " << s.size() << std::endl;

    s.print();
    s-3;
    s.print();

    Set s2(5);
    s2+6;
    s2+2;
    s2+1;
    s2+4;
    s2+9;
    s2.print();

    std::cout << "Cut set of s and s2 is: "; Set ss = s * s2; ss.print();
    std::cout << "Cut set of s2 and s is: "; Set ss2 = s2 * s;  ss2.print();

    std::cout << "Merge set of s and s2 is: "; Set s4 = s + s2; s4.print();

    std::cout << "Symmetric difference of s and s2 is: "; Set s5 = s ^ s2;s5.print();
    std::cout << "Symmetric difference of s2 and s is: "; Set s6 = s2 ^ s;s6.print();

    std::cout << "Difference of s and s2 is: "; Set s7 = s - s2;s7.print();
    std::cout << "Differemce of s2 and s is: "; Set s8 = s2 - s;s8.print();

    bool flag = s != s2;
    std::cout << std::boolalpha << flag << std::endl;

    Set a, b;
    for (size_t i = 0; i < 10; i++)
    {
        a+i;
    }
    for (size_t i = 2; i < 5; i++)
    {
        b+i;
    }
    
    a.print();
    b.print();
    flag = a > b;
    std::cout << flag << std::endl;

    std::cout << a(55) << std::endl;

    Set c;
    for (size_t i = 1; i < 8; i++)
    {
        c+i;
    }
    Set c2;
    c2+1;
    c2+2;
    c2+3;
    
}

int main()
{
    func1();
    std::cout << "--------------------------------------------\n";
    func2();

    return 0;
}
