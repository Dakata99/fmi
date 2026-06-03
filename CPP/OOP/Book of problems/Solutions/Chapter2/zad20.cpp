#include <iostream.h>

const int MaxStack = 100;             // максимален брой елементи на стека
const int FullStack = MaxStack;       // константа, индицираща пълен стек
const int EmptyStack = -1;            // константа, индицираща празен стек
const char EmptyFlag = '\0';          // помощен флаг за празен стек

class Stack
{
private:
    char items[MaxStack];             // носител на стека
    int top;                          // указател към върха на стека

public:
    // конструктор по подразбиране,
    // създаващ празен стек
    Stack();
    // конструктор за присвояване
    Stack(const Stack&);
    // член-функция, която включва символа
    // c в неявния стек
    void push(char c);
    // член-функция, която изключва елемент от
    // неявния стек, ако последният не е празен
    char pop();
    // член-функция, която проверява дали
    // неявният стек е празен
    bool empty() const;
    // член-функция, която проверява дали
    // неявният стек е пълен
    bool full() const;
    // член-функция, която извежда елементите
    // на неявния стек, като го разрушава
    void print();
};

Stack::Stack()
{
    top = EmptyStack;
}

Stack::Stack(const Stack& s)
{
    top = s.top;
    for(int i = 0; i <= top; i++)
        items[i] = s.items[i];
}

void Stack::push(char c)
{
    if(full())
    {
        cout << "Стекът е пълен!\n";
        return;
    }
    items[++top] = c;
}

char Stack::pop()
{
    if(empty())
    {
        cout << "Стекът е празен!\n";
        return EmptyFlag;
    }
    return items[top--];
}

bool Stack::empty() const
{
    return top == EmptyStack;
}

bool Stack::full() const
{
    return top == FullStack - 1;
}

void Stack::print()
{
    for(int i = top; i >= 0; i--)
        cout << pop() << endl;
}

int main()
{
    // създаване на празен стек s
    Stack s;
    // включване на символите ’a’, ’b’ и ’c’ в s
    s.push('a');
    s.push('b');
    s.push('c');
    // създаване на нов стек t, копие на стека s
    Stack t = s;
    // извеждане на елементите на стека s
    s.print();
    // изключване на елемент от стека t
    if(!t.empty())
        cout << t.pop() << endl;
    // извеждане на останалите елементи на стека t
    t.print();
    return 0;
}
