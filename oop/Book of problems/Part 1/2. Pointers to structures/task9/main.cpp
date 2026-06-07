#include <iostream>

struct Rectangle
{
    int length, width;
};

int main()
{
//a
    Rectangle r = {15, 20};
    Rectangle* ptr = &r;

//b
    std::cout << "[" << ptr->length << ", " << ptr->width << "]\n";

//c
    std::cout << (*ptr).width << std::endl; //(*ptr).width == ptr->width is the valid 
}
