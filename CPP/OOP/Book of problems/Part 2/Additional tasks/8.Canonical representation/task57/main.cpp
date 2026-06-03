#include <iostream>
#include "Sort.cpp"

int main()
{
    Sort s;
    Sort* ptr = &s;
    ptr->bubbleSort();
    ptr->write();
    
    Sort s2;
    Sort* ptr2 = &s2;
    ptr2->selectionSort();
    ptr2->write();

    return 0;
}