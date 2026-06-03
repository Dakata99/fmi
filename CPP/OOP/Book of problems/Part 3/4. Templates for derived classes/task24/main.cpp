#include <iostream>
#include "Point3.cpp"
#include "ColPoint3.cpp"
#include "WeightColPoint3.cpp"

void func()
{
//a
    WeightColPoint3<double, double, double>* points = new WeightColPoint3<double, double, double>[5];
    for (size_t i = 0; i < 5; i++)
    {
        points[i].setX(i);
        points[i].setY(i + 1);
        points[i].setZ(i + 2);
        points[i].setColor(i);
        points[i].setWeight(i*10 + i);
    }
    for (size_t i = 0; i < 5; i++)
    {
        points[i].printWeightColPoint3();
    }
    WeightColPoint3<double, double, double> heaviest;
    size_t index = 0;
    double max = 0; double a = 1, b = 2, c = 3, d = 4;
    for (size_t i = 0; i < 5; i++)
    {
        if (points[i].getColor() >= 1 && points[i].getColor() <= 5 
            && a*points[i].getX() + b* points[i].getY() + c*points[i].getZ() == d 
            && points[i].getWeight() > max)
        {
            max = points[i].getWeight();
            heaviest = points[i];
        }
    }
    heaviest.printWeightColPoint3();

    delete[]points;
//b
    
}

int main()
{
    func();

    return 0;
}