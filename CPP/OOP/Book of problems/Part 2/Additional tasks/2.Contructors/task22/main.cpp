#include <iostream>

class Set
{
private:
    int* data;
    size_t current, max;
public:
    Set()
    {
        current = 0, max = 1;
        data = new int[max];
    }
    Set(const size_t num)
    {
        current = 0, max = num;
        data = new int[max];
    }
    Set(const Set& other)
    {
        current = other.current;
        max = other.max;
        data = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~Set()
    {
        delete[]data;
    }

    Set& operator=(const Set& other)
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

    bool isInSet(const int _data)const
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

    void add(const int _data)
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
    void remove(const int _data)
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
    
    size_t size()const
    {
        return current;
    }
    
    Set cut(const Set& other)
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
    Set merge(const Set& other)
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
    Set difference(const Set& other)
    {
        Set temp = this->merge(other);
        for (size_t i = 0; i < other.current; i++)
        {
            temp.remove(other.data[i]);
        }
        return temp;
    }
    Set symetricDiff(const Set& other)
    { 
        Set temp = this->difference(other), temp2 = other;
        temp2 = temp2.difference(*this);

        return temp.merge(temp2);    
    }

    void print()const
    {
        for (size_t i = 0; i < current; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Set s(3);
    s.add(1);
    //s.print();

    s.add(2);
    //s.print();

    s.add(3);
    //s.print();

    s.add(5);
    //s.print();

    s.add(4);
    //s.print();
    
    s.add(5);
    s.print();

    std::cout << "Size: " << s.size() << std::endl;

    s.print();
    s.remove(3);
    s.print();

    Set s2(5);
    s2.add(6);
    s2.add(2);
    s2.add(1);
    s2.add(4);
    s2.add(9);
    s2.print();

    std::cout << "Cut set of s and s2 is: "; Set ss = s.cut(s2); ss.print();
    std::cout << "Cut set of s2 and s is: "; Set ss2 = s2.cut(s);  ss2.print();

    std::cout << "Merge set of s and s2 is: "; Set s4 = s.merge(s2); s4.print();

    std::cout << "Symmetric difference of s and s2 is: "; Set s5 = s.symetricDiff(s2);s5.print();
    std::cout << "Symmetric difference of s2 and s is: "; Set s6 = s2.symetricDiff(s);s6.print();

    std::cout << "Difference of s and s2 is: "; Set s7 = s.difference(s2);s7.print();
    std::cout << "Differemce of s2 and s is: "; Set s8 = s2.difference(s);s8.print();

    return 0;
}
