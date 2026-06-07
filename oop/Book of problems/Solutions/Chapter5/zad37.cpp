#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <ctype.h>      // isspace, isdigit
#include <string.h>

// Брой на променливите
const int VAR_CNT = 'z'-'a'+1;

// Максимална дължина на един ред
const int MAX_LINE_LENGTH = 1024;

// Състояния, в които може да се намира програмата
enum State
{
    Before,   // извън програма (очаква се PROGRAM команда)
    In,       // в програма (PROGRAM - END. блок)
    Error     // състояние на грешка
};

// Кодове на команди
enum Command
{
    PROGRAM,
    ADD, SUB, MUL, MOV,
    END
};

State    state;                         // състояние на програма
char     program[MAX_LINE_LENGTH];      // име на програма
int      vars[VAR_CNT];                 // стойности на променливи
bool     defined[VAR_CNT];              // дали променлива е дефинирана
ifstream file;                          // файл, от който се чете

// Прескача празните позиции в началото на низ
void ignore_spaces(char*& line)
{
    while(*line && isspace(*line)) ++line;
}

// Прочита кода на команда от началото на низ
bool read_command(Command& cmd, char*& line)
{
    ignore_spaces(line);
    switch(*line)
    {
    case 'P':
        if(!strncmp(line, "PROGRAM", 7))
        {
            line += 7;
            cmd = PROGRAM;
            return true;
        }
        return false;
    case 'A':
        if(!strncmp(line, "ADD", 3))
        {
            line += 3;
            cmd = ADD;
            return true;
        }
        return false;
    case 'S':
        if(!strncmp(line, "SUB", 3))
        {
            line += 3;
            cmd = SUB;
            return true;
        }
        return false;
    case 'M':
        if(!strncmp(line, "MUL", 3))
        {
            line += 3;
            cmd = MUL;
            return true;
        }
        if(!strncmp(line, "MOV", 3))
        {
            line += 3;
            cmd = MOV;
            return true;
        }
        return false;
    case 'E':
        if(!strncmp(line, "END.", 4))
        { 
            line += 4;
            cmd = END;
            return true;
        }
        return false;
    }
    return false;
}

// Прочита едно цяло число, евентуално със знак -
bool read_num(int& b, char*& line)
{ 
    bool neg = false;
    if(*line == '-')
    {
        neg = true;
        ++line;
    }
    ignore_spaces(line);
    if(!isdigit(*line)) 
        return false;
    b = 0;
    while(isdigit(*line))
    {
        b = b * 10 + *line - '0';
        ++line;
    }
    if(neg) b = -b;
    return true;
}

// Прочита аргументите на една команда,
// и прави проверки за коректност
bool read_args(char& a, int& b, bool& use_value, char*& line)
{ 
    ignore_spaces(line);
    if(*line != '(') 
        return false;
    ++line;

    ignore_spaces(line);
    if(*line < 'a' || *line > 'z') 
        return false;
    a = *line;
    ++line;

    ignore_spaces(line);
    if(*line != ',') 
        return false;
    ++line;

    ignore_spaces(line);
    if(*line < 'a' || *line > 'z')
    { 
        if(read_num(b, line))
            use_value = true;
        else 
            return false;
    }
    else
    { 
        use_value = false;
        b = *line;
        ++line;
    }

    ignore_spaces(line);
    if(*line != ')') 
        return false;
    ++line;

    ignore_spaces(line);
    return !*line;
}

// Прочита името на програма
bool read_name(char* line)
{ 
    if(!isspace(*line)) 
        return false;

    ignore_spaces(line);
    if(*line)
    {
        strcpy(program, line);
        return true;
    }
    return false;
}

// Извежда стойностите на дефинираните променливи
void print_result()
{ 
    cout << program << endl;
    for(int i = 0; i < VAR_CNT; ++i)
    {
        if(defined[i])
        {
            cout << (char)(i+'a') << " = " << vars[i] << '\n';
        }
    }
    cout << endl;
}

// Извежда съобщение за грешка
void error()
{ 
    cout << "Грешка\n" << endl;
    state = Error;
}

// Извършва действия по започване на програма
// (навлизане в блок PROGRAM END.)
void start_program()
{ 
    state = In;
    for(int i = 0; i < VAR_CNT; ++i)
    { 
        vars[i] = 0;
        defined[i] = 0;
    }
}

// Извършва действията по една изчислителна команда
bool make_calc(Command cmd, char*& line)
{
    char a;
    int b;
    bool use_val;
    if(!read_args(a, b, use_val, line))
        return false;

    if(!use_val)
    { 
        if(!defined[b-'a'])
        {
            return false;
        }
        b = vars[b-'a'];
    }

    if(cmd != MOV && !defined[a-'a'])
        return false;

    switch(cmd)
    { 
    case MOV:
        defined[a-'a'] = true;
        vars[a-'a'] = b;
        break;
    case ADD:
        vars[a-'a'] += b;
        break;
    case SUB:
        vars[a-'a'] -= b;
        break;
    case MUL:
        vars[a-'a'] *= b;
        break;
    }
    return true;
}

// Действия по край на програма
void end_program()
{ 
    if(state == In)
    {
        print_result();
    }
    if(state == Before)
    {
        error();
    }
    state = Before;
}

// Изпълнява един програмен ред
void exec_command(char* line)
{ 
    ignore_spaces(line);
    if(!*line) return;

    Command cmd;
    if(!read_command(cmd, line))
    {
        error();
        return;
    }

    switch(cmd)
    { 
    case PROGRAM:
        if(state == In)
        { 
            error(); 
            return;
        }
        if(!read_name(line))
        { 
            error(); 
            return;
        }
        start_program();
        break;
    case ADD:
    case MUL:
    case SUB:
    case MOV:
        if(state == Error) 
        {
            return;
        }
        if(state != In)
        { 
            error(); 
            return;
        }
        if(!make_calc(cmd, line))
        { 
            error(); 
            return;
        }
        break;
    case END:
        end_program();
        break;
    }
}

// Подготвя програмата за работа
void init()
{ 
    static const int MAX_NAME_LENGTH = 256;
    char file_name[MAX_NAME_LENGTH];

    // Прочита името на входния файл
    cout << "Въведете име на входния файл: ";
    cin.getline(file_name, MAX_NAME_LENGTH);
    file.open(file_name);
    if(!file)
    { 
        cerr << "Не може да се отвори " << file_name << '\n';
        exit(1);
    }
    state = Before;
}

// Действия в края на програмата
void finalize()
{ 
    if(state != Before)
    {
        error();
    }
    file.close();
}

int main()
{ 
    char line[MAX_LINE_LENGTH];

    init();
    while(file.getline(line, MAX_LINE_LENGTH))
        exec_command(line);
    finalize();

    return 0;
}
