#include "Stack.h"

class ArrayStack:public Stack
{
protected:
    virtual int* getArray() = 0;
    virtual bool hasSpace() = 0;
    virtual bool isEmpty() = 0;
    int count;
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
        if (!hasSpace())
        {
            return false;
        }
        getArray()[count] = x;
        count++;

        return true;
    }
    bool pop(int& x)
    {
        if (isEmpty())
        {
            return false;
        }
        x = getArray()[count-1];
        count--;
        return true;
    }
};