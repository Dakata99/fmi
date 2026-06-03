#include <iostream.h>
#include <math.h>

const int MAXSIZE = 20;

struct triangle
{ 
private:
    double a, b, c;                // страни на триъгълника

public:
    // създаване на триъгълник по дадени страни
    void create(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }

    // извеждане на триъгълник
    void print() const
    {
        cout << "triangle(" << a << ", " << b << ", "
             << c << ")\n";
    }

    // достъп до страните на триъгълник
    double get_a() const
    {
        return a;
    }
    double get_b() const
    {
        return b;
    }
    double get_c() const
    { 
        return c;
    }

    // намиране на периметъра на триъгълник
    double perimeter() const
    { 
        return a + b + c;
    }

    // намиране на лицето на триъгълник
    double surface() const
    { 
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    // създаване на триъгълник със страни,
    // равни на страните на даден триъгълник,
    // умножени с коефициента k
    triangle mult_k(int k)
    { 
        triangle t;
        t.create(a * k, b * k, c * k);
        return t;
    }
};

// намиране на триъгълника от дадена редица,
// който е с минимално лице
triangle MinSurface(int n, triangle T[])
{ 
    int k = 0;
    double Min = T[0].surface();
    for(int i = 1; i < n; i++)
    {
        if(T[i].surface() < Min)
        { 
            Min = T[i].surface();
            k = i;
        }
    }
    return T[k];
}

// намиране на триъгълника от дадена редица,
// който е с максимален периметър
triangle MaxPerimeter(int n, triangle T[])
{ 
    int k = 0;
    double Max = T[0].perimeter();
    for(int i = 1; i < n; i++)
    {
        if(T[i].perimeter() > Max)
        {
            Max = T[i].perimeter();
            k = i;
        }
    }
    return T[k];
}

// намиране на редица от триъгълници, получена от
// дадена редица, като страните на всеки триъгълник
// са умножени с коефициент, равен на поредния
// номер на триъгълника в редицата
void NewSequence(int n, triangle * T, triangle * NewT)
{  
    for(int i = 0; i < n; i++)
        NewT[i] = T[i].mult_k(i+1);
}

int main()
{ 
    int n;
    do
    { 
        cout << "n= "; cin >> n;
    } while(n < 1 || n > MAXSIZE);
    triangle T[MAXSIZE];

    int i;
    for(i = 0; i < n; i++)
    { 
        double x, y, z;        // страни на триъгълник
        bool tri;
        // въвеждане на стойности на страните на триъгълник
        do
        {
            cout << "x, y, z (страни на триъгълник): ";
            cin >> x >> y >> z;
            tri = (x > 0) && (y > 0) && (z > 0) &&
                  (x+y > z) && (x+z > y) && (y+z > x);
        } while(!tri);
        // създаване на i-я триъгълник
        T[i].create(x, y, z);
    }

    // извеждане на дефинираната редица от триъгълници
    cout << "Редица от триъгълници:\n";
    for(i = 0; i < n; i++)
        T[i].print();

    // намиране и извеждане на триъгълника с най-малко лице
    cout << "Триъгълник с най-малко лице:\n";
    MinSurface(n, T).print();

    // намиране и извеждане на триъгълника с най-голям периметър
    cout << "Триъгълник с най-голям периметър:\n";
    MaxPerimeter(n, T).print();

    // намиране на редица от триъгълници, получена от
    // дадената редица, като страните на всеки триъгълник
    // са умножени с коефициент, равен на поредния
    // номер на триъгълника в редицата
    triangle NT[MAXSIZE];
    cout << "Нова редица от триъгълници:\n";
    NewSequence(n, T, NT);

    // извеждане на получената редица от триъгълници
    for(i = 0; i < n; i++)
        NT[i].print();
    return 0;
}
