#include <iostream.h>

const int SIZE = 16;
const int SIZEMAX = 20;

// декларация на структурата Person
struct Person
{
    char f_name[SIZE];                        // собствено име
    char l_name[SIZE];                        // фамилно име
};

// въвеждане на данни за лице
void read_person(Person& P)
{
    cout << "Собствено име: ";
    cin >> P.f_name;
    cout << "Фамилно име: ";
    cin >> P.l_name;
}
// извеждане на данните за лице
void print_person(const Person& P)
{
    cout << "Собствено име: " << P.f_name << endl
         << "Фамилно име: "   << P.l_name << endl;
}

// декларация на структурата Client
struct Client
{
    Person name;                        // лице
    double amount;                      // сума в банкова сметка
};

// въвеждане на данни за клиент
void read_client(Client& C)
{
    cout << "Име на клиент: \n"; 
    read_person(C.name);
    cout << "Сума на клиента: "; 
    cin >> C.amount;
}

// извеждане на данни за клиент
void print_client(const Client& C)
{
    cout << "Име на клиент:\n";
    print_person(C.name);
    cout << "Сума на клиента: " << C.amount << endl;
}

int main()
{
    // а)
    // въвеждане на имената и банковите
    // сметки на множество от клиенти
    cout << "Въведете стойност за n от 1 до "
         << SIZEMAX << ": ";
    int n; cin >> n;
    Client a[SIZEMAX];
    int i;
    for(i = 0; i < n; i++)
        read_client(a[i]);

    // б)
    // извеждане на имената и банковите
    // сметки на клиентите от множеството
    cout << "Клиенти на банката: \n";
    for(i = 0; i < n; i++)
        print_client(a[i]);

    // в)
    // намиране на сумата от задълженията
    // на клиентите от множеството
    double S = 0;
    for(i = 0; i < n; i++)
        if (a[i].amount < 0) S += a[i].amount;
    cout << "Сумата от задълженията на клиентите е: "
         << S << endl;
    return 0;
}
