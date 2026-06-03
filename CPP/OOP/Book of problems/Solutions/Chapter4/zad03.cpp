#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class Date
{
private:
    int day,              // ден
        month,            // месец
        year;             // година

public:
    Date(int, int, int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{ 
    return year;
}

class Time
{
private:
    int hour,               // час
        min,                // минути
        sec;                // секунди

public:
    Time(int, int, int);
    int getHour() const;
    int getMin() const;
    int getSec() const;
};

Time::Time(int h, int m, int s) : 
hour(h), min(m), sec(s)
{}

int Time::getHour() const
{
    return hour;
}

int Time::getMin() const
{
    return min;
}

int Time::getSec() const
{
    return sec;
}

class DateTime : public Date, public Time
{
private:
    char dateTimeString[20];        // дата и време

public:
    DateTime(int, int, int, int, int, int);
    char* getDateTime();
};

DateTime::DateTime(int d, int m, int y, int h, int mn, int s) :
                   Date(d, m, y), Time(h, mn, s)
{
    char temp[10];
    // запомняне на датата в низа dateTimeString във формат мм/дд/гг
    strcpy(dateTimeString, itoa(getMonth(), temp, 10));
    strcat(dateTimeString, "/");
    strcat(dateTimeString, itoa(getDay(), temp, 10));
    strcat(dateTimeString, "/");
    strcat(dateTimeString, itoa(getYear(), temp, 10));
    strcat(dateTimeString, " ");
    // запомняне на часа в низа dateTimeString във формат чч:мм:сс
    strcat(dateTimeString, itoa(getHour(), temp, 10));
    strcat(dateTimeString, ":");
    strcat(dateTimeString, itoa(getMin(), temp, 10));
    strcat(dateTimeString, ":");
    strcat(dateTimeString, itoa(getSec(), temp, 10));
    strcat(dateTimeString, " ");
}

char* DateTime::getDateTime()
{
    return dateTimeString;
}

int main()
{
    DateTime d(21, 11, 8, 4, 35, 12);
    cout << d.getDateTime() << endl;
    return 0;
}
