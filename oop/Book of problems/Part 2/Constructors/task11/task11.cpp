#include <iostream>

class G
{
private:
    int a, b;
public:
    G(int = 0, int = 0);
    void display()const;
};

G::G(int x, int y)
{
    a = x;
    b = y;
}

void G::display() const
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    G g1, g2(1), g3(1, 2);
    g1.display();
    g2.display();
    g3.display();
    
    return 0;
}