#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>

const int MaxSide = 100;
int OverflowFlag = -99;                     // глобална променлива

class Matrix
{
public:
    Matrix(int);                             // конструктор
    Matrix::Matrix(const Matrix&);           // конструктор за присвояване
    ~Matrix();                               // деструктор
    Matrix& operator=(const Matrix&);        // оператор за присвояване
    void print() const;                      // извеждане на матрица
    int& operator()(int, int);               // достъп до елемент
private:
    int* array;                              // представяне на матрицата
    int side;                                // размерност на матрицата
};

Matrix::Matrix(int s)
{
    if(s > MaxSide)
    {
        cout << s << " надхвърля "  << MaxSide << ".\n";
        exit(1);
    }

    if(s <= 0)
    { 
        cout << s << " – некоректна размерност\n";
        exit(1);
    }

    array = new int[s * s];
    side = s;
}

Matrix::Matrix(const Matrix& m)
{
    side = m.side;
    array = new int[side * side];
    for(int i = 0; i < side * side; i++)
        array[i] = m.array[i];
}

Matrix::~Matrix()
{
    delete [] array;
}

void Matrix::print() const
{
    Matrix m(side);
    m = *this; 
    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
            cout << setw(8) << m(i, j);
        cout << endl;
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{ 
    if(this != &m)
    { 
        delete [] array;
        side = m.side;
        array = new int[side * side];
        for(int i = 0; i < side * side; i++)
            array[i] = m.array[i];
    }
    return *this;
}

int& Matrix::operator()(int i, int j)
{
    if(i < 0 || j < 0 || i >= side || j >= side)
    { 
        cout << " обръщението ред-колона " << i 
             << "-" << j << " е извън границите.\n";
        return OverflowFlag;
    }
    else
    {
        return array[i * side + j];
    }
}

int main()
{ 
    // създаване на квадратна матрица с размерност 5
    Matrix m(5);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            m(i, j) = i * j + 1;
    // създаване на копие n на квадратната матрица m
    Matrix n(5);
    n = m;
    // извеждане на матрицата n
    n.print();
    return 0;
}
