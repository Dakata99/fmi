#include <iostream.h>

// дефиниция на класа Time
class Time
{
private:
    int hours;                  // часове
    int minutes;                // минути
    void simplify();

public:
    // конструктори
    Time();
    Time(int, int = 0);
    Time(Time const&);
    // мутатор на час и минути
    void reset(int = 0, int = 0);
    // мутатор, добавящ минути
    void addMin(int);
    // мутатор, добавящ часове
    void addHours(int);
    // операторна функция за преобразуване на време
    // в цяло число, изразяващо времето в минути
    operator int() const;
    // извеждане на време
    void print() const;
    // операторна функция, събираща две времена
    Time operator+(const Time &) const;
    // операторна функция, изваждаща две времена
    Time operator-(const Time &) const;
    // операторна функция, умножаваща време с цяло число
    Time operator*(int) const;
    // приятелска функция, умножаваща цяло число с време
    friend Time operator*(int m, const Time &t)
    { 
        return t * m;     // умножава времето t с цялото число m
    }
};

void Time::simplify()
{ 
    if(minutes >= 60)
    { 
        hours  += minutes / 60;
        minutes = minutes % 60;
    }
}

Time::Time()
{ 
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    reset(h, m);
}

Time::Time(Time const& r)
{
    hours = r.hours;
    minutes = r.minutes;
}

void Time::reset(int h, int m)
{ 
    hours = h;
    minutes = m;
    simplify();
}

void Time::addMin(int m)
{
    minutes = minutes + m;
    simplify();
}

void Time::addHours(int h)
{ 
    hours = hours + h;
}

void Time::print() const
{ 
    cout << hours << " hours, " << minutes << " minutes\n";
}

// операторна функция за преобразуване на време
// в цяло число, изразяващо времето в минути
Time::operator int() const
{
    return hours*60 + minutes;
}

// операторна функция за събиране на две времена
Time Time::operator+(const Time& t) const
{ 
    Time new_t;
    new_t.minutes = minutes + t.minutes;
    new_t.hours = hours + t.hours;
    new_t.simplify();
    return new_t;
}

// операторна функция за изваждане на две времена
Time Time::operator-(const Time& t) const
{ 
    Time new_t;
    int m1, m2;
    m1 = t.hours*60 + t.minutes;
    m2 = hours*60 + minutes;
    new_t.minutes = (m2 - m1) % 60;
    new_t.hours = (m2 - m1) / 60;
    return new_t;
}

// операторна функция за умножение на време с цяло число
Time Time::operator*(int mult) const
{ 
    Time new_t;
    int m = (hours*60 + minutes) * mult;
    new_t.hours = m / 60;
    new_t.minutes = m % 60;
    return new_t;
}

int main()
{ 
    // дефиниране и извеждане на две времена t1 и t2
    Time t1(3, 10), t2(12);
    t1.print();
    t2.print();
    // дефиниране чрез конструктора за присвояване и извеждане на време t3
    Time t3 = t2;
    t3.print();
    // добавяне на 105 минути към време t3
    t3.addMin(105);
    // извеждане на време t3
    t3.print();
    // добавяне на 6 часа към време t2
    t2.addHours(6);
    // извеждане на време t2
    t2.print();
    // събиране на две времена
    t1 = t3 + t2;
    // извеждане на време t1
    t1.print();
    // изваждане на две времена
    t1 = t2 - t3;
    // извеждане на време t1
    t1.print();
    // умножение на време t1 с 2
    t1 = t1 * 2;
    // извеждане на време t1
    t1.print();
    // умножение на 6 с време t1 и извеждане
    (6 * t1).print();
    // извеждане на броя на минутите на времето t1
    cout << t1 << endl;
    return 0;
}
