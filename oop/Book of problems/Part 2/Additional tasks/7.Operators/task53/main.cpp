#include <iostream>
#include "Dictionary.cpp"

int main()
{
    Dictionary d(3);
    d.add("plane", "flying machine");
    d.add("cat", "animal");
    d.add("whale", "sea monster");
    d.add("car", "vehicle");
    d.print();

    d["cat"];

    return 0;
}