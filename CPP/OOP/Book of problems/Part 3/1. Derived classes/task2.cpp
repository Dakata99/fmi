#include <iostream>

class base
{
private:
    int b1;
    
protected:
    int b2;
    
public:
    int b3();
} b;

class der1 : public base
{
private:
}

class der2 : private base {};
class der3 : protected base {};

class der11 : public der1 {};
class der21 : protected der2 {};
class der31 : private der3 {};

class der12 : protected der11 {};
class der22 : private der21 {};
class der32 : public der31 {};

int main(void)
{
	return 0;
}
