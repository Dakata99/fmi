#include <iostream>

class Monotone
{
private:
    int* arr;
    size_t size;
public:
    Monotone(const size_t num)
    {
        size = num;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }
    ~Monotone()
    {
        delete[]arr;
    }
    bool isMonotone()const
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Monotone m(5);
    std::cout << std::boolalpha << m.isMonotone() << std::endl;
    
    return 0;
}
