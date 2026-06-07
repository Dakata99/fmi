#include <iostream.h>
#include <iomanip.h>

class IntSequence
{ 
public:
    // включване на елемент на определена позиция в редица
    virtual bool addElementAt(int value, int index) = 0;

    // вземане на елемент от определена позиция в редица
    // Възможни са:
    // а) Елемент с такъв индекс е добавен в редицата
    // Функцията връща истина и
    // записва в value стойността на елемента
    // б) Елемент с такъв индекс не е добавян в редицата
    // Функцията връща лъжа и стойността
    // на value не е определена
    virtual bool getElementAt(int &value, int index) const = 0;

    // изключване на елемент от дадена позиция
    // Ако елемент с такъв индекс не е добавян,
    // връща лъжа, в противен случай - истина.
    virtual bool removeElementAt(int index) = 0;

    // намиране на броя на елементите на редица
    virtual int count() const = 0;

    // Функцията връща:
    // 1,  ако всеки следващ елемент на редица е
    //     по-голям на предишния
    // -1, ако всеки следващ елемент на редица е
    //     по-малък на предишния
    // 0,  във всички останали случаи
    virtual int isMonotonous() const = 0;
};

class IntSet
{
public:

    // проверка дали x принадлежи на множество
    virtual bool element(int x) const = 0;

    // включване на елемент в множество
    virtual bool addElement(int x) = 0;

    // изключване на елемент от множество
    virtual bool removeElement(int x) = 0;

    // намиране сечението на две множества
    virtual bool intersection(const IntSet& s) const = 0;

    // проверка дали множество е подмножество на дадено множество
    virtual bool subset(const IntSet& s) const = 0;
};

// помощен клас, позволяващ пряка индексация на елементите на динамичен масив
class ArrIndexProxy
{  
public:
    ArrIndexProxy(IntSequence *arr, int index) :
                  targetArr(arr),targetIndex(index)
    {}

    ArrIndexProxy(const ArrIndexProxy& p) :
                  targetArr(p.targetArr), targetIndex(p.targetIndex)
    {}

    // оператор за извличане на стойност
    operator int() const
    { 
        int value;
        targetArr->getElementAt(value, targetIndex);
        return value;
    }

    ArrIndexProxy& operator=(int x)
    { 
        targetArr->addElementAt(x,targetIndex);
        return *this;
    }

    ArrIndexProxy& operator=(const ArrIndexProxy& p)
    {
        return *this = (int)p;
    }

private:
    IntSequence *targetArr;
    int targetIndex;
};

class DynArray : public IntSequence, public IntSet
{
public:
    // Масивът се инициализира с начален размер на буфера
    DynArray(int initialSize = 5) : size(initialSize)
    {
        data = new int[size];
        used = new bool[size];
        setUnused(used,size);
    }

    bool addElementAt(int value, int index)
    {
        if(size <= index && !resize(index+1))
            return false;
        data[index] = value;
        used[index] = true;
        return true;
    }

    bool getElementAt(int &value, int index) const
    {
        if(index >= size || !used[index])
            return false;
        value = data[index];
        return true;
    }

    bool removeElementAt(int index)
    {
        if(index >= size || !used[index])
            return false;
        used[index] = false;
        return true;
    }

    int count() const
    {
        int count = 0;
        for(int i = 0; i < size; i++)
            if(used[i]) count++;
        return count;
    }

    int isMonotonous() const
    {
        int a = getNextUsed(-1),
            b = getNextUsed(a);
        if(b < 0)
            return 0;
        int direction = 0;
        if(data[a] == data[b])
            return 0;
        if(data[a] > data[b])
            direction = 1;
        else
            direction = -1;
        // релацията се "обръща", когато direction == -1
        while(b != -1 && direction*data[a] > direction*data[b])
        {
            a = b;
            b = getNextUsed(b);
        }
        // цикълът е обходил всички използвани данни и не е намерил контрапример
        if(b == -1)
            return direction;
        // контрапример е намерен
        return 0;
    }

