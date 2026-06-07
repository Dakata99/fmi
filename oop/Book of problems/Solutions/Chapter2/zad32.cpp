#include <iostream.h>
#include <stdlib.h>

const int MAX_SIZE = 20;
class IntArray
{
public:
    IntArray(int);             // конструктор с параметър
    ~IntArray();               // деструктор
    IntArray(const IntArray&); // конструктор за присвояване
    bool set(int, int);        // присвоява стойност на елемент
    bool get(int, int&);       // намира стойност на елемент
    int linearSearch(int);     // реализира линейно търсене
    int binarySearch(int);     // реализира двоично търсене
    void selectionSort();      // реализира сортиране по метода
    // "пряка селекция"
    void bubbleSort();         // реализира сортиране по метода
    // на мехурчето

private:
    int* array;                // указател към масива
    int num;                   // брой на елементите
    bool isValid(int);         // проверява валидността на индекса на масива
};

// конструктор
// Всеки елемент на масива е инициализиран с 0.
IntArray::IntArray(int size)
{
    if(size > MAX_SIZE)
				{ 
		      cout << size << " надхвърля " << MAX_SIZE
             << ".\n";
        exit(1);
				}
    if(size <= 0)
				{ 
		      cout << "Некоректна размерност!\n";
        exit(1);
					}
    array = new int[size];
    if(!array)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    num = size;
    for(int i = 0; i < size; i++)
        array[i] = 0;
}

// деструктор
// Освобождава паметта, заета от масива.
IntArray::~IntArray()
{
    delete [] array;
}

// конструктор за присвояване
IntArray::IntArray(const IntArray& p)
{
    array = new int[p.num];
    if(!array)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }

    for(int i = 0; i < p.num; i++)
        array[i] = p.array[i];
    num = p.num;
}

// isValid връща true, ако аргументът й е валиден
// индекс на масива и false - в противен случай.
bool IntArray::isValid(int elem)
{ 
    return elem >= 0 && elem < num;
}

// set присвоява стойност на указан елемент на масива.
// Aко стойността се присвоява на валиден елемент, set
// връща true. В противен случай set връща false.
bool IntArray::set(int elem, int value)
{ 
    if(isValid(elem))
    { 
        array[elem] = value;
        return true;
    }
    return false;
}

// get намира стойността на указан от даден индекс елемент.
// Ако индексът е коректен, get връща true,
// в противен случай връща false.
bool IntArray::get(int elem, int& value)
{ 
    if(isValid(elem))
    { 
        value = array[elem];
        return true;
    }
    return false;
}

// linearSearch реализира метода на последователното търсене.
int IntArray::linearSearch(int x)
{ 
    int i = 0;
    while(i < num-1 && x != array[i])
        i++;
    if(x == array[i]) return i;
    else return num;
}

// binarySearch реализира метода на двоичното търсене
// в сортиран във възходящ ред едномерен масив.
int IntArray::binarySearch(int x)
{ 
    int middle, left = 0, right = num-1;
    if(x < array[left]) return -1;
    if(x == array[left]) return 0;
    if(x > array[right]) return num;

    while(right-left > 1)
    { 
        middle = (left + right)/2;
        if(x <= array[middle]) right = middle; 
        else left = middle;
    }
    return right;
}

// selectionSort реализира метода на пряката
// селекция за сортиране на едномерен масив
void IntArray::selectionSort()
{
    int i, j, k;
    int min;
    for(i = 0; i < num-1; i++)
    {
        k = i; min = array[k];
        for(j = i+1; j < num; j++)
        {
            if(array[j] < min)
            {
                k = j;
                min = array[k];
            }
        }
        array[k] = array[i]; 
        array[i] = min;
    }
}

// bubbleSort реализира метода на мехурчето
// за сортиране на едномерен масив
void IntArray::bubbleSort()
{
    int i, k, right = num-1;
    while(right > 0)
    { 
        k = 0; int swap;
        for(i = 0; i < right; i++)
        {
            if(array[i+1] < array[i])
            {
                swap = array[i];
                array[i] = array[i+1];
                array[i+1] = swap;
                k = i;
            }
        }
        right = k;
    }
}

int main()
{
    // създаване на едномерен масив
    int n;
    cout << "n= "; cin >> n;
    IntArray a(n);

    int val, i;
    for(i = 0; i < n; i++)
    {
        cout << "Елемент? "; cin >> val;
        if(!a.set(i, val))
            cout << "Грешка в инициализацията на елемент на масива!\n";
    }

    cout << endl;
    // извеждане на едномерния масив
    for(i = 0; i < n; i++)
        if(a.get(i, val)) cout << val << " ";
        else cout << "Грешка при намирането на елемент от масива!\n";
    cout << endl;

    // опит да се запомни елемент извън границите на масива
    if(a.set(n, MAX_SIZE+1))
        cout << "Елементът " <<  MAX_SIZE+1
             << " е запомнен в масива успешно.\n";
    else
        cout << "Грешка при запомнене на елемента " << MAX_SIZE+1 << ".\n";

    // търсене на елемент в масива
    cout << "Елемент? "; cin >> val;
    if(a.get(a.linearSearch(val), val))
        cout << val << " се съдържа в масива.";
    else cout << val << " не се съдържа в масива.";

    // сортиране на масива по метода на мехурчето
    a.bubbleSort();
    cout << "Сортиран масив!\n";

    // извеждане на сортирания едномерен масив
    for(i = 0; i < n; i++)
        if(a.get(i, val)) cout << val << " ";
        else cout << "Грешка при получаване на елемент на масива!\n";
    cout << endl;

    // търсене на мястото на даден елемент в сортирания масив
    cout << "Елемент? "; cin >> val;
    cout << "Позицията на " << val << " в масива e: "
         << a.binarySearch(val) << endl;
    return 0;
}
