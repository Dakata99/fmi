#include <iostream.h>

class First
{
public:
    First(int a = 3)
    {
        n = a;
        x = -5.5;
        cout << "First: " << n << ", " << x << endl;
    }

    First(const First& p)
    {
        n = p.n;
        x = p.x;
        cout << "First.n: " << n << endl 
             << "First.x: " << x << endl;
    }

    First& operator=(const First & p)
    {
        if(this!=&p)
        {
            n = p.n + 9;
            x = p.x + 3.5;
            cout << "First.n: " << n << endl 
                 << "First.x: " << x << endl;
        }
        return *this;
    }

private:
    int n;
    double x;
};

class Second
{
public:
    Second(double b = 2)
    {
        n = 7;
        x = b;
        cout << "Second: " << n << ", " << x << endl;
    }

private:
    int n;
    double x;
};

class Third
{
public:
    Third(double b = 1)
    {
        n = 3; 
        x = b;
        cout << "Third: " << n << ", " << x << endl;
    }

    Third(const Third& p)
    {
        n = p.n + 6;
        x = p.x + 1.5;
        cout << "Third.n: " << n << endl
             << "Third.x: " << x << endl;
    }

private:
    int n;
    double x;
};

class Fourth : public Second, First, protected Third
{
public:
    Fourth(int x = 3, int y = 1, int z = 2) : 
                First(x), Second(y), Third(z)
    {
        n = z;
        m = x-y;
        cout << "Fourth: " << n << ", " << m << endl;
    }

    Fourth& operator=(const Fourth& p)
    {
        if(this != &p)
        {
            First::operator=(p);
            n = p.n;
            m = p.m;
        }
        return *this;
    }
private:
    int n, m;
};

int main()
{
    Fourth x, y(3, 7, 2), z;
    Fourth t = x;
    z = y;
    return 0;
}