    bool element(int x) const
    {
        int a = getNextUsed(-1);
        while(a != -1 && data[a] != x)
            a = getNextUsed(a);
        return a != -1;
    }

    bool addElement(int x)
    {
        int freeSlot = 0;
        while(freeSlot < size && used[freeSlot])
            freeSlot++;
        if(freeSlot == size && !resize(size+1))
            return false;
        data[freeSlot] = x;
        used[freeSlot] = true;
        return true;
    }

    bool removeElement(int x)
    {
        bool found = false;
        int index = getNextUsed(-1);
        while(index != -1)
        {
            if(data[index] == x)
            {
                used[index] = false;
                found = true;
            }
            index = getNextUsed(index);
        }
        return found;
    }

    bool intersection(const IntSet& s) const
    {
        int index = getNextUsed(-1);
        while(index != -1 && !s.element(data[index]))
            index = getNextUsed(index);
        return index != -1;
    }

    bool subset(const IntSet& s) const
    {
        int index = getNextUsed(-1);
        while(index != -1 && s.element(data[index]))
            index = getNextUsed(index);
        return index == -1;
    }

    // Връща елемента с указания индекс. Резултатът е
    // неопределен, ако на тази позиция не е поставян елемент.
    // Типът на резултата на оператора позволява чрез
    // този оператор не само да се извличат, но
    // и да се променят елементите на масив
    // (вижте клас ArrIndexProxy)
    ArrIndexProxy operator[](int index) const
    {
        ArrIndexProxy proxy((IntSequence*)this,index);
        return proxy;
    }

    ~DynArray()
    {
        delete data;
        delete used;
    }

    // Връща индекса на следващия зает елемент
    // (най-малкият зает индекс, по-голям от index)
    // и -1, ако няма такъв
    int getNextUsed(int index) const
    {
        index++;
        while(index < size && (index < 0 || !used[index]))
            index++;
        if(index == size)
            return -1;
        return index;
    }

    // Връща индекса на следващия незает елемент
    // (най-малкия незает индекс, по-голям от index)
    // и се опитва да задели, ако няма такъв
    int getNextUnUsed(int index)
    {
        index++;
        while(index < size && (index < 0 || used[index]))
            index++;
        if(index == size  && !resize(index+1))
            return -1;
        return index;
    }

private:
    // размер на заделения буфер (в брой елементи)
    int size;
    // буфер със стойности
    int *data;
    // кои стойности в буфера са установени и кои - не
    bool *used;

    // Установява count на брой флага в булевия масив flags на false
    void setUnused(bool *flags, int count)
    {
        for(int i = 0; i < count; i++)
            flags[i] = false;
    }

    // Увеличава размера на масива по такъв начин, че
    // да стане по-голям или равен на minSize
    bool resize(int minSize)
    {
        int newSize = size;
        while(newSize < minSize)
            newSize *= 2;
        int *newData = new int[newSize];
        bool *newUsed = new bool[newSize];
        // проверка за проблем при заделяне на паметта
        if(!newData || !newUsed)
            return false;
        // прехвърляне на старите данни
        for(int i = 0; i < size; i++)
        {
            newData[i] = data[i];
            newUsed[i] = used[i];
        }
        setUnused(newUsed+size,newSize-size);
        int *saveData = data;
        bool *saveUsed = used;
        data = newData;
        used = newUsed;
        size = newSize;
        delete saveData;
        delete saveUsed;
        return true;
    }
};

class IntBinOrdTree : public IntSet
{
public:
    IntBinOrdTree() : root(-1)
    {}

    virtual bool element(int x) const
    {
        if(root != -1 && getValue(root) == x)
            return true;
        int parent = findParent(x,root);
        return parent != -1 &&
              ((leftChild(parent) != -1 && getValue(leftChild(parent)) == x) ||
               (rightChild(parent) != -1 && getValue(rightChild(parent)) == x));
    }

