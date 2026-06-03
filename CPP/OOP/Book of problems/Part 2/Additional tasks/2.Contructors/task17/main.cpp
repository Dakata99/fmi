#include <iostream>

class MilitaryTime
{
private:
    int theHours, theMinutes, theSeconds;
    void simplify();
public:
    MilitaryTime(int, int = 0, int = 0);
    MilitaryTime(int);
    MilitaryTime(const MilitaryTime&);
    
    void add(const MilitaryTime&);
    void sub(const MilitaryTime&);
    bool different(const MilitaryTime&)const;
    int totalSeconds()const;

    int hours()const;
    int minutes()const;
    int seconds()const;

    void print();
};

void MilitaryTime::simplify()
{
    if (theSeconds > 59)
    {
        theSeconds -= 60;
        theMinutes++;
    }
    if (theMinutes > 59)
    {
        theMinutes -= 60;
        theHours++;
    }
    if (theHours > 23)
    {
        theHours -= 24;
    }
}
MilitaryTime::MilitaryTime(int aHour, int aMinute, int aSecond)
    :theHours(aHour), theMinutes(aMinute), theSeconds(aSecond){}

MilitaryTime::MilitaryTime(int aSeconds)
{
    while (aSeconds / 60 != 0)
    {
        simplify();
    }
}
MilitaryTime::MilitaryTime(const MilitaryTime& other)
{
    theHours = other.theHours;
    theMinutes = other.theMinutes;
    theSeconds = other.theSeconds;
    
    simplify();
}
void MilitaryTime::add(const MilitaryTime& other)
{
    theHours += other.theHours;
    theMinutes += other.theMinutes;
    theSeconds += other.theSeconds;
    
    simplify();
}
void MilitaryTime::sub(const MilitaryTime& other)
{
    int totalSeconds = this->totalSeconds();
    if (totalSeconds >= other.totalSeconds())
    {
        theHours -= other.theHours;
        theMinutes -= other.theMinutes;
        theSeconds -= other.theSeconds;
    }
    else
    {
        std::cout << "Cannot substract!\n";
    }
}
bool MilitaryTime::different(const MilitaryTime& other)const
{
    return theHours != other.theHours && theMinutes != other.theMinutes && theSeconds != other.theSeconds;
}
int MilitaryTime::totalSeconds()const
{
    return theSeconds + theMinutes*60 + theHours*60*60;
}

int MilitaryTime::hours()const
{
    return theHours;
}
int MilitaryTime::minutes()const
{
    return theMinutes;
}
int MilitaryTime::seconds()const
{
    return theSeconds;
}

void MilitaryTime::print()
{
    simplify();
    std::cout << theHours << ":" << theMinutes << ":" << theSeconds << std::endl;
}

int main()
{
    MilitaryTime m1(12, 43, 52), m2(14, 53, 12), m3(1, 10, 20);
    std::cout << "M1 total seconds: " << m1.totalSeconds() << std::endl;
    std::cout << "M2 total seconds: " << m2.totalSeconds() << std::endl;
    std::cout << "Is M1 different from M2: " << std::boolalpha << m1.different(m2) << std::endl;

    m1.add(m2);
    m1.print();

    m1.sub(m3);
    m1.print();

    return 0;
}