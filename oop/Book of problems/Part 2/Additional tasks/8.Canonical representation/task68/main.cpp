#include <iostream>
#include "Matrix.cpp"

void func()
{
    double** mat = new double*[3];
    for (size_t i = 0; i < 3; i++)
    {
        mat[i] = new double[3];
    }
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;

    mat[1][0] = 4;
    mat[1][1] = 5;
    mat[1][2] = 6;

    mat[2][0] = 7;
    mat[2][1] = 8;
    mat[2][2] = 9;

    Matrix m1(mat, 3, 3);
    m1.print();

    Matrix m2(mat, 3, 3);
    m2.print();

    Matrix m3 = m1 + m2, m4 = m1 - m2;
    std::cout << "Addition...\n";m3.print();
    std::cout << "Substraction...\n";m4.print();

    Matrix m5 = m1*m2;
    std::cout << "Multiplication...\n";
    m5.print();

    Matrix m6 = m5*2;
    std::cout << "M6*2...\n";m6.print();

    double* arr = m6[2];
    for (size_t i = 0; i < m6.getColumns(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bool flag = m6 == m1;
    std::cout << std::boolalpha << flag << std::endl;

    std::cout << m1(2, 2) << std::endl;
    
    //TODO operator/, (determinant), inverse
    

    for (size_t i = 0; i < 3; i++)
    {
        delete[]mat[i];
    }
    delete[]mat;
}

int main()
{
    func();

    return 0;
}