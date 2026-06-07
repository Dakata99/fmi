#include <iostream>

template <class T>
class Array
{
private:
    size_t size;
    T* arr;
public:
    Array():size(0), arr(nullptr){}
    Array(const size_t _size)
    {
        size = _size;
        arr = new T[size];
    }
    Array(const Array& array)
    {
        size = array.getSize();
        arr = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = array.arr[i];
        }
    }

    ~Array()
    {
        delete[]arr;
    }
    
    //getters
    size_t getSize()const
    {
        return size;
    }
    T* getArr()const
    {
        return arr;
    }
    
    //setters
    void initArr()
    {
        for (size_t i = 0; i < size; i++)
        {
            T x;
            std::cin >> x;
            arr[i] = x;
        }
    }
    //print
    void print()const
    {
        std::cout << "[ ";
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

};

void func()
{
    Array<int> arr1(5);
    arr1.initArr();
    arr1.print();

    Array<double> arr2(3);
    arr2.initArr();
    arr2.print();
}

int main()
{
    func();

    return 0;
}