#pragma once

class Container
{
protected:
    int* data;
    size_t size, capacity;
public:
    Container();
    ~Container();

    virtual void add(const int) = 0;
    virtual void remove(const int) = 0;
    virtual bool member(const int) = 0;
};
