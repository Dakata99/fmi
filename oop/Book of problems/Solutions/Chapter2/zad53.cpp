#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 5; // брой на факултетите на университета

class Budget
{
public:
    // конструктор
    Budget();
    // член-функции за достъп до компонентите на класа
    double getFacultyBudget() const;
    double getUniversityBudget() const;
    // член-функция, която добавя бюджета на
    // факултет към бюджета на университета
    void addBudget(double);

private:
    static double universityBudget;      // бюджет на университет
    double facultyBudget;                // бюджет на факултет
};

// инициализиране на статичната член-данна на класа
double Budget::universityBudget = 0;

Budget::Budget()
{
    facultyBudget= 0;
}

double Budget::getFacultyBudget() const
{
    return facultyBudget;
}

double Budget::getUniversityBudget() const
{
    return universityBudget;
}

void Budget::addBudget(double bud)
{
    facultyBudget = bud;
    universityBudget += facultyBudget;
}

int main()
{
    const int numFaculty = MAX_SIZE;
    int i;
    // въвеждане на бюджета на всеки факултет
    // и добавяне към бюджета на университета
    double budgetAmount;
    Budget fac[numFaculty];
    for(i = 0; i < numFaculty; i++)
    {
        cout << "Въведете бюджета на " << i+1 << "- я факултет: ";
        cin >> budgetAmount;
        fac[i].addBudget(budgetAmount);
    }

    // извеждане на бюджета на всеки факултет и  на университета
    cout << setiosflags(ios::fixed) << setprecision(2);
    for(i = 0; i < numFaculty; i++)
    { 
        cout << "\t Факултет " << (i+1) << ":\t ";
        cout << fac[i].getFacultyBudget() << endl;
    }
    cout << "\t Бюджет на университета:\t ";
    cout << fac[0].getUniversityBudget() << endl;
    return 0;
}
