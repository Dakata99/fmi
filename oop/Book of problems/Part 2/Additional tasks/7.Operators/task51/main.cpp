#include <iostream>

class Box
{
private:
    double width, length, height;
public:
    Box(double w, l, h)
    {
        width = w;
        length = l;
        height = h;
    }
    void operator++()
    {
        ++width;
        ++length;
        ++height;
    }
    void operator++()
    {
        width++;
        length++;
        height++;
    }
};

int main()
{
    return 0;
}