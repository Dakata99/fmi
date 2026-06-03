#pragma once

class Sort
{
private:
    int n;
    double* a;
public:
    Sort();
    ~Sort();

    void selectionSort();
    void bubbleSort();

    void write()const;
};
