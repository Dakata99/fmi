#include <iostream>

#include "../../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../../Iterators/Trees iterators/Position.h"
#include "BTree.h"

void run(void) {
    BTree<int> t1;
    t1.create();
    t1.print2D();

#if 0
    std::cout << std::endl;

    BTree<int> t2 = t1;
    t2.print2D();

    BTree<int> t3(t2);
    t3.print2D();

    t1.pre_order();
    t2.in_order();
    t3.post_order();

    std::cout << std::boolalpha << t1.search(6) << std::endl;
    std::cout << t2.height() << std::endl;
#endif

    // BTree<int> t(t1);

    // std::cout << *t.root_position() << std::endl;
    // t.root_position().set(10);
    // t.root_position().left().set(20);
    // t.root_position().right().set(30);
    // t.root_position().left().left().set(-1000);

    // t.print2D();
    t1.print2D_v2();
}

int main(void) {
    // run();

    return 0;
}
