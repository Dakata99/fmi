#include <iostream.h>

const int MaxStack = 100;        // максимален брой елементи на стека и на опашката
const int FullStack = MaxStack;  // константа, индицираща пълен стек
const int EmptyStack = -1;       // константа, индицираща празен стек
const char EmptyFlag = '\0';     // помощен флаг за празен стек

class Stack
{ 
private:
    char items[MaxStack];    // носител на стека
    int top;                 // указател към върха на стека

public:
    // конструктор по подразбиране, създаващ празен стек
    Stack();
    // конструктор за присвояване
    Stack(const Stack&);
    // член-функция, която включва символа c в неявния стек
    void push(char c);
    // член-функция, която изключва елемент от
    // неявния стек, ако последният не е празен
    char pop();
    // функция за достъп, проверяваща дали неявният стек е празен
    bool empty() const;
    // функция за достъп, проверяваща дали неявният стек е пълен
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
        cout << "Препълване!\n";
        return;
    }
    items[++top] = c;
}

char Stack::pop()
{ 
    if(empty())
    { 
        cout << "Няма елементи!\n";
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

// дефиниция на класа Queue
class Queue : Stack
{ 
public:
    Queue();                    // конструктор
    void add(const char&);      // включване на елемент
    void remove();              // изключване на елемент
    char front();               // намира елемента в началото
    bool empty() const;         // проверка за празна опашка
    bool full() const;          // проверка за пълна опашка
    int length();               // дължина на опашка
    void print();               // извеждане на опашка
};

// конструктор по подразбиране Създава празна опашка.
Queue::Queue()
{}

// включване на елемента c в опашка
void Queue::add(const char& c)
{ 
    Stack s;
    while(!empty())
        s.push(pop());
    push(c);
    while(!s.empty())
        push(s.pop());
}

// изключване на елемент от опашка
void Queue::remove()
{ 
    pop();
}

// намиране на елемента в началото на опашка
char Queue::front()
{
    char h = pop();
    push(h);
    return h;
}

// проверка дали опашка е празна
bool Queue::empty() const
{ 
    return Stack::empty();
}

// проверка дали опашка е пълна
bool Queue::full() const
{ 
    return Stack::full();
}

// намиране на дължината на опашка без тя
// да се разрушава (разрушава се копието й)
int Queue::length()
{ 
    Stack s = *this;
    int n = 0;
    while(s.pop())
        n++;
    return n;
}

// извеждане на елементите на опашка с разрушаването й
void Queue::print()
{ 
    Stack::print();
}

int main()
{ 
    // създаване на опашка q1
    Queue q1;
    cout << "Въведете редица от символи!\n"
            "За край, въведете символа #.\n";
    while(!q1.full())
    { 
        char ch;
        cout << "> "; cin >> ch;
        if(ch != '#') q1.add(ch);
        else break;
    }

    // създаване на опашка q2 – копие на q1
    Queue q2 = q1;
    // извеждане на елементите на опашката q1
    q1.print();
    
    // извеждане на елементите на опашката q2
    while(!q2.empty())
    { 
        cout << q2.front() << endl;
        q2.remove();
    }
    return 0;
}
