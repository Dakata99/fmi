#include "Student.h"
#include <cstring>

Student::Student()
{
    facNumber = 0;
    firstName = nullptr;
    lastName = nullptr;
    term = 0;
    credits = gpa = 0.0;
}
Student::Student(const int facNum, const char* fiName, const char* laName, const int _term, const double creds, const double _gpa)
{
    facNumber =facNum;
    firstName = new char[strlen(fiName) + 1];
    strcpy(firstName, fiName);
    lastName = new char[strlen(laName) + 1];
    strcpy(lastName, laName);
    term = _term;
    credits = creds;
    gpa = _gpa;
}
Student::Student(const Student& other)
{
    facNumber = other.facNumber;
    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);
    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);
    term = other.term;
    credits = other.credits;
    gpa = other.gpa;
}
Student::~Student()
{
    delete[]firstName;
    delete[]lastName;
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        facNumber = other.facNumber;
        firstName = new char[strlen(other.firstName) + 1];
        strcpy(firstName, other.firstName);
        lastName = new char[strlen(other.lastName) + 1];
        strcpy(lastName, other.lastName);
        term = other.term;
        credits = other.credits;
        gpa = other.gpa;
    }
    return *this;
}

int Student::getFacNumber()const
{
    return facNumber;
}
const char* Student::getFirstName()const
{
    return firstName;
}
const char* Student::getLastName()const
{
    return lastName;
}
int Student::getTerm()const
{
    return term;
}
double Student::getCredits()const
{
    return credits;
}
double Student::getGPA()const
{
    return gpa;
}

bool Student::operator==(const Student& other)const
{
    return facNumber == other.facNumber;
}
bool Student::operator!=(const Student& other)const
{
    return facNumber != other.facNumber;
}
bool Student::operator<(const Student& other)const
{
    return facNumber < other.facNumber;
}
bool Student::operator<=(const Student& other)const
{
    return facNumber <= other.facNumber;
}
bool Student::operator>(const Student& other)const
{
    return facNumber > other.facNumber;
}
bool Student::operator>=(const Student& other)const
{
    return facNumber >= other.facNumber;
}

void Student::print()const
{
    std::cout << "Faculty number: " << facNumber << std::endl;
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Term: " << term << std::endl;
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}