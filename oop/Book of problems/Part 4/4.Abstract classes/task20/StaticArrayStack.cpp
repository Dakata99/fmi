#pragma once
#include "ArrayStack.cpp"

class StaticArrayStack:public ArrayStack
{
private:
    int staticArr[10];
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
        return staticArr;
    }
public:
    StaticArrayStack():ArrayStack(){}
};
