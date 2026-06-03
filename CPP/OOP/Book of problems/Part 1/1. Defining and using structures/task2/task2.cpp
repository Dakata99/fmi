#include <iostream>

struct Rectangle
{
    int length, width;
};
//a
void printRectangle(Rectangle& r)
{
    std::cout<<"Length = "<<r.length<<std::endl;
    std::cout<<"Width = "<<r.width<<std::endl;
}
//b
void initRectangle(Rectangle& r)
{
    int length,width;
    do
    {
        std::cout<<"Enter length = ";std::cin>>length;
        r.length = length;
        std::cout<<"Enter  width = ";std::cin>>width;
        r.width = width;
    } while (length <= 0 || width <= 0);
}
Rectangle initRectangle()
{
    Rectangle r;
    int length, width;
    do
    {
        std::cout<<"Enter length = ";std::cin>>length;
        r.length = length;
        std::cout<<"Enter  width = ";std::cin>>width;
        r.width = width;
    } while (length <= 0 || width <= 0);
    return r;
}
int main()
{
    Rectangle r;
    initRectangle(r);
    printRectangle(r);
    Rectangle r2 = initRectangle();
    printRectangle(r2);
    return 0;
}