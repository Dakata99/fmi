#include <iostream.h>
#include <string.h>

const int MaxLengthName = 30;        // максимална дължина на име
const int PATIENTS = 200;            // максимален брой пациенти

// дефиниция на клас Date
class Date
{ 
private:
    int theDay,                      // Ден
        theMonth,                    // Месец
        theYear;                     // Година

public:
    Date(int = 1, int = 1, int = 2000);    // конструктор
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

// дефиниция на клас Patient
class Patient
{ 
public:
    Patient();                                // конструктор по подразбиране
    Patient(char *, const Date&, int);        // конструктор с параметри
    const char* getName() const;              // достъп до име
    Date getDOB() const;                      // достъп до дата на раждане
    int getVisits() const;                    // достъп до брой посещения
    void print() const;                       // извеждане на пациент

private:
    char Name[MaxLengthName];                 // име на пациент
    Date DOB;                                 // дата на раждане на пациент
    int Visits;                               // брой посещения на пациента
};

Patient::Patient()
{ 
    Visits = 0;
}

Patient::Patient(char * n, const Date& d, int v)
{ 
    strcpy(Name, n);
    DOB = d;
    Visits = v;
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
    Doctor(char*);                          // конструктор
    const char* getName() const;            // достъп до име 
    //регистриране на пациент
    void registerPatient(const Patient&);
    // намиране на средния брой на посещенията на пациентите
    double average() const;
    // извеждане на пациентите, направили по-голям брой
    // посещения от указания като параметър брой
    void printUpper(int) const;

private:
    char Name[MaxLengthName];               // име на лекар
    Patient PatientsList[PATIENTS];         // масив с пациентите на лекаря
    int PatientsRegistered;                 // брой на регистрираните пациенти
};

Doctor::Doctor(char* n)
{
    strcpy(Name, n);
    PatientsRegistered = 0;
}

const char* Doctor::getName() const
{ 
    return Name;
}

void Doctor::registerPatient(const Patient& P)
{ 
    PatientsList[PatientsRegistered] = P;
    PatientsRegistered++;
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
    // дефиниране на лекар
    Doctor d1("Petrov");
    // въвеждане на броя на пациентите на лекаря
    int n; 
    do
    { 
        cout << "Брой на пациентите: ";
        cin >> n;
    } while (n < 0 || n > PATIENTS);

    // регистриране на пациентите
    for(int i = 0; i < n; i++)
    { 
        // прескачане на знака за край на ред
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
    cout << "Среден брой посещения при лекаря " 
        << d1.average() << endl;
    // извеждане на пациентите, направили повече от 3 посещения
    if(n > 0) d1.printUpper(3);
    return 0;
}
