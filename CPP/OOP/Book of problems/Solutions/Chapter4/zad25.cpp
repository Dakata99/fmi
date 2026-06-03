#include <iostream.h>
#include <string.h>

// кодове, служещи за различаване на обектите
// от класовете Developer и Manager
enum Type {DEVELOPER = 1, MANAGER};

class Employee
{ 
public:
    Employee(char* name, int period, double salary) : name(0)
    { 
        setName(name);
        setPeriod(period);
        setSalary(salary);
    }

    // конструкторът за присвояване е задължителен
    // заради наличността на динамични член-данни
    Employee(const Employee &e) : name(0)
    { 
        setName(e.name);
        setPeriod(e.period);
        setSalary(e.salary);
    }

    // operator= е задължителен заради
    // наличността на динамични член-данни
    Employee& operator=(const Employee &e)
    { 
        if(&e != this)
        { 
            setName(e.name);
            setPeriod(e.period);
            setSalary(e.salary);
        }
        return *this;
    }

    void setName(char* _name)
    { 
        if(name != NULL)
            delete name;
        name = new char [strlen(_name)+1];
        strcpy(name, _name);
    }

    void setPeriod(int _period)
    { 
        period = _period;
    }

    void setSalary(double _salary)
    { 
        salary = _salary;
    }

    const char *getName() const
    { 
        return name;
    }

    int getPeriod() const
    { 
        return period;
    }

    double getSalary() const
    { 
        return salary;
    }

    // деструкторът е задължителен поради
    // наличността на динамични член-данни
    virtual ~Employee()
    { 
        if(name != NULL)
            delete name;
    }

    // чист виртуален метод
    // Наследниците на класа са "длъжни" да го
    // реализират. В противен случай и те ще са
    // със статут на абстрактни класове и за тях
    // няма да могат да се дефинират обекти
    virtual Type type() = 0;

    virtual void print()
    { 
        cout << "Име: " << name << endl 
             << "Стаж: " << period << endl 
             << "Заплата: " << salary << endl;
    }

protected:
    char *name;				// име
    int period;				// стаж
    double salary;			// заплата
};

class Developer : public Employee
{ 
public:
    Developer(char* name, int period, double salary, bool _knowsCpp, bool _knowsCs) :
              Employee(name, period, salary), 
              knowsCpp(_knowsCpp),
              knowsCs(_knowsCs)
    {};

    Type type()
    { 
        return DEVELOPER;
    }

    bool getKnowsCpp()
    { 
        return knowsCpp;
    }

    bool getKnowsCs()
    { 
        return knowsCs;
    }

    void setKnowsCpp(bool _knowsCpp)
    { 
        knowsCpp = _knowsCpp;
    }

    void setKnowsCs(bool _knowsCs)
    { 
        knowsCs = _knowsCs;
    }

    virtual void print()
    { 
        cout << "Разработчик " << endl;
        Employee::print();
        cout << " Знае C++? = " << (knowsCpp?"yes":"no") << endl
             << " Знае C#? = " << (knowsCs?"yes":"no") << endl;
    }

protected:
    bool knowsCpp, knowsCs;
};

class Manager : public Employee
{ 
public:
    Manager(char* name, int period, double salary, int _inChargeOf) :
            Employee(name, period, salary), inChargeOf(_inChargeOf)
    {};

    Type type()
    { 
        return MANAGER;
    }

    int getInChargeOf()
    { 
        return inChargeOf;
    }

    void setInChargeOf(int _inChargeOf)
    { 
        inChargeOf = _inChargeOf;
    }

    virtual void print()
    { 
        cout << "Мениджър " << endl;
        Employee::print();
        cout << " Управлявани: " << inChargeOf << endl;
    }

protected:
    int inChargeOf;
};

// Динамичен списък от служители
class EmployeeList
{
public:
    EmployeeList()
    { 
        capacity = 3;
        size = 0;
        employees = new Employee*[capacity];
    }

    // включване на нов елемент
    bool insert(Employee* newEmployee)
    { 
        // проверка за място
        if(size == capacity && !resize())
            return false;
        employees[size++] = newEmployee;
        return true;
    }

    // изтриване на всички елементи, които не удовлетворяват предиката pred
    void filter(bool (*pred)(Employee*))
    { 
        // първоначално всички изтрити обекти в масива ще се
        // заменят с NULL, след което масивът ще бъде "сгъстен"
        int i;
        for(i = 0; i < size; i++)
        {
            if(!pred(employees[i]))
            { 
                delete employees[i];
                employees[i] = 0;
            }
        }

        // текущо обработван елемент
        int currentElement = 0;
        // индекс на следващия ненулев елемент
        int currentRealElement = 0;

        // сгъстяване на масива чрез преместване на неговите
        // елементи надясно по такъв начин, че да препокрият
        // нулевите елементи
        while(currentRealElement < size)
        { 
            // намиране на следващия ненулев елемент
            while(currentRealElement < size && employees[currentRealElement] == NULL)
                currentRealElement++;
            if(currentRealElement < size)
            {
                // преди срещане на първия нулев елемент, currentElement == currentRealElement
                employees[currentElement] = employees[currentRealElement];
                currentElement++;
                currentRealElement++;
            }
        }
        size = currentElement;
    }

