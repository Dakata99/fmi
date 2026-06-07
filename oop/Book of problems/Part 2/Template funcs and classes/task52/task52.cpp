#include <iostream>

template <class T>
class Stack
{
private:
    int top, capacity;
    T* stack;
public:
    Stack():top(-1), capacity(0), stack(nullptr){}
    Stack(const int size)
    {
        top = 0;
        capacity = size;
        stack = new T[capacity];
    }
    void push(T sym)
    {
        //std::cout << "Push" << std::endl;
        if (top >= capacity - 1)
        {
            capacity++;
            T* temp = new T[capacity];
            for (size_t i = 0; i < capacity; i++)
            {
                temp[i] = stack[i];
            }
            
            delete[]stack;
            stack = new T[capacity];
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
        T* temp = new T[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            temp[i] = stack[i];
        }

        delete[]stack;
        stack = new T[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            stack[i] = temp[i];
        }
        
        delete[]temp;
    }
    T printTop()const
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
    Stack<char> s(5);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    
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
    
    Stack<int> s2(6);
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    s2.push(6);

    std::cout << s2.printTop() << std::endl;
    s2.pop();
    std::cout << s2.printTop() << std::endl;
    s2.pop();
    std::cout << s2.printTop() << std::endl;
    s2.pop();
    std::cout << s2.printTop() << std::endl;
    s2.pop();
    std::cout << s2.printTop() << std::endl;
    s2.pop();
    std::cout << s2.printTop() << std::endl;
    s2.pop();
}

int main()
{
    func();

    return 0;
}