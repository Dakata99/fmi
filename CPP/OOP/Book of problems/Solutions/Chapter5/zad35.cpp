#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

// ако низът s има вида на шаблона, функцията
// конструира новия шаблон в низа ns
bool templet(const char* s, char* ns)
{
    if(!s || strlen(s) > 7) return false;
    char a[8]; strcpy(a, s);
    char ch1 = s[1], ch2 = s[3];
    if(ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z')
    {
        a[1]='0'; a[3]='0';
    }
    if(strcmp(a, "(0+0)^2") == 0)
    {
        ns[0] = '('; ns[1] = ch1; ns[2] = '^';  ns[3] = '2';
        ns[4] = '+'; ns[5] = '2'; ns[6] = ch1;  ns[7] = ch2;
        ns[8] = '+'; ns[9] = ch2; ns[10] = '^'; ns[11] = '2';
        ns[12] = ')'; return true;
    }
    else
    {
        return false;
    }
}

// Функцията заменя всеки низ от вида (a+b)^2, където a
// и b са произволни малки латински букви, във файла f
// с низа (a^2+2ab+b^2). Резултатът от замяната е във файла g
void Transform(ifstream& f)
{ 
    f.seekg(0);
    ofstream g("res.txt");
    if(!g)
    { 
        cerr << "Не може да се отвори файлът res.txt!\n";
        exit(1);
    }
    int len = strlen("(a+b)^2");
    int j = 0;
    f.seekg(0, ios::end);
    long n = f.tellg(); 
    f.seekg(0); int k = 0; char ch;
    while(j < n-len+1)
    { 
        char s[8], ns[14] = ""; 
        for(int i = j; i < j+len; i++) 
        { 
            f.get(s[k]); 
            k++;
        }
        s[k] = '\0';
        if(templet(s,ns))
        { 
            g << ns;
            j += 7; f.seekg(j);
        }
        else
        { 
            f.seekg(j, ios::beg); 
            f.get(ch); g.put(ch);
            j++; 
        }
        k = 0;
    }
    while(f.get(ch)) g.put(ch);
    g.close();
}

int main()
{ 
    ifstream f("string.txt", ios::in|ios::out);
    if(!f)
    { 
        cerr << " Не може да се отвори файлът string.txt!\n";
        exit(1);
    }
    Transform(f);
    f.close();
    return 0;
}
