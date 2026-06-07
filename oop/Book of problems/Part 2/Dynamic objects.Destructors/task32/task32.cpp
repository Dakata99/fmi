#include <iostream>
#include <algorithm>

class IntArray
{
private:
    size_t capacity, index;
    int* array;
public:
    IntArray():capacity(0), index(0), array(nullptr){}
    IntArray(const size_t _capacity)
    {
        delete[]array;
        this->capacity = _capacity;
        array = new int[this->capacity];
    }
    IntArray(const size_t _capacity, const int* _array)
    {
        delete[]array;
        this->capacity = _capacity;
        array = new int[this->capacity];
        for (size_t i = 0; i < this->capacity; i++)
        {
            this->array[i] = _array[i];
        }
    }

    //getters
    size_t getSize()const
    {
        return capacity;
    }

    //setters
    void setSize(const size_t size)
    {
        capacity = size;
    }
    
    //funcs
    bool getElement(const size_t elem)
    {
        for (size_t i = 0; i < this->capacity; i++)
        {
            if (array[i] == elem)
            {
                return true;
            }
        }
        return false;
    }
    void sort()
    {
        int i, j;  
        for (i = 0; i < capacity-1; i++)
        {
            for (j = 0; j < capacity-i-1; j++)
            {  
                if (array[j] > array[j+1])  
                    std::swap(array[j], array[j+1]); 
            }
        }       
    }
    void init()
    {
        for (size_t i = 0; i < this->capacity; i++)
        {
            int x;
            std::cin >> x;
            array[i] = x;
        }
    }

    //print
    void print()const
    {
        std::cout << "[";
        for (size_t i = 0; i < capacity; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

};

void func()
{
    IntArray arr(5);
    arr.init();
    arr.print();
    arr.sort();
    arr.print();
}

int main()
{
    func();

    return 0;
}