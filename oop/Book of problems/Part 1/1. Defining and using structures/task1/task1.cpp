#include <iostream>
#include <cstring>

struct Product
{
    char description[32];
    int partNum;
    double cost;
};


int main()
{
 //a
    Product p1 = {"screw-driver", 456, 5.50};
    Product p2 = {"hammer", 324, 8.20};
//b
    std::cout<<p1.description << " - "<<p1.partNum << " - "<<p1.cost<<std::endl;
    std::cout<<p2.description <<" - "<<p2.partNum <<" - "<<p2.cost <<std::endl;
//c    
    Product prods[10];
//d
    for (size_t i = 0; i < 10; i++)
    {
        strcpy(prods[i].description, "");
        prods[i].partNum = 0;
        prods[i].cost = 0.00;
    }
//e
    Product prod[5] = {p1, p2, {"socket", 458, 5.75}, {"plier", 929, 10.50}, {"hand-saw", 536, 7.45}};
//f
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<prod[i].description<<" - "<<prod[i].partNum<<" - "<<prod[i].cost<<std::endl;
    }
    
    
    return 0;
}