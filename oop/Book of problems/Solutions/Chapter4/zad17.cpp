#include <iostream.h>

class Base 
{
public:
    Base()
    {
        cout << "Base\n";
    }

    virtual void f()
    {
        cout << "Base::f()\n";	
        g();	// Свързване а)
        h(); 	// Свързване б)
    }

    virtual void g()
    {
        cout << "Base::g()\n";
    }

    void h()
    {
        cout << "Base::h()\n";
    }

    ~Base()
    { 
        cout << "Base::~Base()\n";
    }
};

class Der1 : public Base 
{
public:
    Der1()
    {
        cout << "Der1\n";
    }

    void g()
    {
        cout << "Der1::g()\n";
    }

    void h()
    {
        cout << "Der1::h()\n";
    }

    virtual ~Der1()
    {
        cout << "Der1::~Der1()\n";
    }
};

class Der2 : public Der1
{
public:
    void f()
    {
        cout << "Der2::f()\n";	
        g();	// Свързване в)
        h();	// Свързване г)
    }

    void h()
    {
        cout << "Der2::h()\n";
    }

    ~Der2()
    {
        cout << "Der2::~Der2()\n";
    }
};

int main()	
{
    Der1 d1; 	             // д)
    Der2 d2;	              // е)
    Base *bp = new Der2;	  // ж)
    Der1 *d1p = new Der2;	 // з)
    bp->f();	              // Свързване и)
                           // й)
    bp->h();	              // Свързване к)
                           // л)
    d1p->f();
                           // Свързване м)
                           // н)
    d1p->h();
                           // Свързване о)
                           // п)
    d1.f();	               // р)
    d1.h();	               // с)
    d2.f();	               // т)
    d2.h();	               // у)
    delete bp;	            // ф)
    delete d1p;	           // х)
				return 0;														// ц)
} 	                        
