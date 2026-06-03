#include <iostream>
#include "Sorted.cpp"

int main()
{
    Sorted i(1);
    i.add(1); //0
    i.add(2); //1
    i.add(3); //2
    i.add(4); //3
    i.addBefore(99, 0);
    i.addBefore(89, 1);
    i.addBefore(79, 2);
    i.addBefore(69, 3);
    i.addBefore(59, 4);
    i.addBefore(49, 5);
    i.addAfter(109, 3);
    i.remove(5);

    i.print();

    Sorted p(1);
    p.add(109);
    p.add(101);
    p.add(69);
    p.add(66);
    p.add(109);
    p.add(79);

    p.print();

//intersection
    std::cout << "Intersection*************\n";
    Sorted s = i.intersection(p);s.print();
    s = p.intersection(i);s.print();

//merge
    std::cout << "Merge******************\n";
    Sorted k = i.merge(p);k.print();
    k = p.merge(i);k.print();

//difference
    std::cout << "Difference**************\n";
    Sorted t = i.difference(p); t.print();
    Sorted l = p.difference(i);l.print();

    std::cout << l[2] << std::endl;

    return 0;
}