    virtual bool addElement(int x)
    {
        // дървото е празно
        if(root == -1)
        { 
            // създаване на нов корен с номер 0
            root = 0;
            return createNodeAt(x,0);
        }
        int parent = findParent(x,root),
            newIndex = -1;
        // нов номер за новия елемент
        newIndex = data.getNextUnUsed(-1);
        if(x <= getValue(parent))// Елементът трябва да се добави като ляв наследник
        { 
            // елементът вече съществува
            if(leftChild(parent) != -1)
                return true;
            // създаване на новия елемент
            if(!createNodeAt(x,newIndex))
                return false;
            // свързване на родителя с новия елемент
            data[parent*3+1] = newIndex/3;
            return true;
        }

        // Елементът трябва да се добави като десен наследник
        // елементът вече съществува
        if(rightChild(parent) != -1)
            return true;

        // създаване на новия елемент
        if(!createNodeAt(x, newIndex))
            return false;

        // свързване на родителя с новия елемент
        data[parent*3+2] = newIndex/3;
        return true;
    }

    virtual bool removeElement(int x)
    { 
        if(root == -1)
            return false;
        // изтриване на корена
        if(getValue(root) == x)
        { 
            root = eraseRoot(root);
            return true;
        }
        else if(x < getValue(root))
        {
            return eraseFromSubTree(x, leftChild(root));
        }
        else
        {
            return eraseFromSubTree(x, rightChild(root));
        }
    }

    virtual bool intersection(const IntSet& s) const
    {
        return intersection(root, s);
    }

    virtual bool subset(const IntSet& s) const
    {
        return subset(root, s);
    }

    void print() const
    {
        cout << "*****\n";
        if(root == -1)
            cout << "empty " << endl;
        else
            prettyPrint(root);
        cout << "*****\n";
    }

private:
    // Дървото е представено чрез масива data по следния
    // начин: всеки връх се представя с три последователни
    // елемента от масива (за всяко i, data[3*i] е стойността
    // на връх, data[3*i+1] е номер (а не индекс в масива)
    // на корена на лявото поддърво или -1, ако няма ляво
    // поддърво, data[3*i+2] - аналогично за дясното поддърво
    DynArray data;

    // номер на корена на дървото или -1, ако дървото е празно
    int root;

    // намиране на родителя на елемента x в
    // поддървото с корен root
    // Ако такъв елемент не съществува в дървото, връща
    // номера на "потенциалния" му родител, т.е. връх,
    // чиито наследник би могъл да бъде x
    int findParent(int x, int root) const
    {
        if(root == -1)
            return -1;

        if(x <= getValue(root))
        { 
            // Елементът x не е в дървото, но би могъл да
            // бъде ляв наследник на root
            if(leftChild(root) == -1)
                return root;
            // елементът е пряк наследник на root
            if(getValue(leftChild(root)) == x)
                return root;
            // продължава търсенето наляво
            return findParent(x, leftChild(root));
        }

        // Елементът x не е в дървото, но би могъл да
        // бъде десен наследник на root
        if(rightChild(root) == -1)
            return root;
        // елементът е пряк наследник на root
        if(getValue(rightChild(root)) == x)
            return root;
        // продължава търсенето надясно
        return findParent(x, rightChild(root));
    }

    bool intersection(int treeRoot, const IntSet &t) const
    {
        if(treeRoot == -1)
            return false;
        return t.element(getValue(treeRoot)) ||
               intersection(leftChild(treeRoot),t) ||
               intersection(rightChild(treeRoot), t);
    }

    bool subset(int treeRoot, const IntSet &t) const
    {
        if(treeRoot == -1)
            return true;
        return t.element(getValue(treeRoot)) &&
               subset(leftChild(treeRoot), t) &&
               subset(rightChild(treeRoot), t);
    }

    void prettyPrint(int treeRoot, int level = 0) const
    {
        if(treeRoot == -1)
            return;
        prettyPrint(leftChild(treeRoot), level+1);
        cout << setw(level*3) << getValue(treeRoot) << endl;
        prettyPrint(rightChild(treeRoot), level+1);
    }

