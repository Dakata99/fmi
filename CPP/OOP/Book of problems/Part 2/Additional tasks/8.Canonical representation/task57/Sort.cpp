#include "Sort.h"

Sort::Sort()
{
    std::cout << "Enter size of array: "; std::cin >> n;
    a = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        double x;
        std::cin >> x;
        a[i] = x;
    }
}
Sort::~Sort()
{
    delete[]a;
}

void Sort::selectionSort()
{
    size_t min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (size_t i = 0; i < n - 1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (size_t j = i + 1; j < n; j++)  
            if (a[j] < a[min_idx])  
                min_idx = j;  
  
        // Swap the found minimum element with the first element  
        std::swap(a[min_idx], a[i]);  
    }
}
void Sort::bubbleSort()
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i -1; j++)
        {
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
        }
    }
}

void Sort::write()const
{
    std::cout << "[ ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "]";
}