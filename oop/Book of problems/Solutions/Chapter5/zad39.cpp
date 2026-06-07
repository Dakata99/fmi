#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>
#include <stdlib.h>

enum ElementType{LIST, BTREE, INT};

// Абстрактен тип елемент на контейнер
class AbstractElement
{ 
public:
    // идентифицира конкретния тип на елемента
    virtual int getType() const = 0;
    // оператор за сериализация в изходен поток
    // данните трябва да бъдат записани така, че след
    // това чрез тях операторът за десериализация
    // да може да създаде аналогична СД
    virtual ostream& write(ostream&) const = 0;
    // оператор, който трябва да създаде копие на
    // структурата от данни, записана от оператора <<
    virtual istream& read(istream&) = 0;
    // създава обект на някоя от конкретните
    // реализации на АbstractElement според
    // желания тип, посочен чрез параметъра
    static AbstractElement* elementFactory(int type);
    // Създава копие на дадения елемент. Копието е различен
    // обект с идентично съдържание. Разчита на конструктора
    // за копиране на съответния клас
    static AbstractElement* copyElement(AbstractElement*);
};

// Клас за представяне на елементи – цели числа
class IntElement : public AbstractElement
{ 
public:
    IntElement(int value) : i(value)
    {}

    int getType() const
    { 
        return INT;
    }

    ostream& write(ostream& out) const
    { 
        out << i << " ";
        return out;
    }

    istream& read(istream& in) 
    {
        in >> i;
        return in;
    }

private:
    int i;
};

// Двойна кутия за динамичен едносвързан списък
struct DListNode
{ 
    DListNode(AbstractElement* _data, DListNode* _next)
              : data(_data), next(_next)
    {};
    AbstractElement *data;
    DListNode *next;
};

//константа, указваща края на списъка
const int listEnd = -1;

// Линеен едносвързан списък
class DList : public AbstractElement
{ 
public:
    DList() : first(NULL), count(0)
    {};

    // конструктор за копиране
    DList(const DList& l) : first(NULL), count(0)
    { 
        copy(l);
    }

    // оператор за присвояване
    DList& operator=(const DList& l)
    { 
        if(this == &l)
            return *this;
        clearAll();
        copy(l);
        return *this;
    }

    int getType() const
    { 
        return LIST;
    }

    // добавя елемент на определена позиция в списъка, а
    // при index == listEnd, в края му.
    // Ако толкова голям индекс не съществува в списъка,
    // добавя също в края му.
    bool addElementAt(AbstractElement *element, int index)
    { 
        if(!first || index == 0)
            return addFirst(element);
        DListNode* previous = first;
        // намира указател към елемента, след който ще вмъква новия елемент
        index--;
        while(previous->next != NULL && index != 0)
        { 
            previous = previous->next;
            index--;
        }
        return insertAfter(previous, element);
    }

    // връща елемента на определена позиция в списъка и NULL, ако няма такъв
    AbstractElement* getElementAt(int index) const
    { 
        if(!first || index < 0 || index >= count)
            return NULL;
        DListNode* current = first;
        while(current && index != 0)
        { 
            current = current->next;
            index--;
        }
        return current->data;
    }

    // работи добре само за списъци от числа
    void print() const
    { 
        DListNode* current = first;
        while(current)
        { 
            current->data->write(cout);
            current = current->next;
        }
    }

    ostream& write(ostream& out) const
    { 
        // записва първо броя на елементите
        out << count << " ";
        // последователно сериализаира всеки елемент
        DListNode* current = first;
        while(current)
        {
            // записва типа на поредния елемент
            out << current->data->getType() << " ";
            // и самия елемент
            current->data->write(out);
            current = current->next;
        }
        return out;
    }

    istream& read(istream& in)
    { 
        clearAll();
        int newCount, newElementType;
        AbstractElement* newElement;
        in >> newCount;
        // десериализаира всеки от записаните елементи
        for(; newCount > 0; newCount--)
        { 
            // какъв е типът на този елемент?
            in >> newElementType;
            // създаване на представител на елемент от този тип
            newElement = AbstractElement::elementFactory(newElementType);
            if(newElement == NULL)
            { 
                cout << "Грешка! Погрешен тип!";
                return in;
            }
            // предава потока на новия обект, който
            // да прочете съдържанието си от там
            newElement->read(in);
            addElementAt(newElement, listEnd);
        }
        return in;
    }

