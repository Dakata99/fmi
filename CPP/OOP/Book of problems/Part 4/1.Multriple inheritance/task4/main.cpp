#include <iostream>
#include "PersonalData.cpp"
#include "Car.cpp"
#include "CarOwner.cpp"
#include "Class.cpp"
#include "Teacher.cpp"

int main()
{
    PersonalData p1("Daniel", 1999), p2("Plamen", 1971);
    //p1.printPD();
    //p2.printPD();

    Car c1("Toyota", "Rav4", "A1AS5DF43"), c2("BMW", "X5", "AK53KLK23");
    //c1.printCar();
    //c2.printCar();

    CarOwner co1(p1, c1), co2(p2, c2);
    //co1.printCarOwner();
    //co2.printCarOwner();

    Class cl1(2019, 20, 2);
    //cl1.printClass();

    Teacher t(PersonalData("Ribarska", 1977), cl1);
    t.printTeacher();

    return 0;
}