    // прилагане на функцията f над
    // всички елементи на списък
    void map(void (*f)(Employee*))
    { 
        for(int i = 0; i < size; i++)
            f(employees[i]);
    }

    // прилагане на функцията op над всеки от
    // елементите и комбиниране на получените
    // числа чрез двуместната операция comb
    double accumulate(double (*op)(Employee*), double (*comb)(double, double), double nullVal)
    { 
        double result = nullVal;
        for(int i = 0; i < size; i++)
            result = comb(result, op(employees[i]));
        return result;
    }

    ~EmployeeList()
    {
        for(int i = 0; i < size; i++)
            delete employees[i];
        delete [] employees;
    }

private:
    // увеличаване на размера на динамичния масив
    bool resize()
    { 
        Employee ** newArray = new Employee*[capacity*2];
        if(newArray == NULL)
            return false;
        for(int i = 0; i < capacity; i++)
            newArray[i] = employees[i];
        Employee **tmp = employees;
        employees = newArray;
        delete tmp;
        capacity *= 2;
        return true;
    }

    // динамичен масив със служители
    Employee **employees;
    // текущ брой "заети" елементи в масива
    int size;
    // общ брой елементи (големина) на масива
    int capacity;
};

bool filterLessThan3Months(Employee* emp)
{ 
    return emp->getPeriod () >= 3;
}

void increseSalary(Employee* emp)
{ 
    if (emp->type() == DEVELOPER && ((Developer*)emp)->getKnowsCs() && !((Developer*)emp)->getKnowsCpp())
        emp->setSalary(emp->getSalary() + 100);
    if (emp->type() == DEVELOPER && ((Developer*)emp)->getKnowsCpp())
        emp->setSalary(emp->getSalary() + 500);
}

void printEmployee(Employee* emp)
{ 
    emp->print();
}

double getSalary(Employee* emp)
{ 
    return emp->getSalary();
}

double plus(double a, double b)
{
    return a + b;
}

class SoftwareCompany
{
public:
    // добавя служител към регистъра
    void newEmployee()
    { 
        char type;
        cout << "Тип служител (d/m):";
        cin >> type;
        Employee* newEmployee = createEmployee(type);
        if(newEmployee)
            list.insert(newEmployee);
    }

    // изтриване на служителите със стаж
    // по-малък от 3 месеца
    void removeRecentlyEmployed()
    { 
        list.filter(filterLessThan3Months);
    }

    // увеличаване на заплати
    void increaseSalaries()
    { 
        list.map(increseSalary);
    }

    // извеждане на данните
    void printAll()
    { 
        list.map(printEmployee);
    }

    // сумиране на заплатите
    double sumSalaries()
    { 
        return list.accumulate(getSalary, plus, 0);
    }

private:
    // четене на общите данни за двата
    // вида служители
    void readCommonData(Employee *e)
    { 
        char name[500];
        cout << "Име: "; cin >> name;
        e->setName(name);
        int period;
        cout << "Стаж: "; cin >> period;
        e->setPeriod(period);
        double salary;
        cout << "Заплата: "; cin >> salary;
        e->setSalary(salary);
    }

    Developer* createDeveloper()
    { 
        Developer *developer = new Developer("", 0, 0, false, false);
        int knows;
        readCommonData(developer);
        bool knowsCpp, knowsCs;
        cout << "Знае ли Cpp (1/0)?: ";
        cin >> knows;
        knowsCpp = knows == 1;
        developer->setKnowsCpp(knowsCpp);
        cout << "Знае ли C# (1/0)?: ";
        cin >> knows;
        knowsCs = knows == 1;
        developer->setKnowsCs(knowsCs);
        return developer;
    }

    Manager* createManager()
    {
        Manager *manager = new Manager("", 0, 0, 0);
        readCommonData(manager);
        int inChargeOf;
        cout << "Колко човека ръководи?:";
        cin >> inChargeOf;
        manager->setInChargeOf(inChargeOf);
        return manager;
    }

    // в зависимост от type създава Developer или Manager
    Employee* createEmployee(char type)
    { 
        switch(type)
        { 
        case 'd': return createDeveloper();
        case 'm': return createManager();
        }
        return NULL;
    }
    EmployeeList list;
};

int main()
{ 
    SoftwareCompany company;
    company.newEmployee();
    company.newEmployee();
    company.removeRecentlyEmployed();
    company.increaseSalaries();
    company.printAll();
    cout << "Сума от заплати: " << company.sumSalaries()
         << endl;
    return 0;
}