    ~DList()
    { 
        clearAll();
    }

private:
    DListNode *first;
    int count;
    // изтрива всички елементи
    void clearAll()
    { 
        if(!first)
            return;
        DListNode* current = first,
                 * next = first->next;
        while(current)
        { 
            delete current->data;
            delete current;
            current = next;
            if(current != NULL)
                next = current->next;
        }
    }

    // добавя нов елемент след дадения приема се, че previous е коректен
    bool insertAfter(DListNode* previous, AbstractElement* element)
    { 
        previous->next = new DListNode(element, previous->next);
        count++;
        return previous->next != NULL;
    }

    // променя първия елемент на списъка
    bool addFirst(AbstractElement *element)
    { 
        first = new DListNode(element, first);
        count++;
        return first != NULL;
    }

    // копира елементите на списъка src
    void copy(const DList& src)
    { 
        DListNode* current = src.first;
        while(current != NULL)
        { 
            addElementAt(AbstractElement::copyElement(current->data), listEnd);
            current = current->next;
        }  
    }
};


// Връх на двоично дърво
struct BTreeNode
{ 
    BTreeNode(AbstractElement *_data, BTreeNode *_left, BTreeNode *_right) 
              : data(_data), left(_left), right(_right)
    {};
    AbstractElement* data;
    BTreeNode *left, *right;
};

class BTree;

// помощен клас за обхождане на двоично дърво
class BTreeIterator
{ 
public:
    // при създаване, итераторът
    // сочи корена на дървото
    BTreeIterator(BTree* _tree);
    // връща итератор към лявото поддърво
    // Ако дървото е празно, връща копие на същия итератор
    BTreeIterator left();
    // връща итератор към дясното поддърво
    // Ако дървото е празно, връща копие на същия итератор
    BTreeIterator right();
    // връща стойността на корена на поддървото
    AbstractElement* root();
    // променя стойността на корена
    // Ако поддървото е празно, в дървото
    // се добавя нов връх с тази стойност
    bool changeRoot(AbstractElement* data);
    // проверка за празно дърво
    bool empty();

private:
    // двоен указател, за да може да бъде променяна стойността
    // на вече съществуващи указатели в структурата на
    // дървото, например при добавяне на нов елемент
    BTreeNode **currentNode;
    BTree *tree;
};

// Класът, реализиращ двоично дърво също
// може да бъде елемент на контейнер
class BTree : public AbstractElement
{ 
public:
    BTree() : root(NULL)
    {}

    // конструктор за копиране
    BTree(const BTree& tree) : root(NULL)
    { 
        copy(tree);
    }

    // оператор за присвояване
    BTree& operator=(const BTree& tree)
    { 
        if(this != &tree)
            copy(tree);
        return *this;
    }  

    // връща итератор към дървото
    BTreeIterator iterator()
    { 
        return BTreeIterator(this);
    }

    int getType() const
    { 
        return BTREE;
    }

    ostream& write(ostream& out) const
    { 
        writeNode(root, out);
        return out;
    }

    istream& read(istream& in)
    { 
        clearAll(root);
        root = NULL;
        readNode(root, in);
        return in;
    }

    // работи добре само за дървета от числа
    void print()
    { 
        prettyPrint(root);
    }

    ~BTree()
    { 
        clearAll(root);
    }

    friend class BTreeIterator;

private:
    BTreeNode *root;

    // работи добре само за дървета от числа
    void prettyPrint(BTreeNode *root, int level=0)
    { 
        if(!root)
            return;
        prettyPrint(root->left, level+1);
        cout << setw(level*3) << " ";
        root->data->write(cout);
        cout << endl;
        prettyPrint(root->right, level+1);
    }

    void clearAll(BTreeNode *root)
    { 
        if(!root)
            return;
        clearAll(root->left);
        clearAll(root->right);
        delete root->data;
        delete root;
    }

    void writeNode(BTreeNode* root, ostream& out) const
    { 
        if(!root)
        { 
            out << "() ";
            return;
        }
        out << "( ";
        writeNode(root->left, out);
        out << root->data->getType() << " ";
        root->data->write(out);
        writeNode(root->right, out);
        out << ") ";
    }

    void readNode(BTreeNode*& root, istream& in)
    { 
        char c;
        // прескачане на отварящата скоба
        in >> c;
        // ако веднага следва затваряща скоба, дървото е празно
        if(in.peek() == ')')
        { 
            // прескачане на затварящата скоба
            in >> c;
            return;
        }
        BTreeNode * newLeft  = NULL,
                  * newRight = NULL;
        // прочитане на лявото поддърво
        readNode(newLeft, in);
        int type;
        // Прочита се кодът, идентифициращ типа на
        // съдържанието на корена. Създава се празен
        // обект от този тип и се използва read за
        // прочитане на съдържанието му
        in >> type;
        AbstractElement* data = AbstractElement::elementFactory(type);
        data->read(in);
        // прочитане на дясното поддърво
        readNode(newRight, in);
        // прескачане на затварящата скоба
        in >> c;
        // създаване на новия връх
        root = new BTreeNode(data, newLeft, newRight);
        return;
    }

