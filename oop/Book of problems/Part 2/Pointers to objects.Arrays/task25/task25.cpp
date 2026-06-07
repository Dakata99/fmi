#include <iostream>
#include <string>

class Date
{
private:
    size_t day, month, year;
public:
    Date():day(1), month(1), year(2000){}
    Date(const size_t& day, const size_t& month, const size_t& year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Date(const Date& date)
    {
        this->day = date.getDay();
        this->month = date.getMonth();
        this->year = date.getYear();
    }
    
    //getters
    size_t getDay()const
    {
        return day;
    }
    size_t getMonth()const
    {
        return month;
    }
    size_t getYear()const
    {
        return year;
    }

    //setters
    void setDay(const size_t day)
    {
        this->day = day;
    }
    void setMonth(const size_t month)
    {
        this->month = month;
    }
    void setYear(const size_t year)
    {
        this->year = year;
    }

    //print
    void printDate()const
    {
        std::cout << "Date: " << day << "." << month << "." << year << std::endl;
    }
    
};

class Patient
{
private:
    std::string name;
    size_t visits;
    Date birth;
public:
    Patient():name(""), visits(0), birth(){}
    Patient(const std::string name, const size_t& visits, const Date& date)
    {
        this->name = name;
        this->visits = visits;
        this->birth = date;
    }
    
    //setters
    void setName(const std::string& name)
    {
        this->name = name;
    }
    void setDay(const Date& date)
    {
        birth.setDay(date.getDay());
        birth.setMonth(date.getMonth());
        birth.setYear(date.getYear());
    }
    void setVisits(const size_t visits)
    {
        this->visits = visits;
    }

    //getters
    std::string getName()const
    {
        return name;
    }
    Date getDate()const
    {
        return birth;
    }
    size_t getVisits()const
    {
        return visits;
    }

    //print
    void printInfo()const
    {
        std::cout << "Name: " << name << std::endl;
        birth.printDate();
        std::cout << "Visits: " << visits << std::endl;
    }
};

class Doctor
{
private:
    std::string name;
    size_t registered;
    size_t capacity;
    Patient* pats;
public:
    //Doctor():name(""), registered(0), capacity(0), pats(nullptr){}
    Doctor(const std::string name, const size_t num)
    {
        this->name = name;
        registered = 0;
        capacity = num;
        pats = new Patient[capacity];
    }
    
    //getters
    std::string getName()const
    {
        return name;
    }
    
    //funcs
    void regPatient(const Patient& pat)
    {
        if (registered >= capacity - 1)
        {
            capacity++;
            Patient* temp = new Patient[capacity];
            for (size_t i = 0; i < registered; i++)
            {
                temp[i] = pats[i];
            }

            delete[]pats;
            pats = new Patient[capacity];
            for (size_t i = 0; i < registered; i++)
            {
                pats[i] = temp[i];
            }
            
            delete[]temp;
        }
        pats[registered] = pat;
        registered++;
    }
    size_t average()const
    {
        size_t aver = 0;
        for (size_t i = 0; i < registered; i++)
        {
            aver += pats[i].getVisits();
        }
        return aver/registered;
    }
    void printUpper(const size_t limit)const
    {
        std::cout << "Patients with visits over the limit - " << limit << ": " << std::endl;
        for (size_t i = 0; i < registered; i++)
        {
            if (pats[i].getVisits() >= limit)
            {
                pats[i].printInfo();
            }
        }
    }

    //print
    void print()const
    {
        std::cout << "Doctors name: " << name << std::endl;
        for (size_t i = 0; i < registered; i++)
        {
            pats[i].printInfo();
        }
    }

    ~Doctor()
    {
        delete[]pats;
    }
};

void func()
{
    Doctor who("Petrov", 2);
    who.regPatient(Patient("Daniel Lyubenov", 20, Date(3, 12, 1999)));
    who.regPatient(Patient("Iliqna Qneva", 32, Date(17, 5, 1976)));
    who.regPatient(Patient("Plamen Qnev", 12, Date(30, 3, 1971)));
    who.regPatient(Patient("Elena B", 5, Date(2, 5, 2005)));


    //who.print();
    //std::cout << who.getName();
    std::cout << who.average() << std::endl;
    who.printUpper(15);

}

int main()
{
    func();

    return 0;
}