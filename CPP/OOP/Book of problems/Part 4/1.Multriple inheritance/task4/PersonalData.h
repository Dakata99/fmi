#pragma once

class PersonalData
{
private:
    char* name;
    size_t birthYear;
    char* copy(const char*);
public:
//des/constructors
    PersonalData(const char* = "", const size_t = 1999);
    PersonalData(const PersonalData&);
    ~PersonalData();

//operators
    PersonalData& operator=(const PersonalData&);

//getters
    char* getName()const;
    size_t getYear()const;

//setters
    void setName(const char*);
    void setYear(const size_t);

//funcs
    void printPD()const;
};