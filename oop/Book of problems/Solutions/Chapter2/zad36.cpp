#include <iostream.h>

const int MaxStack = 100;            
const int FullStack = MaxStack;      
const int EmptyStack = -1;           
const char EmptyFlag = '\0';         

class StackIter;


class Stack
{ 
private:
    friend StackIter;		
    char items[MaxStack];            
    int top;                         
public:
    Stack();
    Stack(const Stack&);
    
    void push(char c);
    char pop();
    bool empty() const;
    bool full() const;

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
        cout << "������ � �����!\n";
        return;
    }
    items[++top] = c;
}

char Stack::pop()
{ 
    if(empty())
    { 
        cout << "������ � ������!\n";
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


class StackIter
{ 
private:
    Stack* st;            

public:
    StackIter(Stack& s)
    { 
        st = &s;
    }
    char* getNext();
};

char* StackIter::getNext()
{ 
    if(st->top == EmptyStack)
        return 0;
    return &st->items[st->top--];
}

int main()
{ 
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    Stack t = s;

    s.print();

    StackIter si(t);
    char* ptr = NULL;

    while(ptr = si.getNext())
        cout << *ptr << endl;
    return 0;
}
