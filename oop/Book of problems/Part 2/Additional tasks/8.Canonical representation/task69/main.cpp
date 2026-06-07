#include <iostream>
#include "Vector.cpp"

int main()
{
    Vector v1(3), v2(1);
    v1.add(1);
    v1.add(2);
    v1.add(3);
    v1.print();

    v2.add(5);
    v2.add(6);
    v2.add(7);
    v2.add(8);
    v2.print();

    std::cout << "Sum...\n";
    Vector v3 = v1 + v2;v3.print();

    std::cout << "Substract...\n";
    v3 = v1 - v2;v3.print();

    std::cout << "Multiply with a number...\n";
    v3 = v1*3;v3.print();

    double res = v1 * v2;
    std::cout << "Scalar product: " << res << std::endl;

    std::cout << "Quotient of a vector...\n";
    v3 = v1 / 2;v3.print();

    v3++;
    v3.print();

    v3--;
    v3.print();

    bool flag = v3 == v2;
    std::cout << std::boolalpha << flag << std::endl;

    std::cout << v3[3] << std::endl;

    //TODO operator>>, operator<<, ||

    std::cout << v3() << std::endl;

    return 0;
}