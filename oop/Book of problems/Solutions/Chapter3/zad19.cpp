#include <iostream.h>
#include <stdlib.h>

// дефиниция на класа DoubleVec
class DoubleVec
{
public:
    // канонично представяне
    DoubleVec(int = 1);
    ~DoubleVec();
    DoubleVec(const DoubleVec&);
    DoubleVec& operator=(const DoubleVec&);
    // предефиниране на оператора за индексиране []
    double& operator[](int);
    // достъп до долната граница на индекса
    int lowerbound() const;
    // достъп до горната граница на индекса
    int upperbound() const;

private:
    double* vector;         // носител на вектор
    int size;               // размерност на вектор
protected:
    int lower;              // долна граница на индекса
    int upper;              // горна граница на индекса
};

DoubleVec::DoubleVec(int s)
{
    if(s <= 0)
    {
        cout << "Невалидна размерност на вектор!\n";
        exit(1);
    }
    lower = 0;
    upper = s-1;
    size = s;
    vector = new double[s];
    if(!vector)
    {
        cout << "Грешка при заделяне на памет!\n";
        exit(1);
    }
}

DoubleVec::~DoubleVec()
{
    delete [] vector;
}

DoubleVec::DoubleVec(const DoubleVec& v)
{
    size = v.size;
    vector = new double[size];
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

DoubleVec& DoubleVec::operator=(const DoubleVec& v)
{
    if(this != &v)
    {
        delete [] vector;
        size = v.size;
        vector = new double[size];
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

double& DoubleVec::operator[](int i)
{
    if(i < 0 || i > upper - lower)
    {
        cout << "Некоректен индекс " << i << endl;
        exit(1);
    }
    return vector[i];
}

int DoubleVec::lowerbound() const
{
    return lower;
}

int DoubleVec::upperbound() const
{
    return upper;
}

// дефиниция на класа DoubleVector
class DoubleVector : public DoubleVec
{
public:
    DoubleVector(int, int);     // конструктор
    double& operator[](int);    // оператор за индексиране
};

// конструктор на вектор с указани
// долна и горна граници на индекса
DoubleVector::DoubleVector(int low, int upp)
    : DoubleVec(upp - low + 1)
{ 
    lower = low;
    upper = upp;
}


// предефиниране на оператора [] за
// индексиране в указаните граници
double& DoubleVector::operator[](int i)
{
    return DoubleVec::operator[](i - lower);
}

int main()
{
    // дефиниране на реален вектор с 4 компоненти
    // и с граници на индекса от 0 до 3
    DoubleVec u(4);
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
    // и с граници на индекса от 26 до 35
    DoubleVector v(26, 35);

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
