#pragma once
#include "ArrayStack.cpp"

class DynArrayStack:public ArrayStack
{
private:
    int capacity;
    int* dynArr;
    bool enlarge()
    {
        int* temp = new int[capacity*2];
        if (temp == NULL)
        {
            return false;
        }
        for (size_t i = 0; i < capacity; i++)
        {
            temp[i] = dynArr[i];
        }
        int* save = dynArr;
        dynArr = temp;
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
        return dynArr;
    }
};