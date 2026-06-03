#include <iostream.h>
#include <stdlib.h>

const int MAXSIZE = 100; // максимален брой елементи на масива

template <class T>
class Array
{
public:
    Array(int);
    ~Array();
    Array(const Array&);
    Array& operator=(const Array&);
    int get_size() const;
    T& operator[](int);

private:
    T* arr;                  // указател към масива
    int size;                // брой на елементите
};

// конструктор
template <class T>
Array<T>::Array(int n)
{
    if(n > MAXSIZE)
				{ 
				    cout << n << " надхвърля " << MAXSIZE
             << ".\n";
        exit(1);
				}
    if(n <= 0)
				{ 
				    cout << "Некоректна размерност!\n";
        exit(1);
				}
    
		  size = n;
    arr = new T[n];
    if(!arr)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
   
}

// деструктор
template <class T>
Array<T>::~Array()
{
    delete [] arr;
}

// конструктор за присвояване
template <class T>
Array<T>::Array(const Array<T>& p)
{ 
    size = p.size;
    arr = new T[size];
    if(!arr)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    for(int i = 0; i < size; i++)
        arr[i] = p.arr[i];
}

// оператор за присвояване
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& p)
{ 
    if(this != &p)
    { 
        delete [] arr;
        size = p.size;
        arr = new T[size];
        if(!arr)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        for(int i = 0; i < size; i++)
            arr[i] = p.arr[i];
    }
    return *this;
}

// оператор за индексиране
template <class T>
T& Array<T>::operator[](int sub)
{ 
    if(sub < 0 || sub >= size)
    { 
        cout << "Грешка: Индексът е извън границите!\n";
        exit(1);
    }
    return arr[sub];
}

// намира броя на елементите на масив
template <class T>
int Array<T>::get_size() const
{ 
    return size;
}

int main()
{ 
    int n, i;
    cout << "n= "; cin >> n;
    
    // дефиниция на едномерен масив от цели числа
    Array<int> a(n);
    for(i = 0; i < n; i++)
        a[i] = i+1;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        a[i] = a[i]+5;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        a[i]--;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // дефиниция на едномерен масив от символи
    Array<char> c(n);
    for(i = 0; i < n; i++)
        c[i] = (char)(i+65);
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        c[i] = (char)(c[i]+5);
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        c[i]--;
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}
