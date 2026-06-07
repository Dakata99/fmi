#include <iostream>

class First
{
private:
    int n;
    double x;

public:
    First(int a = 3)
    {
        n = a;
        x = -5.5;
        std::cout << "First: " << n << ", " << x << std::endl;
    }
    
    First(const First& p)
    {
        n = p.n;
        x = p.x;
        std::cout << "First.n: " << n << std::endl;
        std::cout << "First.x: " << x << std::endl;
    }
    
    First& operator=(const First& p)
    {
        if (this != &p)
        {
            n = p.n + 9;
            x = p.x + 3.5;
            std::cout << "First.n: " << n << std::endl;
            std::cout << "First.x: " << x << std::endl;
        }
        return *this;
    }
};

class Second
{
private:
    int n;
    double x;
    
public:
    Second(double b = 2)
    {
        n = 7;
        x = b;
        std::cout << "Second: " << n << ", " << x << std::endl;
    }
};

class Third
{
private:
    int n;
    double x;
    
public:
    Third(double b = 1)
    {
        n = 3;
        x = b;
        std::cout << "Third: " << n << ", " << x << std::endl;
    }
    Third(const Third& p)
    {
        n = p.n + 6;
        x = p.x + 1.5;
        std::cout << "Third.n: " << n << std::endl;
        std::cout << "Third.x: " << x << std::endl;
    }
};

class Fourth : public Second, First, protected Third
{
private:
    int n, m;
    
public:
    Fourth(int x = 3, int y = 1, int z = 2) : First(x), Second(y), Third(z)
    {
        n = z;
        m = x - y;
        std::cout << "Fourth: " << n << ", " << m << std::endl;
    }
    
    Fourth& operator=(const Fourth& p)
    {
        if (this != &p)
        {
            First::operator=(p);
            n = p.n;
            m = p.m;
        }
        return *this;
    }
};

int main()
{
    Fourth x, y(3, 7, 2), z;
    //Fourth t = x;
    //z = y;
    
    /*
    For obj-x:
    	Second: 7, 1
    	First: 3, -5.5
    	Third: 3, 2
    	Fourth: 2, 2
    	
    For obj-y:
    	Second: 7, 7
    	First: 3, -5.5
    	Third: 3, 2
    	Fourth: 2, -4
    	
    For obj-z:
    	Second: 7, 1
    	First: 3, -5.5
    	Third: 3, 2
    	Fourth: 2, 2
    	
    */

    return 0;
}
