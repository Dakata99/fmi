#include <iostream>
#include "Matrix.cpp"

int main()
{
    Matrix mat(3, 1, 3);
    mat.init();
    mat.print();
    mat.change(222, 2, 2);
    mat.print();

    return 0;
}