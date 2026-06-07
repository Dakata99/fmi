#include <iostream.h>
#include <stdlib.h>

class Stack
{
public:
    // включване на елемент в стек
    // Операцията връща истина, ако е била успешна
    // (т.е. ако в стека има място) и лъжа, в
    // противен случай
    virtual bool push(int) = 0;

    // изключване на елемент от стек
    // Операцията връща истина, ако е била успешна
    // (т.е. ако в стека има елементи) и лъжа, в
    // противен случай
    virtual bool pop(int&) = 0;

    // брой елементи в стек
    virtual int size() = 0;
    virtual ~Stack()
    {}
};

class ArrayStack : public Stack
{
public:
    ArrayStack()
    {
        count = 0;
    }

    int size()
    { 
        return count;
    }

    bool push(int x)
    { 
        // има ли свободно място?
        if(!hasSpace())
            return false;
        getArray()[count] = x;
        count++;
        return true;
    }

    bool pop(int &x)
    { 
        if(isEmpty())
            return false;
        x = getArray()[count-1];
        count--;
        return true;
    }

protected:
    // помощна функция, връщаща масива, в който се съхранява стекът
    virtual int* getArray() = 0;

    // функцията указва дали има свободно място
    // в масива, в който се съхранява стекът
    virtual bool hasSpace() = 0;

    // функцията указва дали стек е празен
    virtual bool isEmpty() = 0;

    // брой елементи в стек
    int count;
};

class StaticArrayStack : public ArrayStack
{
public:
    StaticArrayStack() : ArrayStack()
    {}

private:
    int staticArray[10];

protected:
    bool hasSpace()
    {
        return count < 9;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int* getArray()
    {
        return staticArray;
    }
};

class DynamicArrayStack : public ArrayStack
{
public:
    DynamicArrayStack() : ArrayStack()
    {
        dynamicArray = new int[10];
        capacity = 10;
    }

    ~DynamicArrayStack()
    {
        delete dynamicArray;
    }

private:
    // текущ размер на масива
    // Броят на елементите винаги е по-малък
    // или равен на размера на масива
    int capacity;
    int *dynamicArray;

    // удвоява размера на масива и връща
    // истина при успех
    bool enlarge()
    { 
        int* newArray = new int[capacity*2];
        // има ли памет?
        if(newArray == NULL)
            return false;
        // копиране на стария масив в новия
        for(int i = 0; i < capacity; i++)
            newArray[i] = dynamicArray[i];
        // подменяне на dynamicArray и
        // изтриване на стария масив
        int *save = dynamicArray;
        dynamicArray = newArray;
        capacity *= 2;
        delete save;
        return true;
    }

protected:
    bool hasSpace()
    { 
        return count < capacity || enlarge();
    }

    bool isEmpty()
    { 
        return count == 0;
    }

    int* getArray()
    { 
        return dynamicArray;
    }
};

void equalizer(Stack* stacks[], int n)
{	 
    bool equilized = false;
    int i, x;
    for(int current = 0; current < n-1; current++)
    {
        do
        {	
            i = current+1;
            while(i < n && abs(stacks[current]->size() - stacks[i]->size()) <= 1)
                i++;
            if(i < n)
            { 
                if(stacks[current]->size() < stacks[i]->size())
                { 
                    stacks[i]->pop(x);
                    stacks[current]->push(x);
                } 
                else
                { 
                    stacks[current]->pop(x);
                    stacks[i]->push(x);
                }
            }
        } while(i < n);
    }
}

int main()
{
    // създаване на масив, съдържащ 3 стека
    Stack* stacks[3];
    stacks[0] = new StaticArrayStack;
    stacks[1] = new StaticArrayStack;
    stacks[2] = new DynamicArrayStack;
    int i, x;
    for(i = 0; i < 3; i++)
    {
        cout << "Въведете елементите на стек #" << i << ", -1 за край...";
        do
        cin >> x;
        while(x != -1 && stacks[i]->push(x));
    }
    equalizer(stacks, 3);
    for(i = 0; i < 3; i++)
    { 
        cout << "============\n";
        while(stacks[i]->pop(x))
            cout << x << endl;
    }
    return 0;
}
