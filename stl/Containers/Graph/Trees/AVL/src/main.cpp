#include <iostream>

#include "../../../../../Iterators/Trees iterators/Iterator.h"
#include "../../../../../Iterators/Trees iterators/Position.h"
#include "AVL.h"

void run(void) {
    AVL<int> t1;

    t1.insert_rec(50);
    t1.insert_rec(10);
    t1.insert_rec(20);
    t1.print2D();

    for (int i = 0; i < 20; i++) {
        t1.insert_rec(std::rand() % 50 + -50);
    }
    t1.print2D();

#if 0
    t1.insert_rec(20);
    t1.insert_rec(30);
    t1.insert_rec(15);
    t1.insert_rec(10);
    t1.insert_rec(5);
    t1.insert_rec(25);
    t1.insert_rec(42);
    t1.insert_rec(55);
    t1.insert_rec(33);
    t1.insert_rec(28);

    t1.print2D();   
    t1.remove(28);
    t1.print2D();
    t1.remove(30);
    t1.print2D();
    t1.remove(20);
    t1.print2D();
#endif
}

int main(void) {
    // run();

    return 0;
}
