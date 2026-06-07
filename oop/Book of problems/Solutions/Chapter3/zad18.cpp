#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class Date
{ 
private:
    int theDay,                      // Ден
        theMonth,                    // Месец
        theYear;                     // Година

public:
    Date(int = 1, int = 1, int = 2000); // конструктор
    int Day() const;                    // достъп до ден
    int Month() const;                  // достъп до месец
    int Year() const;                   // достъп до година
    void setDay(int);                   // промяна на ден
    void setMonth(int);                 // промяна на месец
    void setYear(int);                  // промяна на година
    void print() const;                 // извеждане на дата
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


const int MaxLengthName = 30;        // максимална дължина на име
const int PATIENTS = 100;            // максимален брой на пациентите
const Date DATE(1, 1, 1900);         // подразбираща се дата

// дефиниция на клас Person
class Person
{ 
public:

    // канонично представяне
    Person(const char* = "", const Date& = DATE);
    ~Person();
    Person(const Person&);
    Person& operator=(const Person&);
    // член-функции за достъп
    const char* getName() const;    // достъп до име
    Date getDOB() const;            // достъп до дата на раждане
    void print() const;             // извеждане на данните за лице
private:
    char* Name;                     // име на лице
    Date DOB;                       // дата на раждане на лице
};

Person::Person(const char* n, const Date& d)
{
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, n);
    DOB = d;
}

Person::~Person()
{
    delete [] Name;
}

Person::Person(const Person& P)
{
    Name = new char[strlen(P.Name)+1];
    if(!Name)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    strcpy(Name, P.Name);
    DOB = P.DOB;
}

Person& Person::operator=(const Person& P)
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
    }
    return *this;
}

const char* Person::getName() const
{ 
    return Name;
}

Date Person::getDOB() const
{
    return DOB;
}

void Person::print() const
{
    cout << "Име: " << Name << "\n";
    cout << "Дата: "; DOB.print();
}

// дефиниция на клас Patient
class Patient : public Person
{
public:
    // конструктор
    Patient(char * = "", Date = DATE, int = 0);
    int getVisits() const;        // достъп до брой визити
    void print() const;           // извеждане на пациент

private:
    int Visits;                   // брой посещения на пациента
};

Patient::Patient(char * n, Date d, int v) : Person(n, d)
{
    Visits = v;
}

int Patient::getVisits() const
{
    return Visits;
}

void Patient::print() const
{
    Person::print();
    cout << "Брой на визитите: " << Visits << endl; 
}

// дефиниция на клас Doctor
class Doctor : public Person
{
public:
    // канонично представяне
    Doctor(char* = "", const Date& = DATE, int = 0);
    ~Doctor();
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    // 
    void registerPatient(const Patient&);
    // член-функция за намиране на средния брой визити на лекар
    double average() const;
    // извеждане на пациентите, направили по-голям
    // брой визити от указаното количество
    void printUpper(int) const;

private:
    Patient* PatientsList;      // списък с пациентите на лекар
    int PatientsRegistered;     // брой на регистрираните пациенти
    static int Registered;      // пореден номер на регистриран пациент
};

int Doctor::Registered = 0;     // инициализация на статичната член-данна

Doctor::Doctor(char* n, const Date& d, int reg) : Person(n, d)
{
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
    delete [] PatientsList;
}

Doctor::Doctor(const Doctor& d) : Person(d)
{
    PatientsRegistered = d.PatientsRegistered;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    for(int i = 0; i < PatientsRegistered; i++)
        PatientsList[i] = d.PatientsList[i];
}

Doctor& Doctor::operator=(const Doctor& d)
{
    if(this != &d)
    {
        Person::operator=(d);
        delete [] PatientsList;
        PatientsRegistered = d.PatientsRegistered;
        PatientsList = new Patient[PatientsRegistered];
        if(!PatientsList)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        for(int i = 0; i < PatientsRegistered; i++)
            PatientsList[i] = d.PatientsList[i];
    }
    return *this;
}

void Doctor::registerPatient(const Patient& p)
{
    PatientsList[Registered] = p;
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
    // въвеждане на броя на пациентите на лекар
    int n;
    do
    {
        cout << "Брой на пациентите: ";
        cin >> n;
    } while(n < 0 || n > PATIENTS);

    // създаване на датата на раждане на лекар
    Date DOB_Petrov(5, 10, 1975);
    // създаване на обект, представящ "лекар" с n пациента
    Doctor d1("Petrov", DOB_Petrov, n);
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
        cout << "Брой визити на пациент:";
        cin >> vis;
        Patient P(NamePatient, dat, vis);
        d1.registerPatient(P);
    }

    // извеждане на средния брой посещения при лекаря
    cout << d1.average() << endl;

    // извеждане на пациентите, направили повече от 3 посещения
    if(n > 0) d1.printUpper(3);
    return 0;
}
