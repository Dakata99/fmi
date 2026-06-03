#include <iostream>

template <class T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
//a
    int a = 1, b = 2;    
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
//b
    double a2 = 1.5, b2 = 2.5;    
    std::cout << "a = " << a2 << " b = " << b2 << std::endl;
    swap(a2, b2);
    std::cout << "a = " << a2 << " b = " << b2 << std::endl;
//c
    char a3 = 'a', b3 = 'H';    
    std::cout << "a = " << a3 << " b = " << b3 << std::endl;
    swap(a3, b3);
    std::cout << "a = " << a3 << " b = " << b3 << std::endl;
//d
    //BankAccount 

    return 0;
}