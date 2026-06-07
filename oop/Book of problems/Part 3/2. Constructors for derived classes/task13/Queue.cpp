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
    bool empty()const
    {
        return top == 0;
    }
    char printTop()const
    {
        return stack[top];
    }
    int getTop()const
    {
        return top;
    }
    ~Stack()
    {
        delete[]stack;
    }
};

class Queue:private Stack
{
public:
    Queue(){}
    void add(const char& sym)
    {
        Stack s;
        while (!empty())
        {
            s.push(pop());
        }
        push(sym);
        while (!s.getTop() != 0)
        {
            push(s.pop());
        }
    }
    void remove()
    {
        pop();
    }
    char front()
    {
        char h = pop();
        push(h);
        return h; 
    }
    bool empty()const
    {
        return Stack::empty();
    }
    int lenght()const
    {
        Stack s = *this;
        size_t n = 0;
        while (s.pop())
        {
            n++;
        }
        return n;
    }
    void print()const
    {
        Stack::print();
    }
};

void func()
{
    Queue q1;
    while ()
    {
        char ch;
        std::cin >> ch;
        if (ch == '#')
        {
            break;
        }
        q1.push(ch);
    }
    Queue q2 = q1;
    q1.print();

    while (!q2.empty())
    {
        std::cout << q2.front() << std::endl;
        q2.remove();
    }
}

int main()
{
    func();

    return 0;
}