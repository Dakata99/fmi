#include <iostream.h>
#include <string.h>

// дефиниция на клас PersonalData
class PersonalData
{
public:
    // канонично представяне
    PersonalData();
    PersonalData(const PersonalData&);
    PersonalData& operator=(const PersonalData&);
    ~PersonalData();
    // въвеждане на данни
    void read();
    // извеждане на данни
    void print() const;

private:
    char *name;                       // име
    int birthYear;                    // година на раждане
    void copy(const PersonalData&);
};

PersonalData::PersonalData() : name(NULL), birthYear(0)
{} 

PersonalData::PersonalData(const PersonalData& data) :
                           name(NULL)
{
    copy(data);
}

PersonalData& PersonalData::operator=(const PersonalData& data)
{
    if(this != &data)
        copy(data);
    return *this;
}

PersonalData::~PersonalData()
{
    if(name != NULL)
        delete name;
}

void PersonalData::read()
{
    char nameTmp[255];
    cout << "Лично име: ";
    cin >> nameTmp;
    if(name != NULL)
        delete name;
    name = new char[strlen(nameTmp)+1];
    strcpy(name, nameTmp);
    cout << "Година на раждане: ";
    cin >> birthYear;
}

void PersonalData::print() const
{
    cout << "Лично име: "
         << name << endl
         << "Година на раждане: "
         << birthYear << endl;
}

void PersonalData::copy(const PersonalData& data)
{
    if(name != NULL)
        delete name;
    name = NULL;
    if(data.name != NULL)
    {
        name = new char [strlen(data.name)+1];
        strcpy (name, data.name);
    }
    birthYear = data.birthYear;
}

// дефиниция на клас Class
class Class
{
public:
    // конструктор по подразбиране
    Class();
    // въвеждане на данни
    void read();
    // извеждане на данни
    void print() const;

private:
    int year;                // випуск
    int childrenCount;       // брой ученици
    int classId;             // номер на паралелка
};

Class::Class() : year(0), childrenCount(0), classId(0)
{}

void Class::read()
{
    cout << "Випуск: ";
    cin >> year;
    cout << "Брой ученици: ";
    cin >> childrenCount;
    cout << "Паралелка: ";
    cin >> classId;
}

void Class::print() const
{
    cout << "Випуск: " <<  year << endl
         << "Брой ученици:" << childrenCount << endl
         << "Паралелка: " << classId << endl;
}

// дефиниция на клас Car
class Car
{
public:
    // канонично представяне
    Car();
    Car(const Car&);
    Car& operator=(const Car&);
    ~Car();
    // въвеждане на данни
    void read();
    // извеждане на данни
    void print() const;

private:
    char *model;                    // модел
    char registration[10];          // регистрационен номер
    void copy(const Car&);
};

Car::Car() : model(NULL)
{}

Car::Car(const Car& data) : model(NULL)
{
    copy (data);
}

Car& Car::operator=(const Car& data)
{
    if(this != &data)
        copy (data);
    return *this;
}

Car::~Car()
{
    if(model != NULL)
        delete model; 
}

void Car::read()
{
    char nameTmp[255];
    cout << "Модел: ";
    cin >> nameTmp;
    if(model != NULL)
        delete model;
    model = new char[strlen(nameTmp)+1];
    strcpy(model, nameTmp);
    cout << "Регистрационен номер: ";
    cin >> registration;
}

void Car::print() const
{
    cout << "Модел: " <<  model << endl
         << "Регистрационен номер: " << registration << endl;
}

void Car::copy(const Car& data)
{
    if(model != NULL)
        delete model;
    model = NULL;
    if(data.model != NULL)
    {
        model = new char[strlen(data.model)+1];
        strcpy(model, data.model);
    }
    strcpy(registration, data.registration);
}

class Teacher : public PersonalData, public Class
{
public:
    // въвеждане на данни
    void read();
    // извеждане на данни
    void print() const;
};

void Teacher::read()
{
    PersonalData::read();
    Class::read();
}

void Teacher::print() const
{
    PersonalData::print();
    Class::print();
}

class CarOwner : public PersonalData, public Car
{
public:
    // въвеждане на данни
    void read();
    // извеждане на данни
    void print() const;
};

void CarOwner::read()
{
    PersonalData::read();
    Car::read();
}

void CarOwner::print() const
{
    PersonalData::print(); 
    Car::print();
}

int main()
{
    Teacher t;
    CarOwner co;
    t.read();
    co.read();
    cout << "\n============\n";
    t.print();
    cout << "\n============\n";
    co.print();
    return 0;
}
