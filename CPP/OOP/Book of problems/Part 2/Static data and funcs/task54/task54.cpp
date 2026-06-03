#include <iostream>
#include <iomanip>

class Budget
{
private:
    static double uniBudget;
    double facultyBudget;
public:
    Budget():facultyBudget(0){}

    double getUniBudget()const
    {
        return uniBudget;
    }
    double getFacultyBudget()const
    {
        return facultyBudget;
    }
    void addBudget(const double amount)
    {
        facultyBudget = amount;
        uniBudget += facultyBudget;
    }
    static void addAdminBuget(const double amount)
    {
        uniBudget += amount;
    }
};
double Budget::uniBudget = 0;

void func()
{
    std::cout << "Enter adminstration budget: ";
    double admins;
    std::cin >> admins;
    Budget::addAdminBuget(admins);
    
    const int numFaculty = 5;
    double budgetAmount;
    Budget fac[numFaculty];

    for (size_t i = 0; i < numFaculty; i++)
    {
        std::cin >> budgetAmount;
        fac[i].addBudget(budgetAmount);
    }
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    for (size_t i = 0; i < numFaculty; i++)
    {
        std::cout << fac[i].getFacultyBudget() << std::endl;
    }

    std::cout << fac[0].getUniBudget() << std::endl;
    
}

int main()
{
    func();

    return 0;
}