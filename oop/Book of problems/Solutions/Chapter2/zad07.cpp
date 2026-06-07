#include <iostream.h>
#include <iomanip.h>

class Employee
{ 
public:
    void read();              // въвеждане на данни за чиновник
    void print() const;       // извеждане на данни за чиновник

private:
    struct
    { 
        char first[16];       // собствено име
        char last[16];        // фамилно име
    } name;
    struct
    { 
        double hours;         // часове на работа
        double salary;        // заплата за 1 час
    } work;
};

void Employee::read()
{
    cout << "Собствено име: ";
    cin >> name.first;
    cout << "Фамилно име: ";
    cin >> name.last;
    cout << "Часове на работа: ";
    cin >> work.hours;
    cout << "Заплащане за 1 час: ";
    cin >> work.salary;
    cin.ignore();    // прескачане на знаците за край на ред
}

void Employee::print() const
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << name.first << " " << name.last << " "
         << work.hours * work.salary << endl;
}

int main()
{
    // дефиниране на чиновник
    Employee e; 
    e.read();
    // извеждане на името и заплатата на чиновник
    e.print();
    return 0;
}
