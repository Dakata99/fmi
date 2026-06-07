#include <iostream.h>
#include <stdlib.h>

// дефиниция на шаблона на класа TVec
template <class T>
class TVec
{
public:
    // канонично представяне
    TVec(int = 1);
    ~TVec();
    TVec(const TVec&);
    TVec& operator=(const TVec&);
    // оператор за индексиране
    T& operator[](int);
    // достъп до долната граница на индекса
    int lowerbound() const;
    // достъп до горната граница на индекса
    int upperbound() const;
private:
    T* vector;          // носител на вектор
    int size;           // размерност на вектор
protected:
    int lower;          // долна граница на индекса
    int upper;          // горна граница на индекса
};

template <class T>
TVec<T>::TVec(int s)
{
    if(s <= 0)
    { 
        cout << "Невалидна размерност на вектор!\n";
        exit(1);
    }
    lower = 0;
    upper = s-1;
    size = s;
    vector = new T[s];
    if(!vector)
    { 
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
}

template <class T>
TVec<T>::~TVec()
{
    delete [] vector;
}

template <class T>
TVec<T>::TVec(const TVec<T>& v)
{
    size = v.size;
    vector = new T[size];
    if(!vector)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
    for(int i = 0; i < size; i++)
        vector[i] = v.vector[i];
    lower = v.lower;
    upper = v.upper;
}

template <class T>
TVec<T>& TVec<T>::operator=(const TVec<T>& v)
{
    if(this != &v)
    {
        delete [] vector;
        size = v.size;
        vector = new T[size];
        if(!vector)
        { 
            cout << "Грешка при заделяне на памет!\n";
            exit(1);
        }
        for(int i = 0; i < size; i++)
            vector[i] = v.vector[i];
        lower = v.lower;
        upper = v.upper;
    }
    return *this;
}

template <class T>
T& TVec<T>::operator[](int i)
{
    if(i < 0 || i > upper - lower)
    {
        cout << "Некоректен индекс " << i << endl;
        exit(1);
    }
    return vector[i];
}

template <class T>
int TVec<T>::lowerbound() const
{
    return lower;
}

template <class T>
int TVec<T>::upperbound() const
{
    return upper;
}

// дефиниция на класа TVector
template <class T>
class TVector : public TVec<T>
{
public:
    TVector(int, int);      // конструктор
    T& operator[](int);     // оператор за индексиране
};

// конструктор на вектор с указани
// долна и горна граници на индекса
template <class T>
TVector<T>::TVector(int low, int upp) : TVec<T>(upp - low + 1)
{ 
    lower = low;
    upper = upp;
}


// предефиниране на оператора [] за
// индексиране в указаните граници
template <class T>
T& TVector<T>::operator[](int i)
{
    return TVec<T>::operator[](i - lower); //  TVec<T>::lower при някой компилатори
}

int main()
{
    // дефиниране на вектор с 4 целочислени компоненти
    // и с граници на индекса от 0 до 3
    TVec<int> u(4);
    // въвеждане на стойности на компонентите на вектора u
    int i;
    for(i = u.lowerbound(); i <= u.upperbound(); i++)
    {
        cout << "> "; cin >> u[i];
    }

    // извеждане на вектора u
    for(i = u.lowerbound(); i <= u.upperbound(); i++)
        cout << u[i] << " ";
    cout << endl;

    // дефиниране на реален вектор с 10 компоненти
    // и с граници на индекса от -4 до 5
    TVector<double> v(-4, 5);
    // въвеждане на стойности на компонентите на вектора v
    for(i = v.lowerbound(); i <= v.upperbound(); i++)
    {
        cout << "> "; cin >> v[i];
    }

    // извеждане на вектора v
    for(i = v.lowerbound(); i <= v.upperbound(); i++)
        cout << v[i] << " ";
    return 0;
}
