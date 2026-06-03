#pragma once

class Stack
{
public:
    virtual bool push(int) = 0;
    virtual bool pop(int&) = 0;
    virtual int size() = 0;
    virtual ~Stack(){}
};