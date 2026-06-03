#include <iostream.h>

class B
{
public:
    B()
    {}

    virtual void p() const
    {
        cout << "B::p\n";
    }

    virtual void q() const
    { 
        cout << "B::q\n";
    }
};

class D : public B
{
public:
    D(){}

    void p() const
    {
        cout << "D::p\n";
    }

    void q() const
    { 
        cout << "D::q\n";
    }
};

int main()
{
    B b; D d;
    B* pb = new B;
    B* pd = new D;
    D* pd2 = new D;
    b.p(); b.q();
    d.p(); d.q();
    pb->p(); pb->q();
    pd->p(); pd->q();
    pd2->p();pd2->q();
    delete pb;
    delete pd;
    delete pd2;
    return 0;
}
