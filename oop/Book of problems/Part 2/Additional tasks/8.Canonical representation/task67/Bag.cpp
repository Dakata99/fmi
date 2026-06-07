#include "Bag.h"

//des/constructors
Bag::Bag(const size_t num)
{
    current = 0, max = num;
    arr = new int[max];
}
Bag::Bag(const Bag& other)
{
    current = other.current;
    max = other.max;
    arr = new int[max];
    for (size_t i = 0; i < current; i++)
    {
        arr[i] = other.arr[i];
    }
}
Bag::~Bag()
{
    delete[]arr;
}

//operators
Bag& Bag::operator=(const Bag& other)
{
    if (this != &other)
    {
        delete[]arr;
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

//getters
size_t Bag::size()const
{
    return current;
}

//setters

//funcs
bool Bag::isInBag(const int data)const
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
size_t Bag::getTimes(const int data)const
{
    int counter = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            counter++;
        }
    }
    return counter;
}
void Bag::add(const int data)
{
    if (current + 1 >= max)
    {
        max++;
        int* temp = new int[current];
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
void Bag::remove(const int data)
{
    if (isInBag(data))
    {
        int index;
        for (size_t i = 0; i < current; i++)
        {
            if (arr[i] == data)
            {
                index = i;
            }
        }
        current--;
        int* temp = new int[current];
        for (size_t i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        for (size_t i = index; i < current + 1; i++)
        {
            temp[i] = arr[i + 1];
        }

        delete[]arr;
        arr = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            arr[i] = temp[i];
        }
        delete[]temp; 
    }
    else
    {
        //std::cout << "The element is not in the set - you cant temove it again\n";
        return;
    }
}

Bag Bag::cut(const Bag& other)
{
    Bag temp(1);
    for (size_t i = 0; i < current; i++)
    {
        int counter = getTimes(arr[i]), counter2 = other.getTimes(arr[i]);
        for (size_t j = 0; j < other.current; j++)
        {
            if (!temp.isInBag(arr[i])) // && arr[i] == other.arr[j]) -maybe its not needed
            {
                if (counter >= counter2)
                {
                    while (counter2 > 0)
                    {
                        temp.add(arr[i]);
                        counter2--;
                    }
                }
                else
                {
                    while (counter > 0)
                    {
                        temp.add(arr[i]);
                        counter--;
                    }
                }
            }
        }
    }

    return temp;
}
Bag Bag::merge(const Bag& other)
{
    Bag temp(this->current + other.current);
    for (size_t i = 0; i < this->current; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = 0; i < other.current; i++)
    {
        temp.add(other.arr[i]);
    }    
    
    return temp;
}
Bag Bag::diff(Bag& other)
{
    Bag temp = *this, temp2 = this->cut(other);
    for (size_t i = 0; i < temp2.size(); i++)
    {
        temp.remove(temp2.arr[i]);
    }
    
    return temp;;
}
Bag Bag::symDiff(Bag& other)
{
    Bag temp = this->diff(other), temp2 = other.diff(*this);
    
    return temp.merge(temp2);
}
    
void Bag::print()const
    {
        std::cout << "Multiset is: ";
        for (size_t i = 0; i < current; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