    // намиране на стойността на върха с номер root
    // при root == -1 резултатът е неопределен
    int getValue(int root) const
    {
        return data[3*root];
    }

    // намиране на левия наследник
    ArrIndexProxy leftChild(int root) const
    {
        return data[3*root+1];
    }

    // намиране на десния наследник
    ArrIndexProxy rightChild(int root) const
    {
        return data[3*root+2];
    }

    // създаване на елемент на дадения индекс
    bool createNodeAt(int value, int index)
    {
        return data.addElementAt(value, index) &&
               data.addElementAt(-1, index+1)  &&
               data.addElementAt(-1, index+2);
    }

    // намиране на най-малкия елемент в дървото с корен root
    int leftMost(int root)
    {
        if(root == -1)
            return -1;
        if(leftChild(root) == -1)
            return root;
        return leftMost(leftChild(root));
    }

    // изтриване на връх с даден номер
    bool freeNode(int node)
    {
        return data.removeElementAt(node*3) &&
               data.removeElementAt(node*3+1) &&
               data.removeElementAt(node*3+2);
    }

    // изтриване на елемент от някое поддърво
    bool eraseFromSubTree(int x, ArrIndexProxy treeRoot)
    {
        if(treeRoot == -1)
            return false;
        // изтриване на корена
        if(x == getValue(treeRoot))
        {
            treeRoot = eraseRoot(treeRoot);
            return true;
        }
        int parent = findParent(x, treeRoot);

        // node е елементът от масива, който
        // съдържа номера на върха със стойност x
        ArrIndexProxy node = (x <= getValue(parent) ? leftChild(parent) : rightChild(parent));

        // върхът за изтриване има два наследника
        if(leftChild(node) != -1 && rightChild(node) != -1)
        {
            // заменяне на стойността на върха със стойността
            // на най-малкия елемент в лявото му поддърво
            data[node*3] = getValue(leftMost(rightChild(node)));
            return eraseFromSubTree(getValue(node),
                rightChild(node));
        }

        int tmp = node;
        // върхът има само десен наследник
        if(leftChild(node) == -1)
        {
            // следващото присвояване променя елемента
            // на масива, който е част от представянето
            // на върха parent и съдържа номера на
            // левия/десния му наследник
            node = rightChild(node);
        } 
        else
        {
            node = leftChild(node);
        }
        return freeNode(tmp);
    }

    // изтриване на корена на дадено поддърво връща номера на новия му корен
    int eraseRoot(int treeRoot)
    {
        int tmp = treeRoot;
        if(leftChild(treeRoot) == -1)
        {
            treeRoot = rightChild(treeRoot);
            freeNode(tmp);
            return treeRoot;
        }

        if(rightChild(treeRoot) == -1)
        {
            treeRoot = leftChild(treeRoot);
            freeNode(tmp);
            return treeRoot;
        }

        // коренът има два наследника
        tmp = leftMost(rightChild(treeRoot));

        // прехвърляне на стойността на
        // най-малкия елемент в дясното поддърво
        // върху стойността на корена
        data[treeRoot*3] = getValue(tmp);
        // изтриване на най-малкия елемент в дясното поддърво
        eraseFromSubTree(getValue(tmp), rightChild(treeRoot));
        return treeRoot;
    }
};

bool containsRange(IntSet* set, int start, int end)
{
    for(int i = start; i <= end; i++)
        if(!set->element(i))
            return false;
    return true;
}

int main()
{
    DynArray da;
    IntBinOrdTree tree;
    int i = 0, count = 0;
    cout << "Въведете елементи на масива, -1 за край.";
    cin >> i;
    while(i != -1)
    {
        da.addElementAt(i, count);
        tree.addElement(i);
        cin >> i;
        count++;
    }

    cout << containsRange((IntSet*)&da, 1, 5) << endl
         << containsRange((IntSet*)&tree, 1, 5);
    return 0;
}
