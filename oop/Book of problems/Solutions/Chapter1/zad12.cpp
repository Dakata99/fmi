#include <iostream.h>
#include <iomanip.h>
#include <string.h>

int k;                           // брой на учебните дисциплини
const int SIZE = 12;             // максимална дължина на име
const int SIZE_MAX1 = 10;        // максимален брой на
// учебните дисциплини
const int SIZE_MAX2 = 25;        // максимален брой на
// студентите от групата

// декларация на структурата Student
struct Student
{
    int fac_n;                  // факултетен номер на студент
    char name[SIZE];            // Фамилия на студент
    double subjects[SIZE_MAX1]; // масив с оценките на студент
};

// въвеждане на данни за студент
void create_student(Student& s)
{
    do
    {
        cout << "Факултетен номер: ";
        cin >> s.fac_n;
    } while(s.fac_n <= 0 || s.fac_n > 99999);

    cout << "Фамилия: "; cin >> s.name;
    for(int i = 0; i < k; i++)
    {
        cout << "Оценка по " << i+1 << "-и предмет: ";
        cin >> s.subjects[i];
    }
}

// извеждане на данните за студент
void print_student(const Student& s)
{
    cout << setw(5) << s.fac_n
        << setw(SIZE+2) << s.name;
    for(int i = 0; i < k; i++)
        cout << setw(5) << s.subjects[i];
}

// намиране на средния успех на студент
double result(const Student& s)
{
    double u = 0;
    for(int i = 0; i < k; i++)
        u += s.subjects[i];
    u /= k;
    return u;
}

// а)
// въвеждане на данни за студентите от една група
void create_group(int n, Student *s)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Данни за " << i+1 << "-и студент: ";
        create_student(s[i]);
    }
}

// б)
// извеждане на заглавието (антетката) на таблицата
void print_table()
{
    cout << setiosflags(ios::fixed|ios::showpoint)
        << setprecision(2);
    int i;
    for(i = 0; i < 5+SIZE+2+5*(k+1)+1; i++)
        cout << "=";
    cout << endl;
    cout << setw(5) << "Ф.Н."
        << setw(SIZE+2) << "Фамилия";

    for(i = 0; i < k; i++)
        cout << setw(4) << "Д-" << i+1;
    cout << setw(6) << "Ср.у." << endl;
    for(i = 0; i < 5+SIZE+2+5*(k+1)+1; i++)
        cout << "=";
    cout << endl;
}

// извеждане на таблицата с данните
// за студентите от групата
void print_group(int n, Student *s)
{
    // извеждане на заглавието на таблицата 
    print_table();
    int i, j;

    // намиране на средния успех по всяка учебна дисциплина
    double temp[SIZE_MAX1] = {0, };
    for(j = 0; j < k; j++)
    {
        for(i = 0; i < n; i++)
            temp[j] = temp[j] + s[i].subjects[j];
        temp[j] = temp[j]/n;
    }

    // извеждане на данните за студентите и
    // намиране на сумата sum от средния
    // успех на всички студенти
    double sum = 0;
    for(i = 0; i < n; i++)
    {
        print_student(s[i]);
        double res = result(s[i]);
        sum += res;
        cout << setw(6) << res << endl;
    }
    for(i = 0; i < 5+SIZE+2+5*(k+1)+1; i++)
        cout << "=";

    // извеждане на средния успех на студентите
    // от групата по всички предмети
    cout << endl << setw(5+SIZE+2+5) << temp[0];
    for(j = 1; j < k; j++)
        cout << setw(5) << temp[j];
    cout << setw(6) << sum/n << endl;
}

// в)
// сортиране сортира във възходящ ред по фамилия
// и в низходящ ред по среден успех 
// масива от указатели към данните за студентите
// чрез метода на пряката селекция
void sortgroup(int n, Student **s)
{ 
    for(int i = 0; i < n-1; i++)
    { 
        int k = i;
        Student* Max_Student = s[i];
        for(int j = i+1; j < n; j++)
        {
            int x = strcmp(s[j]->name, Max_Student->name);
            if(x < 0 || x == 0 && result(*s[j]) > result(*Max_Student))
            {
                k = j;
                Max_Student = s[j];
            }
        }
        Student* x;
        x = s[i]; s[i] = s[k]; s[k] = x;
    }
}



// г)
// извеждане на сортираните в низходящ ред по среден
// успех данни за студентите от групата
void print_sort_group(int n, Student **s)
{
    // извеждане на заглавието на таблицата
    print_table();
    // извеждане на сортираните данни
    for(int i = 0; i < n; i++)
    {
        print_student(*s[i]);
        double res = result(*s[i]);
        cout << setw(6) << res << endl;
    }
}

int main()
{
    // въвеждане на броя на учебните дисциплини
    do
    { 
        cout << "Въведете стойност за k от 1 до " 
             << SIZE_MAX1 << ": ";
        cin >> k;
    } while (k < 1 || k > SIZE_MAX1);
    // въвеждане на броя на студентите на групата
    int n;
    do
    { 
        cout << "Въведете стойност за n от 1 до "
             << SIZE_MAX2 << ": ";
        cin >> n;
    } while (n < 1 || n > SIZE_MAX2);

    Student s[SIZE_MAX2];   // ще съдържа данни за студентите
    Student* ps[SIZE_MAX2]; // ще съдържа указатели към елементите на масива s

    // създаване на масива s, съдържащ информация
    // за студентите от дадена група
    create_group(n, s);

    // извеждане на информацията за студентите от групата
    print_group(n, s);

    // инициализиране на елементите на масива от указатели
    for(int i = 0; i < n; i++)
        ps[i] = &s[i];

    // сортиране на информацията за студентите от групата
    sortgroup(n, ps);
    cout << endl;

    // извеждане на сортираната информация за студентите
    print_sort_group(n, ps);
    return 0;
}
