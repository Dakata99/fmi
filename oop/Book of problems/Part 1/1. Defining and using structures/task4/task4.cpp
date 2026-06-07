#include <iostream>
#include <cmath>

struct Polar
{
    double radius, alpha;
};

struct Rect
{
    double x,y;
};

void printRect(const Rect& r)
{
    std::cout<<"("<<r.x<<", "<<r.y<<")"<<std::endl;
}
void printPolar(const Polar& p)
{
    std::cout<<"Radius = "<<p.radius<<std::endl;
    std::cout<<"Angle = "<<p.alpha<<std::endl;
}
Rect polarToRect(const Polar& p)
{
    Rect r;
    r.x = cos(p.alpha)*p.radius;
    r.y = sin(p.alpha)*p.radius;
    return r;
}
Polar rectToPolar(const Rect& r)
{
    Polar p;
    p.radius = sqrt(r.x*r.x + r.y*r.y);
    p.alpha = asin(r.y/p.radius);
    return p;
}


int main()
{
    char operation;
    std::cout<<"Enter operation for input(r - rect, p - polar): ";std::cin>>operation;
    switch (operation)
    {
    case 'r':
    case 'R':
        std::cout<<"Enter rectangle coordinates: ";
        Rect r1;
        Polar p1;
        while (std::cin>>r1.x>>r1.y)
        {
            p1 = rectToPolar(r1);
            printPolar(p1);
            std::cout<<"Type end to stop!"<<std::endl;
        }        
        break;
    case 'p':
    case 'P':
        std::cout<<"Enter polar coordinates: ";
        Rect r2;
        Polar p2;
        while (std::cin>>p2.radius>>p2.alpha)
        {
            r2 = polarToRect(p2);
            printRect(r2);
        }
            std::cout<<"Type end to stop!"<<std::endl;
        break;
    
    default:std::cout<<"Invalid operation!"<<std::endl;break;
    }
    return 0;
}