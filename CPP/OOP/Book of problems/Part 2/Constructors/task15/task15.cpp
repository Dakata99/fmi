#include <iostream>

class Differ
{
private:
    unsigned int n;
    int* arr;
public:
    Differ():arr(nullptr), n(0){}
    Differ(int _n):n(_n)
    {
        arr = new int[n];
    }
    void init()
    {
        for (size_t i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            arr[i] = x;
        }
    }
    void display()const
    {
        for (size_t i = 0; i < n; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }
    bool checkReps() const
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    return false;
                }                
            }
        }
        return true;
    }
    
    ~Differ()
    {
        delete[]arr;
    }
};

void func()
{
    unsigned int n;
    do
    {
        std::cout << "Enter n = "; std::cin >> n;
    } while (n <= 0);
    
    Differ d(n);
    d.init();
    d.display();
    std::cout << "Repeated: " << std::boolalpha << d.checkReps() << std::endl;
}

int main()
{
    func();
    
    return 0;
}