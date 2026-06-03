#include <iostream.h>

const int MaxStack = 100;             // максимален брой елементи на стека
const int FullStack = MaxStack;       // константа, индицираща пълен стек
const int EmptyStack = -1;            // константа, индицираща празен стек

template <class T>
class Stack
{
private:
    T items[MaxStack];  // носител на стек с елементи от тип T
    int top;                 // указател към върха на стека

public:
    // конструктор по подразбиране,
    // създаващ празен стек
    Stack();
    // конструктор за присвояване
    Stack(const Stack&);
    // член-функция, която включва
    // елемента c в неявния стек
    void push(T c);
    // член-функция, която изтрива елемент от
    // неявния стек, ако последният не е празен
    T pop();
    // член-функция, проверяваща дали
    // неявният стек е празен
    bool empty() const;
    // член-функция, проверяваща дали
    // неявният стек е пълен
    bool full() const;
    // член-функция, която извежда елементите
    // на неявния стек, като го разрушава
    void print();
};

template <class T>
Stack<T>::Stack()
{ 
    top = EmptyStack;
}

template <class T>
Stack<T>::Stack(const Stack<T>& s)
{
    top = s.top;
    for(int i = 0; i <= top; i++)
        items[i] = s.items[i];
}

template <class T>
void Stack<T>::push(T c)
{ 
    if(full())
    { 
        cout << "Стекът е пълен!\n";
        return;
    }
    items[++top] = c;
}

template <class T>
T Stack<T>::pop()
{ 
    if(empty())
    { 
        cout << "Стекът е празен!\n";
        return 0;
    }
    return items[top--];
}

template <class T>
bool Stack<T>::empty() const
{ 
    return top == EmptyStack;
}

template <class T>
bool Stack<T>::full() const
{ 
    return top == FullStack - 1;
}

template <class T>
void Stack<T>::print()
{
    for(int i = top; i >= 0; i--)
        cout << pop() << endl;
}

int main()
{ 
    // създаване на празен стек от символи s
    Stack<char> s;
    // включване на символите ’a’, ’b’ и ’c’в s
    s.push('a');
    s.push('b');
    s.push('c');
    // създаване на нов стек от символи t,
    // копие на стека s
    Stack<char> t = s;
    // извеждане на елементите на стека s
    s.print();
    // изключване и извеждане на елемент от стека t
    if(!t.empty())
        cout << t.pop() << endl;
    // извеждане на останалите елементи на стека t
    t.print();
    return 0;
}
