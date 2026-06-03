#include "Sorted.h"

void Sorted::sort()
{
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < current; j++)
        {
            if (arr[i] < arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}
Sorted::Sorted(const size_t num)
{
    current = 0;
    max = num;
    arr = new int[max];
}
Sorted::Sorted(const Sorted& other)
{
    current = other.current;
    max = other.max;
    arr = new int[max];
    for (size_t i = 0; i < current; i++)
    {
        arr[i] = other.arr[i];
    }
}
Sorted::~Sorted()
{
    delete[]arr;
}

Sorted& Sorted::operator=(const Sorted& other)
{
    if (this != &other)
    {
        current = other.current;
        max = other.max;
        arr = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

size_t Sorted::size()const
{
    return current;
}
int Sorted::operator[](const size_t index)
{
    if (index > current - 1)
    {
        return -1;
    }
    
    return arr[index];
}

bool Sorted::member(const int data)const
{
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            return true;
        }
    }
    return false;
}
size_t Sorted::getTimes(const int data)const
{
    size_t counter = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            counter++;
        }
    }
    return counter;
}
void Sorted::remove(const int data)
{
    if (current == -1)
    {
        return;
    }
    else if (!this->member(data))
    {
        return;
    }

    Sorted temp;
    size_t index;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            index = i;
        }
    }
    current--;
    for (size_t i = 0; i < index; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = index; i < current + 1; i++)
    {
        temp.add(arr[i + 1]);
    }

    *this = temp;
}
void Sorted::add(const int data)
{
    if (current + 1 >= max)
    {
        max++;
        int* temp = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            arr[i] = temp[i];
        }
        delete[]temp;
    }
    arr[current++] = data;
}
void Sorted::addBefore(const int data, const size_t index)
{
    if (index > current)
    {
        std::cout << "You cannot add an element there!\n";
        return;
    }
  
    Sorted temp(current);
    for (size_t i = 0; i < index; i++)
    {
        //std::cout << arr[i] << "error1\n";
        temp.add(arr[i]);
    }
    temp.add(data);
    for (size_t i = index + 1, j = i - 1; i < current + 1; i++, j++)
    {
        //td::cout << arr[i - index] << "error2\n";
        temp.add(arr[j]);
    }
    *this = temp;   
}
void Sorted::addAfter(const int data, const size_t index)
{
    if (index > current)
    {
        return;
    }
    Sorted temp(current);
    for (size_t i = 0; i <= index; i++)
    {
        temp.add(arr[i]);
    }
    temp.add(data);
    for (size_t i = index + 2, j = index + 1; i < current + 1; i++, j++)
    {
        temp.add(arr[j]);
    }

    *this = temp;
}
void Sorted::remove(const size_t index)
{
    Sorted temp(current - 1);
    for (size_t i = 0; i < index; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = index + 1; i < current; i++)
    {
        temp.add(arr[i]);
    }
    
    *this = temp;
}

Sorted Sorted::intersection(const Sorted& other)
{
    Sorted temp(1);
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < other.current; j++)
        {
            if (!temp.member(arr[i]))
            {
                size_t count1 = getTimes(arr[i]), count2 = other.getTimes(arr[i]);
                if (count1 >= count2)
                {
                    while (count2 > 0)
                    {
                        temp.add(arr[i]);
                        count2--;
                    }
                }
                else
                {
                    while (count1 > 0)
                    {
                        temp.add(arr[i]);
                        count1--;
                    }
                }
            }
        }
    }
    temp.sort();

    return temp;
}
Sorted Sorted::merge(const Sorted& other)
{
    Sorted temp(current + other.current);
    for (size_t i = 0; i < current; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = 0; i < other.current; i++)
    {
        temp.add(other.arr[i]);
    }
    temp.sort();
    
    return temp;
}
Sorted Sorted::difference(const Sorted& other)
{
    Sorted temp = this->intersection(other);
    Sorted temp2 = *this;
    for (size_t i = 0; i < temp.size(); i++)
    {
        temp2.remove(temp.arr[i]);
        temp2.current--;
    }
    temp2.sort();
    return temp2;
}

void Sorted::print()
{
    sort();
    std::cout << "Sorted-------\n";
    for (size_t i = 0; i < current; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n--------------\n";
}