#include <iostream>
#include <iomanip>

int err = -1;

class Matrix
{
private:
    size_t n;
    int* mat;
public:
    Matrix():n(1), mat(nullptr){}
    Matrix(const size_t size)
    {
        if(size <= 0)
        {
            std::cout << "Invalid size..., setting size to 2!" << std::endl; n = 2;
        }
        else
        {
            n = size;
        }
        mat = new int[n*n];
    }
    Matrix(const Matrix& other)
    {
        n = other.getSize();
        
        delete[]mat;
        mat = new int[n*n];

        for (size_t i = 0; i < n*n; i++)
        {
            mat[i] = other.mat[i];
        }
    }
    ~Matrix()
    {
        delete[]mat;
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            delete[]mat;
            n = other.getSize();
            mat = new int[n*n];

            for (size_t i = 0; i < n*n; i++)
                mat[i] = other.mat[i];
        }
        return *this;
    }

    int& operator()(int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            std::cout << "Error!" << std::endl; return err;
        }
        else
        {
            return mat[i*n + j];
        }
    }

    size_t getSize()const
    {
        return n;
    }

    void print()const
    {
        Matrix m(n);
        m = *this;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout << std::setw(8) <<  m(i, j);
            }
            std::cout << std::endl;
        }
    }
};

void func()
{
    Matrix mat1(5);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            mat1(i, j) = i*j + 1;
        }
    }

    Matrix mat2(5);
    mat2 = mat1;

    mat2.print();
}

int main()
{
    func();

    return 0;
}