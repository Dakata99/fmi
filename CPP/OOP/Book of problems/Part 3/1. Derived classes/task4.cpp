#include <iostream>

class first
{
private:
    int f1;
protected:
    int f2;
public:
    void first_read(int x, int y)
    {
        f1 = x;
        f2 = y;
    }
    void first_print()const
    {
        std::cout << f1 << std::endl << f2 << std::endl;
    }
    friend void first_friend(first& f, int x, int y)
    {
        f.f1 = x + y;
        f.f2 = x - y;
    }
};

class second:first
{
private:
    int s1;
protected:
    int s2;
public:
    friend void second_friend(second& s, first f, int x, int y)
    {
        std::cout << "friend function" << std::endl;
        first_friend(f, x, y);
        s.s1 = f.f1 + x;
        s.s2 = f.f2 - x;
        s.f1 = x + y;
        s.f2 = f.f2 + f.f1;
        std::cout << "s.first_print" << std::endl;
        s.first_print();
        std::cout << "s.second_print" << std::endl;
        s.second_print();
    }
    void read_second(int x, int y, int z, int t)
    {
        first_read(x,y);
        s1 = z;
        s2 = t;
    }
    void second_print()const
    {
        std::cout << "first_print():\n";first_print();
        std::cout << s1 << std::endl << s2 << std::endl;
    }
};

void func()
{
    first f;
    f.first_read(2, 4);
    f.first_print();
    first_friend(f, 1, 3);
    f.first_print();

    second s;
    s.read_second(6, 8, 5, 7);
    s.second_print();
    second_friend(s, f, 8, 9);
    
    f.first_print();
    s.first_print();
}

int main()
{
    func();

    return 0;
}