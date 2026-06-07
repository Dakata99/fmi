#include <iostream>

class Stack
{
private:
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
    ~Stack()
    {
        delete[]stack;
    }
};

void func()
{
    Stack s(5);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    /*
    std::cout << s.printTop() << std::endl;
    s.pop();
    std::cout << s.printTop() << std::endl;
    s.pop();
    std::cout << s.printTop() << std::endl;
    s.pop();
    std::cout << s.printTop() << std::endl;
    s.pop();
    std::cout << s.printTop() << std::endl;
    s.pop();
    //std::cout << s.printTop() << std::endl;
    //s.push('1');
    */

    s.printStack();
}

int main()
{
    func();

    return 0;
}