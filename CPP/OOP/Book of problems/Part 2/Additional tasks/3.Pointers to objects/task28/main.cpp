#include <iostream>

class Tank
{
private:
    int gallons;
public:
    Tank()
    {
        gallons = 35;
    }
    Tank(int gal)
    {
        gallons = gal;
    }
    int getGallons()const
    {
        return gallons;
    }
};

int main()
{
    Tank storage[5] = {5, 10, 15, 20};
    for (size_t i = 0; i < 5; i++)
        std::cout << storage[i].getGallons() << std::endl;

    return 0;    
}
