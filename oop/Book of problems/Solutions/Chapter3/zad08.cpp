#include <iostream.h>

class base
{ 
public:
    base();
    base(int n);
    void print() const;

private:
    int x;
};

base::base()
{ 
    cout << "base::base()\n";
    x = 0;
}

base::base(int n)
{ 
    cout << "base::base(" << n << ")\n";
    x = n;
}

void base::print() const
{ 
    cout << "base::x " << x << endl;
}

class der : public base
{ 
public:
    der();
    der(int n);
    void print() const;

private:
    base b;
    int x;
};

der::der()
{ 
    cout << "der::der()\n";
    x = 5;
}

der::der(int n) : base(n)
{ 
    b = base(-n);
    x = n + 5;
    cout << "der::der(" << n << ")\n";
}

void der::print() const
{ 
    base::print();
    cout << "der::x " << x << endl;
    cout << "der::b "; b.print();
}

int main()
{ 
    der d1;
    d1.print();
    der d2(5);
    d2.print();
    return 0;
}
