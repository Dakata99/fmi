#include <iostream.h>

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
    // помощна функция, връщаща масива, в който
    // се съхранява стекът
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

    // удвоява размера на масива и връща истина при успех
    bool enlarge()
    { 
        int* newArray = new int[capacity*2];
        // има ли памет?
        if(newArray == NULL)
            return false;
        // копиране на стария масив в новия
        for(int i = 0; i < capacity; i++)
            newArray[i] = dynamicArray[i];
        // подменяне на dynamicArray и изтриване на стария масив
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

int main()
{ 
    StaticArrayStack staticStack;
    int x;
    // въвеждане на елементи в статичния стек
    cout << "Въведете елементите на стека, -1 за край ";
    do
    cin >> x;
    while(x != -1 && staticStack.push(x));
    // извеждане на елементите на стека
    while(staticStack.pop(x))
        cout << x << endl;
    DynamicArrayStack dynamicStack;
    // въвеждане на елементи в динамичния стек
    cout << "Въведете елементите на стека, -1 за край ";
    do
    cin >> x;
    while(x != -1 && dynamicStack.push(x));
    // извеждане на елементите на стека
    while(dynamicStack.pop(x))
        cout << x << endl;
    return 0;
}
