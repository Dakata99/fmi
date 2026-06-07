#include <cstring>
#include "Car.h"

char* Car::copy(const char* str)
{
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);

    return temp;
}

//des/constructors
Car::Car(const char* _mark, const char* _model, const char* _regNum)
{
    mark = copy(_mark);
    model = copy(_model);
    regNum = copy(_regNum);
}
Car::Car(const Car& other)
{
    mark = copy(other.mark);
    model = copy(other.model);
    regNum = copy(other.regNum);
}
Car::~Car()
{
    delete[]mark;
    delete[]model;
    delete[]regNum;
}
//operators
Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        delete[]mark;
        mark = copy(other.mark);
        
        delete[]model;
        model = copy(other.model);
        
        delete[]regNum;
        regNum = copy(other.regNum);
    }
    return *this;
}
//getters
char* Car::getMark()const
{
    return mark;
}
char* Car::getModel()const
{
    return model;
}
char* Car::getRegNum()const
{
    return regNum;
}
//setters
void Car::setMark(const char* _mark)
{
    mark = copy(_mark);
}
void Car::setModel(const char* _model)
{
    model = copy(_model);
}
void Car::setRegNum(const char* _regNum)
{
    regNum = copy(_regNum);
}
//funcs
void Car::printCar()const
{
    std::cout << "Mark: " << mark << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Registration number: " << regNum << std::endl;
}