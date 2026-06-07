#include <iostream.h>

const int MAX = 20;

class differ
{
public:
    // конструктор с параметър, задаващ дължината на редица
    differ(int m)
    { 
        n = m;
        for(int i = 0; i < m; i++)
            cin >> a[i];
    }

    // функция, която определя дали подразбиращата
    // се редица се състои от различни числа
    bool diff() const
    { 
        if(n == 1) return true;
        int i = -1;
        bool b; int j;
        do
        { 
            i++; j = i;
            do
            { 
                j++;
                b = a[i] != a[j];
            } while (b && j < n-1);
        } while (b && i < n-2);
        return b;
    }

private:
    int n;                       // брой елементи на редица
    int a[MAX];                  // носител на редица
};

int main()
{ 
    // въвеждане на редица
    int n;
    do
    { 
        cout << "n= "; 
        cin >> n;
    } while (n < 1);

    // създаване на обект t на класа differ,
    // задаващ непразна редица от цели числа
    differ t(n);
    // проверка дали елементите на редицата,
    // зададена чрез обекта t са различни
    cout << "Елементите на редицата " 
         << (t.diff()? "са различни.\n" : "не са различни.\n");
    return 0;
}
