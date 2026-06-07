#pragma once

class Car
{
private:
    char* mark, *model, *regNum;
    char* copy(const char*);
public:
//des/constructors
    Car(const char* = "", const char* = "", const char* = "");
    Car(const Car&);
    ~Car();
//operators
    Car& operator=(const Car&);
//getters
    char* getMark()const;
    char* getModel()const;
    char* getRegNum()const;
//setters
    void setMark(const char*);
    void setModel(const char*);
    void setRegNum(const char*);
//funcs
    void printCar()const;
};
