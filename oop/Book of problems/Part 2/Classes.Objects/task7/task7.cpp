#include <iostream>
#include <cstring>

struct Name
{
    char* first, *last;
};

struct Work
{
    int hours;
    double salaryPerHour;
};

class Employee
{
private:
    Name name;
    Work work;
public:

    void print(Name& name)const
    {
        std::cout << name.first << " " << name.last << std::endl;
    }
    double salary(Work& work)const
    {
        return work.hours * work.salaryPerHour;
    }
};

int main()
{
    Name name;
    name.first = new char[7];
    strcpy(name.first, "Daniel");
    name.last = new char[9];
    strcpy(name.last, "Lyubenov");

    Work work;
    work.hours = 8;
    work.salaryPerHour = 1.5;

    Employee em;
    em.print(name);
    std::cout << em.salary(work) << std::endl;

    delete[]name.first;
    delete[]name.last;

    return 0;
}