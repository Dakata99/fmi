#include <iostream.h>
#include <iomanip.h>

// Помощна функция, която преобразува символ, представящ
// шестнадесетична цифра, в съответното му число
unsigned int char_to_digit(char ch)
{
    if(ch >= '0' && ch <= '9')
        return ch - '0';
    if(ch >='a' && ch <= 'f')
        return 10 + ch - 'a';
    if(ch >='A' && ch <= 'F')
        return 10 + ch - 'A';
    return (unsigned int)(-1);
}

// Функция, прочитаща от даден поток число,
// записано в указана бройна система
unsigned int get_number(istream& stream, unsigned int base)
{
    char ch;
    unsigned int digit = 0;
    unsigned int number = 0;
    while(digit < base)
    {
        number = number * base + digit;
        ch = stream.get();
        digit = char_to_digit(ch);
    }
    return number;
}

// Функция, която разпознава бройната система,
// в която е записано числото на текущата позиция на даден входен поток
// Разпознаването се основава на първия един или първите два символа от потока.
// Ако числото започва с цифра, различна от 0, то е в десетична система,
// ако започва с 0x е в шестнадесетична, а ако започва само с 0 е в осмична система.
int detect_base(istream& stream)
{
    char ch = stream.get();
    if(ch == '0')
    {
        ch = stream.get();
        if(ch == 'x' || ch == 'X')
        {
            ch = stream.get();
            stream.putback(ch);
            if((ch >= '0'&&ch <= '9')||
                (ch >= 'a'&&ch <= 'f')||
                (ch >= 'A'&&ch <= 'F'))
                return 16;
            else return -1;
        }
        else
        {
            stream.putback(ch);
            // Ако следващият символ не е осмична цифра се приема, че числото е 0
            return 8;
        }
    }
    else
    {
        stream.putback(ch);
        if(ch >= '0' && ch <= '9')
            return 10;
        else
            return -1;
    }
}

// Извежда дадено число в поток в бройна система, различна от дадената
void print_number(ostream& stream, unsigned int number, int base)
{
    if(base != 8)
    { 
        stream << setiosflags(ios::showbase) << oct 
               << number << endl;
    }
    if(base != 10)
    { 
        stream << dec << number << endl;
    }
    if(base != 16)
    { 
        stream << setiosflags(ios::showbase) << hex 
               << number << endl;
    }
    stream << dec;
}

int main()
{ 
    // Разпознава в каква бройна система е число
    int base = detect_base(cin);
    if(base < 0)
    {
        cerr << "Невалидно число!\n";
        return 1;
    }
    // Чете число
    unsigned int number = get_number(cin, base);
    // Извежда числото в останалите бройни ситеми
    print_number(cout, number, base);
    return 0;
}
