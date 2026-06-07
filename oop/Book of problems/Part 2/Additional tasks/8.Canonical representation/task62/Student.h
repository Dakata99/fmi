#pragma once

class Student
{
private:
    int facNumber;
    char* firstName, *lastName;
    int term;
    double credits, gpa;
public:
    Student();
    Student(const int, const char*, const char*, const int, const double, const double);
    Student(const Student&);
    ~Student();

    Student& operator=(const Student&);

    int getFacNumber()const;
    const char* getFirstName()const;
    const char* getLastName()const;
    int getTerm()const;
    double getCredits()const;
    double getGPA()const;

    bool operator==(const Student&)const;
    bool operator!=(const Student&)const;
    bool operator<(const Student&)const;
    bool operator<=(const Student&)const;
    bool operator>(const Student&)const;
    bool operator>=(const Student&)const;

    void print()const;
};
