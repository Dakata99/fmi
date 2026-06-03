#include <iostream>
#include "Student.cpp"

int main()
{
    Student s(81864, "Daniel", "Lyubenov", 2, 34, 99);
    s.print();

    Student s2(2123, "Ivan", "Spasimirov", 3, 31, 32);
    s2.print();

    bool flag = s < s2;
    std::cout << std::boolalpha << flag << std::endl;

    return 0;
}