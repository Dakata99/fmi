#include <iostream>

class Check
{
private:
    int a;
    
protected:
    int b, c;
    void set_a(int x) { a = x; }
    
public:
    void set_b(int x) { b = x; }
    void set_c(int x) { c = x; }
};

/* a)
class Quiz : private Check {}; 
a, b, c, set_a, set_b, set_c will be private
*/

/* b)
class Quiz : protected Check s{};
a will be private
b, c, set_a, set_b, set_c will be protected
*/

/* c)
class Quiz : public Check {};
a is private
b, c, set_a will be protected
set_b, set_c - public 
*/

/* d)
class Quiz : Check {};
Answer: private
*/

int main(void)
{

    return 0;
}

