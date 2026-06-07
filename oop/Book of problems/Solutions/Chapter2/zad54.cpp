#include <iostream.h>
#include <iomanip.h>

const int MAXSIZE = 5;  // брой на факултетите на университет

class Budget
{ public:
Budget();
double getFacultyBudget() const;
double getUniversityBudget() const;
void addBudget(double);
static void administration(double);

private:
    static double universityBudget;      // бюджет на университет
    double facultyBudget;                // бюджет на факултет
};

// инициализиране на статичната член-данна на класа
double Budget::universityBudget = 0;

// конструктор
Budget::Budget()
{
    facultyBudget= 0;
}

// функция за достъп, връщаща бюджета на факултет
double Budget::getFacultyBudget() const
{ 
    return facultyBudget;
}

// функция за достъп, връщаща бюджета на университет
double Budget::getUniversityBudget() const
{ 
    return universityBudget;
}

// добавяне на бюджета на факултет
// към бюджета на университет
void Budget::addBudget(double bud)
{ 
    facultyBudget = bud;
    universityBudget += facultyBudget;
}

// добавяне на бюджета на администрацията към
// бюджета на университета
void Budget::administration(double bud)
{ 
    universityBudget += bud;
}

int main()
{
    const int numFaculty = MAXSIZE;
    cout << "Въведете бюджета на администрацията: ";
    double adminBudget;
    cin >> adminBudget;
    // добавяне на бюджета на администрацията към
    // бюджета на университета
    Budget::administration(adminBudget);
    int i;
    // въвеждане на бюджетите на факултетите и
    // добавяне към бюджета на университета
    double budgetAmount;
    Budget fac[numFaculty];
    for(i = 0; i < numFaculty; i++)
    {
        cout << "Въведете бюджета на " << i+1
            << "- я факултет: ";
        cin >> budgetAmount;
        fac[i].addBudget(budgetAmount);
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    // извеждане на бюджета на администрацията
    cout << "\t Бюджет на администрацията:\t ";
    cout << adminBudget << endl;
    // извеждане на бюджета на всеки факултет и
    // на университета
    for(i = 0; i < numFaculty; i++)
    { 
        cout << "\t Факултет " << (i+1) << ":\t ";
        cout << fac[i].getFacultyBudget() << endl;
    }
    cout << "\t Бюджет на университета:\t ";
    cout << fac[0].getUniversityBudget() << endl;
    return 0;
}
