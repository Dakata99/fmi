#include <iostream>

class Time
{
private:
    size_t hours, mins;
    void simplify()
    {
        if(mins >= 60)
            mins -= 60;
            hours++;
    }
public:
    Time():hours(0), mins(0){}
    Time(const size_t _hours, const size_t _mins):hours(_hours), mins(_mins){}

    //getters
    size_t getHours()const
    {
        return hours;
    }
    size_t getMins()const
    {
        return mins;
    }

    //setters
    void setHours(const size_t _hours)
    {
        hours = _hours;
    }
    void setMins(const size_t _mins)
    {
        mins = _mins;
        if (mins > 60)
        {
            mins-=60;
            hours++;
        }
    }

    //operators
    Time operator+(const Time& other)
    {
        return Time(hours + other.getHours(), mins + other.getMins());
    }
    Time operator-(const Time& other)
    {
        return Time(abs(hours - other.getHours()), abs(mins - other.getMins()));
    }
    Time operator*(const size_t num)
    {
        mins = (hours*60 + mins)*num;
        hours = mins/60;
        mins = mins%60;

        return Time(hours, mins);
    }

    operator int()const
    {
        return hours*60 + mins;
    }

    //funcs
    void addHours(const size_t _hours)
    {
        hours += _hours;
        simplify();
    }
    void addMins(const size_t _mins)
    {
        mins += _mins;
        simplify();
    }
    
    void print()
    {
        simplify();
        std::cout << "Hours: " << hours << std::endl;
        std::cout << "Minutes: " << mins << std::endl;
    }

};

void func()
{
    Time t1(5, 20), t2(3, 40);
    
    Time t3 = t1 + t2;
    Time t4 = t1 - t2;
    Time t5 = t1 * 5;
    //Time t6 = t2 * 3;

    t3.print();
    t4.print();
    //t5.print();
    //t6.print();

}

int main()
{
    func();

    return 0;
}