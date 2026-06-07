#include <iostream>
#include <cmath>

struct Triangle
{
    double a,b,c;
};
void printTriangle(const Triangle& t)
{
    std::cout<<t.a<<", "<<t.b<<", "<<t.c<<std::endl;
}
void initTriangle(Triangle& t)
{
    double a, b, c;
    do
    {
        std::cin>>a;
        t.a = a;
        std::cin>>b;
        t.b = b;
        std::cin>>c;
        t.c = c;
    } while (a <= 0 || b<=0 || c<=0 && a<b+c && c<a+b && b<a+c);
}
Triangle initTriangle()
{
    Triangle t;
    double a, b, c;
    do
    {
        std::cin>>a;
        t.a = a;
        std::cin>>b;
        t.b = b;
        std::cin>>c;
        t.c = c;
    } while (a <= 0 || b<=0 || c<=0 && a<b+c && c<a+b && b<a+c);
    return t;
}
double perimeter(const Triangle& t)
{
    return t.a+t.b+t.c;
}
double area(const Triangle& t)
{
    double pHalf = perimeter(t)/2;
    return sqrt(pHalf*(pHalf-t.a)*(pHalf-t.b)*(pHalf-t.c));
}

int main()
{
    Triangle t;
    initTriangle(t);
    printTriangle(t);
    std::cout<<"Perimeter is: "<<perimeter(t)<<std::endl;
    std::cout<<"Area is: "<<area(t)<<std::endl;
    return 0;
}