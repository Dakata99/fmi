#include <iostream>

class StackIter;

class Stack
{
private:
    friend StackIter;
    int top, capacity;
    char* stack;
public:
    Stack():top(-1), capacity(0), stack(nullptr){}
    Stack(const int size)
    {
        top = 0;
        capacity = size;
        stack = new char[capacity];
    }
    void push(char sym)
    {
        std::cout << "Push" << std::endl;
        if (top >= capacity - 1)
        {
            capacity++;
            char* temp = new char[capacity];
            for (size_t i = 0; i < capacity; i++)
            {
                temp[i] = stack[i];
            }
            
            delete[]stack;
            stack = new char[capacity];
            for (size_t i = 0; i < capacity; i++)
            {
                stack[i] = temp[i];
            }
            delete[]temp;
        }
        top++;
        stack[top] = sym;
    }
    void pop()
    {
        if (top == 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        top--;
        capacity--;
        char* temp = new char[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            temp[i] = stack[i];
        }

        delete[]stack;
        stack = new char[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            stack[i] = temp[i];
        }
        
        delete[]temp;
    }
    char printTop()const
    {
        return stack[top];
    }
    void print()const
    {
        for (size_t i = top; i>= 0; i--)
            std::cout << stack[i] << std::endl;
            //pop();
    }
    ~Stack()
    {
        delete[]stack;
    }
};

class StackIter
{
private:
    Stack* st;
public:
    StackIter():st(nullptr){}
    StackIter(Stack& s)
    {
        st = &s;
    }
    char* getNext()
    {
        if (st->top == 0)
            return 0;

        return &st->stack[st->top--];
    }
};

void func()
{
    Stack s(5);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    Stack t = s;
    s.print();

    StackIter si(t);
    char* ptr = NULL;

    while (ptr = si.getNext())
        std::cout << *ptr << std::endl;
}

int main()
{
    func();

    return 0;
}