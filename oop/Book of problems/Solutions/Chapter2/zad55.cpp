#include <iostream.h>
#include <string.h>
#include <stdlib.h>

const int MaxLengthName = 30;    // максимална дължина на име
const int PATIENTS = 100;        // максимален брой на пациентите

// дефиниция на клас Date
class Date
{ 
private:
    int theDay,                     // Ден
        theMonth,                   // Месец
        theYear;                    // Година

public:
    Date(int = 1, int = 1, int = 2000);    // конструктор
    int Day() const;                 // достъп до ден
    int Month() const;               // достъп до месец
    int Year() const;                // достъп до година
    void setDay(int);                // промяна на ден
    void setMonth(int);              // промяна на месец
    void setYear(int);               // промяна на година
    void print() const;              // извеждане на дата
};

Date::Date(int d, int m, int y)
{ 
    theDay = d;
    theMonth = m;
    theYear = y;
}

int Date::Day() const
{ 
    return theDay;
}

int Date::Month() const
{ 
    return theMonth;
}

int Date::Year() const
{ 
    return theYear;
}

void Date::setDay(int d)
{ 
    theDay = d;
} 

void Date::setMonth(int m)
{ 
    theMonth = m;
}

void Date::setYear(int y)
{ 
    theYear = y;
}

void Date::print() const
{ 
    cout << theDay << "." << theMonth
        << "." << theYear << endl;
}

Date date(1, 1, 2000);            // подразбираща се дата

// дефиниция на клас Patient
class Patient
{ 
public:
    // канонично представяне
    Patient(const char * = "", const Date& = date, int = 0);
    ~Patient();
    Patient(const Patient&);
    Patient& operator=(const Patient&);
    // функции за достъп
    const char* getName() const;        // достъп до име
    Date getDOB() const;                // достъп до дата на раждане
    int getVisits() const;              // достъп до брой визити
    void print() const;                 // извеждане на пациент

private:
    char* Name;                         // име на пациент
    Date DOB;                           // дата на раждане на пациент
    int Visits;                         // брой посещения на пациента
};

Patient::Patient(const char * n, const Date& d, int v)
{ 
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, n);
    DOB = d;
    Visits = v;
}

Patient::~Patient()
{ 
    delete [] Name;
}

Patient::Patient(const Patient& P)
{ 
    Name = new char[strlen(P.Name)+1];
    if(!Name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, P.Name);
    DOB = P.DOB;
    Visits = P.Visits;
}

Patient& Patient::operator=(const Patient& P)
{ 
    if(this != &P)
    { 
        delete [] Name;
        Name = new char[strlen(P.Name)+1];
        if(!Name)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(Name, P.Name);
        DOB = P.DOB;
        Visits = P.Visits;
    }
    return *this;
}

const char* Patient::getName() const
{ 
    return Name;
}

Date Patient::getDOB() const
{ 
    return DOB;
}

int Patient::getVisits() const
{ 
    return Visits;
}

void Patient::print() const
{
    cout << "Име: " << Name << "\n";
    cout << "Дата: "; DOB.print();
    cout << "Брой на визитите: " << Visits << endl; 
}

// дефиниция на клас Doctor
class Doctor
{ 
public:
    // канонично представяне
    Doctor(const char* = "", int = 0);
    ~Doctor();
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    const char* getName() const;    // достъп до име на лекар
    // член-функция за регистрация на пациент
    void registerPatient(const Patient&);
    // член-функция за намиране на
    // средния брой визити на лекаря
    double average() const;
    // извеждане на пациентите, направили по-
    // голям брой визити от указания лимит
    void printUpper(int) const;

private:
    char* Name;                       // име на лекар
    Patient* PatientsList;            // масив с пациентите на лекаря
    int PatientsRegistered;           // брой на регистрираните пациенти
    static int Registered;            // текущ регистриран пациент
};

int Doctor::Registered = 0;     // инициализация на статичната член-данна

Doctor::Doctor(const char* n, int reg)
{ 
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, n);
    PatientsRegistered = reg;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
}

Doctor::~Doctor()
{
    delete [] Name;
    delete [] PatientsList;
}

Doctor::Doctor(const Doctor& D)
{ 
    Name = new char[strlen(D.Name)+1];
    if(!Name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, D.Name);
    PatientsRegistered = D.PatientsRegistered;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    for(int i = 0; i < PatientsRegistered; i++)
        PatientsList[i] = D.PatientsList[i];
}

Doctor& Doctor::operator=(const Doctor& D)
{ 
    if(this != &D)
    { 
        delete [] Name;
        delete [] PatientsList;
        Name = new char[strlen(D.Name)+1];
        if(!Name)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        strcpy(Name, D.Name);
        PatientsRegistered = D.PatientsRegistered;
        PatientsList = new Patient[PatientsRegistered];
        if(!PatientsList)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        for(int i = 0; i < PatientsRegistered; i++)
            PatientsList[i] = D.PatientsList[i];
    }
    return *this;
}

const char* Doctor::getName() const
{ 
    return Name;
}

void Doctor::registerPatient(const Patient& P)
{
    PatientsList[Registered] = P;
    Registered++;
}

double Doctor::average() const
{
    int totalVisits = 0;
    for(int i = 0; i < PatientsRegistered; i++)
        totalVisits += PatientsList[i].getVisits();
    if(PatientsRegistered != 0)
        return double(totalVisits)/PatientsRegistered;
    else return 0;
}

void Doctor::printUpper(int lim) const
{
    cout << "Пациенти с посещения над лимита!\n";
    for(int i = 0; i < PatientsRegistered; i++)
        if(PatientsList[i].getVisits() > lim)
            PatientsList[i].print();
}

int main()
{ 
    int n;
    do
    { 
        cout << "Брой на пациентите на лекар: ";
        cin >> n;
    } while(n < 0 || n > PATIENTS);

    // създаване на списък с данни за пациентите на лекар
    Doctor d1("Petrov", n);
    for(int i = 0; i < n; i++)
    { 
        cin.ignore();
        cout << "Име на пациент: ";
        char NamePatient[MaxLengthName];
        cin.getline(NamePatient, MaxLengthName+1);
        int d, m, y;
        cout << "ден: "; cin >> d;
        cout << "месец: "; cin >> m;
        cout << "година: "; cin >> y;
        Date dat(d, m, y);
        int vis;
        cout << "Брой визити на пациент: ";
        cin >> vis;
        Patient P(NamePatient, dat, vis);
        d1.registerPatient(P);
    }

    // намиране и извеждане на средния брой
    // посещения на пациенти при лекаря
    cout << "Среден брой посещения на пациенти: "
         << d1.average() << endl;
    // извеждане на пациентите, направили
    // повече от 3 посещения при лекаря
    if(n > 0) d1.printUpper(3);
    return 0;
}
