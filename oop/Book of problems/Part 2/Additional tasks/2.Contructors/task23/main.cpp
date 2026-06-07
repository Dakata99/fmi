#include <iostream>
#include "Bag.cpp"

int main()
{
    Bag b(3);
    b.add(1);
    b.add(2);
    b.add(3);
    b.add(1);
    //b.print();
    b.remove(2);
    //b.print();
    b.remove(2);

    Bag b2(2);
    b2.add(1);
    b2.add(5);
    b2.add(9);
    b2.add(8);
    b2.add(1);
    b2.add(5);
    b2.add(6);
    b2.add(3);
    b2.add(1);
    //b2.print();

    Bag b3(1);
    b3.add(1);
    b3.add(6);
    b3.add(3);
    b3.add(18);
    b3.add(9);
    //b3.print();

    Bag b4 = b2.cut(b3);
    // std::cout << "Cut of b2 and b3 is: ";b4.print();
    // std::cout << "Cut of b3 and b2 is: ";b4 = b3.cut(b2);b4.print();
    // std::cout << std::endl;

    // b4 = b3.merge(b2);
    // b2.print();
    // b3.print();
    // std::cout << "Merge of b3 and b2 is: ";b4.print();
    // std::cout << "Merge of b2 and b3 is: ";b4 = b2.merge(b3);b4.print();
    // std::cout << std::endl;

    b2.print();
    b3.print();
    std::cout << "Diff of b2 and b3 is: "; Bag b5 = b2.diff(b3); b5.print();
    std::cout << "Diff of b3 and b2 is: "; b5 = b3.diff(b2); b5.print();
    std::cout << std::endl;
    
    b2.print();
    b3.print();
    std::cout << "Symetric diff of b3 and b2 is: "; Bag b6 = b3.symDiff(b2);b6.print();
    //std::cout << "Symmetric diff of b2 and b3 is: ";b6 = b2.symDiff(b3);b6.print();

    return 0;
}