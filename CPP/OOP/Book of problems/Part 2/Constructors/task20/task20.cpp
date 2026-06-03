#include <iostream>
#include <cstring>  

const int MAX_STACK = 100;
const int FULL_STACK = MAX_STACK;
const int EMPTY_STACK = -1;

class Stack
{
private:
    char* sym;
    unsigned int top;
public:
    Stack()
    {
        top = EMPTY_STACK;
        this->sym = nullptr;
    }
    void push(char sym)
    {
        if (fullStack())
        {
            std::cout << "Stack is full!" << std::endl;
            return;
        }
        else
        {
            top++;
            this->sym[top] = sym;
        }
    }
    void pop()
    {
        if (emptyStack())
        {
            std::cout << "Stack is empty!" << std::endl;
        }
        else
        {
            top--;
        }
    }
    bool fullStack()const
    {
        return top == FULL_STACK;
    }
    bool emptyStack()const
    {
        return top == EMPTY_STACK;
    }
    char printTop()const
    {
        return this->sym[top];
    }
};

void func()
{
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    //std::cout << s.printTop();
    
}

int main()
{
    func();

    return 0;
}