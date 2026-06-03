#include <iostream>
#include <algorithm>
#include "Worker.cpp"
#include "HourlyWorker.cpp"
#include "SalariedWorker.cpp"

HourlyWorker* makeHourlyWorkers(const size_t num)
{
    HourlyWorker* hws = new HourlyWorker[num];
    
    for (size_t i = 0; i < num; i++)
    {
        char name[20];
        std::cout << "Enter name of worker: "; std::cin >> name;

        double salaryPerHour;
        std::cout << "Enter salary per hour: "; std::cin >> salaryPerHour; 

        char duty[10];
        std::cout << "Enter duty: "; std::cin >> duty;

        size_t hours;
        std::cout << "Enter hours: "; std::cin >> hours;
        hws[i] = HourlyWorker(name, salaryPerHour, duty, hours);
    }
    return hws;
}

SalariedWorker* makeSalariedWorkers(const size_t num)
{
    SalariedWorker* sws = new SalariedWorker[num];
    
    for (size_t i = 0; i < num; i++)
    {
        char name[20];
        std::cout << "Enter name of worker: "; std::cin >> name;

        double salaryPerHour;
        std::cout << "Enter salary per hour: "; std::cin >> salaryPerHour; 

        char duty[10];
        std::cout << "Enter duty: "; std::cin >> duty;

        size_t hours;
        std::cout << "Enter hours: "; std::cin >> hours;
        sws[i] = SalariedWorker(name, salaryPerHour, duty, hours);
    }

    return sws;
}

void printInfoHourlyWorkers(const size_t num, HourlyWorker*& hws)
{
    std::cout << "---------Info for hourly workers------------" << std::endl;
    for (size_t i = 0; i < num; i++)
    {
        hws[i].print();
    }
    std::cout << "--------------------------------------------" << std::endl;
}

void printInfoSalariedWorkers(const size_t num, SalariedWorker*& sws)
{
    std::cout << "---------Info for salaried workers------------" << std::endl;
    for (size_t i = 0; i < num; i++)
    {
        sws[i].print();
    }
    std::cout << "----------------------------------------------" << std::endl;
}

void sortHourlyWorkers(const size_t num, HourlyWorker*& hws)
{
    for (size_t i = 0; i < num; i++)
    {
        double max = hws[i].getSalary();
        for (size_t j = i + 1; j< num; j++)
        {
            if (hws[i].getSalary() < hws[j].getSalary())
            {
                swap(hws[i], hws[j]);
            }
        }
    }
}

void sortSalariedWorkers(const size_t num, SalariedWorker*& sws)
{

}

void func()
{
    std::cout << "Enter a number for hourly workers: "; size_t n; std::cin >> n;
    HourlyWorker* hws = makeHourlyWorkers(n);

    std::cout << "Enter a number for salaried workers: "; size_t n2; std::cin >> n2;
    SalariedWorker* sws = makeSalariedWorkers(n2);

    printInfoHourlyWorkers(n, hws);
    printInfoSalariedWorkers(n2, sws);

    delete[]hws;
    delete[]sws;
}

int main()
{
    func();

    return 0;
}