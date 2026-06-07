#include <iostream>
#include <iomanip>

int k;
const int SIZE = 12;
const size_t SUB_SIZE = 10;
const size_t GROUP_SIZE = 25;

struct Student
{
    size_t facultyNumber;
    char name[SIZE];
    double subjects[SUB_SIZE];
};

void create_student(Student& s)
{
    do
    {
        std::cin >> s.facultyNumber;
    } while (s.facultyNumber <= 0 || s.facultyNumber > 99999);
    
    std::cout << "Last name: "; std::cin >> s.name;
    
    for (size_t i = 0; i < k; i++)
    {
        std::cout << "Grade on " << i + 1 << "-th subject: ";
        std::cin >> s.subjects[i];
    }
}
void print_student(const Student& s)
{
    std::cout << std::setw(5) << s.facultyNumber << std::setw(SIZE + 2) << s.name;
    for (size_t i = 0; i < k; i++)
        std::cout << std::setw(5) << s.subjects[i];
}
double result(const Student& s)
{
    double res = 0;
    for (size_t i = 0; i < k; i++)
        res += s.subjects[i];
    
    res /= k;
    
    return res;
}

//a
void create_group(const size_t n, Student* s)
{
    for (size_t i = 0; i < n; i++)
        create_student(s[i]);
}

//b
void print_table()
{
    std::cout << std::setiosflags(std::ios::fixed|std::ios::showpoint) << std::setprecision(2);
    for (size_t i = 0; i < 5 + SIZE  + 2 + 5*(k + 1) + 1; i++)
        std::cout << "=";
    std::cout << std::endl;
    std::cout << std::setw(5) << "F.N." << std::setw(SIZE + 2) << "Last name";
    for (size_t i = 0; i < k; i++)
        std::cout << std::setw(4) << "Sub" << i + 1;
    std::cout << std::setw(6) << "Average" << std::endl;
    for (size_t i = 0; i < k; i++)
        std::cout << "=";
    std::cout << std::endl;    
}
void print_group(const size_t n, Student s[])
{
    print_table();
    double temp[SUB_SIZE] = {0, };
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            temp[i] += s[i].subjects[i];
        }
        temp[i] = temp[i]/n;
    }
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        print_student(s[i]);
        double res = result(s[i]);
        sum += res;
    }
    
}

void test()
{
    size_t k;
    do
    {
        std::cout << "Enter a value between 1 and 10: ";
        std::cin >> k;
    } while (k < 1 || k > SUB_SIZE);

    size_t n;
    do
    {
        std::cout << "Enter a value between 1 and 25: ";
        std::cin >> n;
    } while (n < 1 || n > GROUP_SIZE);
    
    
    Student s[GROUP_SIZE];
    Student* ps[GROUP_SIZE];

    create_group(n, s);
    print_group(n, s);

    for (size_t i = 0; i < n; i++)
        ps[i] = &s[i];

    sort_group(n, ps);

    print_sort_group(n, ps);
}

int main()
{
   test();

    return 0;
}