    // изтирва текущото дърво и създава идентично копие на дървото tree
    void copy(const BTree& tree)
    {
        clearAll(root);
        root = copyNode(tree.root);
    }

    // изпозлва се от copy
    BTreeNode* copyNode(BTreeNode* node)
    { 
        if(node == NULL)
            return NULL;
        return new BTreeNode (AbstractElement::copyElement(node->data),
                              copyNode(node->left),
                              copyNode(node->right));
    }
};

BTreeIterator::BTreeIterator(BTree *_tree)
{ 
    tree = _tree;
    currentNode = &tree->root;
}

BTreeIterator BTreeIterator::left()
{ 
    BTreeIterator it = *this;
    if(*currentNode)
        it.currentNode = &(*currentNode)->left;
    return it;
}

BTreeIterator BTreeIterator::right()
{ 
    BTreeIterator it = *this;
    if(*currentNode)
        it.currentNode = &(*currentNode)->right;
    return it;
}

AbstractElement *BTreeIterator::root()
{ 
    if(*currentNode)
        return (*currentNode)->data;
    return NULL;
}

bool BTreeIterator::changeRoot(AbstractElement *data)
{ 
    if(*currentNode)
    {
        delete (*currentNode)->data;
        (*currentNode)->data = data;
    } 
    else
    {
        (*currentNode) = new BTreeNode(data, NULL, NULL);
    }
    // за успех се счита промяната на данните, както
    // и успешното създаване на нов елемент
    return *currentNode != NULL;
}

bool BTreeIterator::empty()
{ 
    return *currentNode == NULL;
}

AbstractElement* AbstractElement::elementFactory(int type)
{ 
    switch(type)
    { 
    case INT: return new IntElement(0);
    case LIST: return new DList;
    case BTREE: return new BTree;
    }
    return NULL;
}

AbstractElement* AbstractElement::copyElement (AbstractElement* element)
{ 
    switch (element->getType())
    { 
    case INT: return new IntElement(*(IntElement*)element);
    case LIST: return new DList(*(DList*)element);
    case BTREE: return new BTree (*(BTree*)element);
    }
    return NULL;
}

void writeDemo()
{ 
    //създаване на списък с елементи 1, 2 и 3
    DList *l1 = new DList;
    l1->addElementAt(new IntElement(1), listEnd);
    l1->addElementAt(new IntElement(2), listEnd);
    l1->addElementAt(new IntElement(3), listEnd);
    // създаване на списък с елементи 4, 5 и 6
    DList *l2 = new DList;
    l2->addElementAt(new IntElement(4), listEnd);
    l2->addElementAt(new IntElement(5), listEnd);
    l2->addElementAt(new IntElement(6), listEnd);
    // създаване на двоично дърво
    BTree *t = new BTree;
    t->iterator().changeRoot(new IntElement(7));
    t->iterator().left().changeRoot(new IntElement(8));
    // добавяне на списъкът l1 като елемент на дървото
    t->iterator().left().left().changeRoot(l1);
    t->iterator().right().changeRoot(new IntElement(9));
    // създаване на списък с елементи: списък, число, дърво
    DList theList;
    theList.addElementAt(l1, listEnd);
    theList.addElementAt(new IntElement(10), listEnd);
    theList.addElementAt(t, listEnd);
    // създаване на файл, в който да се запише списъкът
    ofstream file("data.txt");
    theList.write(file);
}

void readDemo()
{ 
    DList l;
    // прочита списъка, записан от writeDemo
    ifstream file("data.txt");
    // Внимание! функцията разчита, че този файл е създаден
    // от writeDemo. В противен случай следващите
    // преобразувания може да не са коректни
    l.read(file);
    // Методът writeDemo поставя двоично дърво като трети
    // елемент на списъка
    // Преобразува се абстрактният елемент до конкретния
    // клас BTree, за да се осигури достъп до метода
    // print, който е специфичен за класа на дървото
    ((BTree*)l.getElementAt(2))->print();
}

int main()
{ 
    writeDemo();
    readDemo();
    return 0;
}
