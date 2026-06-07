#include <iostream>

#include "../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../Iterators/Trees iterators/Position.h"
#include "BST.h"

void run(void) {
    BST<int> t1;

    t1.insert_rec(20);
    t1.insert_rec(30);
    t1.insert_rec(15);
    t1.insert_rec(10);
    t1.insert_rec(5);
    t1.insert_rec(25);
    t1.insert_rec(42);
    t1.insert_iter(55);
    t1.insert_iter(33);
    t1.insert_iter(28);

    t1.print2D();
    t1.remove(28);
    t1.print2D();
    t1.remove(30);
    t1.print2D();
    t1.remove(20);
    t1.print2D();

#if 1
    std::vector<int> vec = {36, 52, 7, 4, 3, 59, 0, 1, 8, 45, -1, 124, -1};
    BST<int> t2;
    t2.create(vec);
    t2.print2D();
#endif

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

    BTree<int> t(t1);
    
    std::cout << *t.root_position() << std::endl;
    t.root_position().set(10);
    t.root_position().left().set(20);
    t.root_position().right().set(30);
    t.root_position().left().left().set(-1000);

    t.print2D();
    t1.print2D_v2();
#endif
}

int main(void) {
    // run();

    return 0;
}
