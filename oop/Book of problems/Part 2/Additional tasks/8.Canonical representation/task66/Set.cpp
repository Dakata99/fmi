#include "Set.h"

Set::Set::Set()
{
    current = 0, max = 1;
    data = new int[max];
}
Set::Set(const size_t num)
{
    current = 0, max = num;
    data = new int[max];
}
Set::Set(const Set& other)
{
    current = other.current;
    max = other.max;
    data = new int[max];
    for (size_t i = 0; i < current; i++)
    {
        data[i] = other.data[i];
    }
}
Set::~Set()
{
    delete[]data;
}

Set& Set::operator=(const Set& other)
{
    if (this != &other)
    {
        delete[]data;
        current = other.current, max = other.max;
        data = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Set Set::operator+(const Set& other)
{
    return this->merge(other);
}
Set Set::operator+(const int element)
{
    this->add(element);
    return *this;
}
Set Set::operator-(const Set& other)
{
    return this->difference(other);
}
Set Set::operator-(const int element)
{
    this->remove(element);
    return *this;
}
Set Set::operator*(const Set& other)
{
    return this->cut(other);
}
Set Set::operator^(const Set& other)
{
    return this->symetricDiff(other);
}
bool Set::operator()(const int element)
{
    return isInSet(element);
}
bool Set::operator==(const Set& other)
{
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < other.current; j++)
        {
            if (!isInSet(other.data[j]) || !other.isInSet(data[i]))
            {
                return false;
            }
        }
    }
    return true;
}
bool Set::operator!=(const Set& other)
{
    return ~(*this == other);
}
bool Set::operator>(const Set& other)
{
    if (current <= other.current)
    {
        return false;
    }
    Set temp = other;
    for (size_t i = 0; i < temp.current; i++)
    {
        if (isInSet(temp.data[i]))
        {
            temp.remove(data[i]);
        }
    }
    if (temp.current <= 0)
        return false;
    else 
        return true;
}
bool Set::operator<(const Set& other)
{
    return !(*this > other);
}
Set Set::operator~()
{
    return Set();
}

bool Set::isInSet(const int _data)const
{
    for (size_t i = 0; i < current; i++)
    {
        if (data[i] == _data)
        {
            return true;
        }
    }
        return false;
}

void Set::add(const int _data)
{
    if (isInSet(_data))
    {
        //std::cout << "Element is already in the set!\n";
        return;
    }
    
    if (current + 1 >= max)
    {
        max++;
        int* temp = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = data[i];
        }
        delete[]data;
        data = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            data[i] = temp[i];
        }
        delete[]temp;
    }
    data[current++] = _data;
}
void Set::remove(const int _data)
{
    if (!isInSet(_data))
    {
        std::cout << "Element is not in the set - you cant remove it again!\n";
        return;
    }
    current--;
    int* temp = new int[current];
    int index;
    for (size_t i = 0; i < current + 1; i++)
    {
        if (data[i] == _data)
        {
            index = i;
        }
    }
    for (size_t i = 0; i < index; i++)
    {
        temp[i] = data[i];
    }
    for (size_t i = index; i < current; i++)
    {
        temp[i] = data[i + 1];
    }
    
    delete[]data;
    data = new int[current];
    for (size_t i = 0; i < current; i++)
    {
        data[i] = temp[i];
    }
    delete[]temp;
}
    
size_t Set::size()const
{
    return current;
}  
    
Set Set::cut(const Set& other)
{
    Set temp;
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < other.current; j++)
        {
            if (!temp.isInSet(data[i]) && data[i] == other.data[j])
            {
                temp.add(data[i]);
            }
        }
    }
    
    return temp;
}
Set Set::merge(const Set& other)
{
    Set temp;
    for (size_t i = 0; i < other.current; i++)
    {
        temp.add(other.data[i]);
    }
    for (size_t i = 0; i < current; i++)
    {
        temp.add(data[i]);
    } 

    return temp;      
}
Set Set::difference(const Set& other)
{
    Set temp = this->merge(other);
    for (size_t i = 0; i < other.current; i++)
    {
        temp.remove(other.data[i]);
    }
    return temp;
}
Set Set::symetricDiff(const Set& other)
{ 
    Set temp = this->difference(other), temp2 = other;
    temp2 = temp2.difference(*this);

    return temp.merge(temp2);    
}

void Set::print()const
{
    for (size_t i = 0; i < current; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}