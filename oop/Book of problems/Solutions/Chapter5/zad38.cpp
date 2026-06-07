#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <assert.h>     // assert
#include <stdlib.h>     // exit
#include <stdio.h>      // unlink, rename
#include <ctype.h>      // isspace

// име на текстовия файл, в който се записва информацията
const char * EXPORT_FILE_NAME = "print.txt";

// име на временния файл, използван при изтриване на запис
const char * TEMP_FILE_NAME = "temp_student.dat";

// максимална дължина на име на файл
const int MAX_PATH_SIZE = 256;

// максимална дължина на име на студент
const int MAX_NAME_LENGTH = 32;

// минимална и максимална стойност на факултетен номер
const int MIN_FN = 42900;
const int MAX_FN = 45150;

// структура, съхраняваща информация за студент
struct student_info
{
    int     fn;                     // факултетен номер
    char    name[MAX_NAME_LENGTH];  // име
    float   grade;                  // среден успех
};

// указател към функция, която се извиква от менюто
typedef int(*cmd_function)(fstream&, const char file_name[]);

// прототипи на включените в менюто функции
int insert (fstream&, const char file_name[]);
int remove (fstream&, const char file_name[]);
int update (fstream&, const char file_name[]);
int print  (fstream&, const char file_name[]);
int save   (fstream&, const char file_name[]);
int search (fstream&, const char file_name[]);
int quit   (fstream&, const char file_name[]);

// структура, описваща команда от менюто
struct command
{
    char         key;        // символ, с който потребителят  избира команда
    const char * name;       // име на команда, изписвано в менюто
    cmd_function function;   // указател към функция, която изпълнява командата
} commands[] = {             // масив от поддържаните команди
    {'i', "Вмъкване",      insert},
    {'r', "Изтриване",     remove},
    {'u', "Актуализиране", update},
    {'p', "Извеждане",     print},
    {'s', "Запазване",     save},
    {'f', "Търсене",       search},
    {'q', "Завършване",    quit},
    {0, NULL, NULL}};        // завършва с 'нулев' запис

    // Следват някои помощни функции //

// функция за проверка на факултетен номер
int validate_fn(int fn)
{ 
    return fn >= MIN_FN && fn <= MAX_FN;
}

// функция за проверка на успех
int validate_grade(float grade)
{ 
    return grade >= 2.0 && grade <= 6.0;
}

// функция за намиране на общия брой записи във файл
int get_count(fstream& file)
{ 
    long int offset;
    file.clear();
    if(!file.seekg(0, ios::end))    // позициониране в края на файла
    { 
        return -1;
    }
    offset = file.tellg();          // вземане на позицията – размера на файла

    // подсигуряване файлът да е коректен
    // Функцията assert прекратява програмата,
    // ако условието-аргумент не е истина.
    // Това се случва само в Debug режим и
    // такива проверки не забавят изпълнението
    // на крайната програма.
    assert(offset % sizeof(student_info) == 0);
    // пресмятане броя на записите
    return offset / sizeof(student_info);
}

// функция, прочитаща данните на определена позиция
int read_at(fstream& file, student_info& info, int pos)
{ 
    file.clear();
    file.seekg(pos * sizeof(info));
    return !file.read((char*)&info, sizeof(info));
}

// Търси индекса на запис с определен факултетен номер.
// Ако запис с такъв номер не е намерен, връща индекса
// на първия елемент с по-голям номер.
// Използва алгоритъма за двоично търсене
long int seek_fn(fstream& file, int fn, long int count)
{ 
    student_info info;
    long int  start = 0,
              end   = count;
    long int  middle;
    while(start < end)
    { 
        middle = (start + end) / 2;
        if(read_at(file, info, middle))
        {  
            cout << "Пропада четенето на елемент!" << endl;
            return -1;
        }
        if(info.fn == fn)
        {
            return middle;
        }
        else if(info.fn > fn)
        {
            end = middle;
        }
        else
        {
            start = middle+1;
        }
    }
    return start;
}

// Премества записите от определено място до края на
// файла с една позиция напред. Така се освобождава
// място за вмъкване на нов запис.
// В тази реализация копирането става запис по запис.
// С цел по-голяма ефективност би могло да се реализира
// копиране на блокове с по-голям размер.
int shift_out(long int start, long int count, fstream& file)
{
    student_info info;
    file.clear();
    for(int pos = count-1; pos >= start; --pos)
    {
        file.seekg(pos*sizeof(info));
        file.read((char*)&info, sizeof(info));
        file.seekp((pos+1)*sizeof(info));
        file.write((char*)&info, sizeof(info));
        if(!file) return 1;
    }
    return 0;
}

// Изтрива запис с определен индекс от файл.
// Изтриването става като записите, без този който трябва
// да бъде изтрит, се копират в нов – временен файл и след това
// първоначалният файл се изтрива с помощта на функцията
// unlink, а временният се применува (чрез функцията rename).
// Съществува следният проблем – ако двата файла се намират
// на различни дискове, тази операция няма да успее. За
// справяне с него е възможно името на временния файл да се
// получава от името на файла с данни като се добави .tmp
// накрая, например.
int remove_from_file(long int index, fstream& file,
                     const char file_name[MAX_NAME_LENGTH])
{
    // Всички записи без един се копират в този временен файл
    ofstream tmp(TEMP_FILE_NAME, ios::binary|ios::out|ios::trunc);
    if(!tmp)
    {
        cout << "Пропада отварянето на файла!" << endl;
        return 1;
    }
    int pos = 0;
    student_info info;
    file.clear();
    file.seekg(0);

    while(file.read((char*)&info, sizeof(info)))
    { 
        if(pos != index)
        { 
            tmp.write((char*)&info, sizeof(info));
            if(!tmp)
            { 
                cout << "Неуспешно записване на данни във временния файл";
                tmp.close();
                unlink(TEMP_FILE_NAME);
                return 1;
            }
        }
        ++pos;
    }

    file.clear();
    file.close();
    unlink(file_name);                  // изтриване на оригиналния файл
    tmp.close();
    rename(TEMP_FILE_NAME, file_name);  // и преименуване на временния файл

    file.open(file_name, ios::in|ios::out|ios::binary);
    if(!file)
    { 
        cout << "Неуспешно отваряне на файла."
             << file_name << endl;
        return 1;
    }
    return 0;
}

// функция, която прескача всички празни символи в началото на поток
void ignore_spaces(istream& in)
{
    char ch;
    do
    { 
        ch = in.get();
    }while(in  && isspace(ch));
    in.putback(ch);
}

// оператор за изход на данни за студент
ostream& operator<<(ostream& out, const student_info& info)
{ 
    out  << setw(MAX_NAME_LENGTH-1) << setiosflags(ios::left)
         << info.name << " |" << resetiosflags(ios::left)
         << setw(7) << info.fn << " |"
         << setw(6) << setprecision(2) 
         << info.grade << endl;
    return out;
}

// оператор за вход на данни за студент
istream& operator>>(istream& in, student_info& info)
{ 
    ignore_spaces(in);
    in.getline(info.name, MAX_NAME_LENGTH, ' ');
    in >> info.fn;
    in >> info.grade;
    return in;
}

    // Функции, реализиращи предложените команди //

// Команда за край на работата
// Основната й задача е да върне резултат, указващ
// край на работата със системата.
int quit(fstream& file, const char file_name[])
{ 
    file.close();
    return 1;
}

// Команда за вмъкване на елемент във файл
int insert(fstream& file, const char file_name[])
{ 
    // Четене на информацията за нов студент
    student_info info;
    cout << "Въведете информация за студент: " << endl;
    cout << "Фамилия, номер и оценка: ";
    cin >> info;
    while(!cin || !validate_fn(info.fn) ||
          !validate_grade(info.grade))
    {
        cout << "Грешни данни! Въведете информацията отново!";
        cin.clear();
        cin >> info;
    }

    long int count = get_count(file);
    if(count < 0)
    { 
        cout << "Неуспех при вземане на броя записи!" << endl;
        return count;
    }

    // Намиране на мястото, на което трябва да се реализира вмъкването
    long int index = seek_fn(file, info.fn, count);
    if(index < 0)
    {
        cout << "Неуспех при търсене на студент!" << endl;
        return index;       // Прекратява работата на програмата
    }

    if(index >= count)      // Вмъкване в края на файла
    { 
        file.seekp(0, ios::end);
        if(!file.write((char*)&info, sizeof(info)))
        { 
            cout << "Неуспешно записване на данните!" << endl;
            return 1;
        }
        return 0;
    }

    // Ако няма да се вмъква в края на файла, се търси
    // елементът върху когото трябва да се вмъква
    student_info tmp_info = {0, };
    if(read_at(file, tmp_info, index))
    { 
        cout << "Не може да прочете данни за студента!" << endl;
        return 1;
    }

    // Ако записът е със същия номер, следва актуализиране на данните
    if(tmp_info.fn == info.fn)
    { 
        cout << "Студент с такъв номер вече съществува."
                " Данните ще бъдат променени." << endl;
    }
    else
    { 
        // преместване на записите до края за да се освободи място
        if(shift_out(index, count, file))
        {
            cout << "Преместването е неуспешно!" << endl;
            return 1;
        }
    }

    // и в двата случая на намерената позиция се 
    // записват данните от новия запис
    file.seekp(index*sizeof(info));
    if(!file.write((char*)&info, sizeof(info)))
    { 
        cout << "Неуспешно записване на данни!" << endl;
        return 1;
    }
    return 0;
}

// Команда за изтриване на запис за студент
int remove(fstream& file, const char file_name[])
{ 
    // прочитане на номера на студента, който ще се изтрива
    int fn;
    cout << "Номер на студент за изтриване: ";
    cin >> fn;
    if(!validate_fn(fn))
    { 
        cout << fn << " не е валиден номер!" << endl;
        return 0;
    }

    // търсене на позицията, на която се намира
    long int count = get_count(file);
    long int index = seek_fn(file, fn, count);
    if(index < 0)
    { 
        cout << "Неуспешно търсене на студент!" << endl;
        return index;
    }

    // ако номерът е по-голям от всички
    if(index > count) 
    { 
        cout << "Няма студент с този номер!" << endl;
        return 0;
    }
    student_info info;
    if(read_at(file, info, index))
    { 
        cout << "Четенето на данните е неуспешно!" << endl;
        return 1;
    }

    if(info.fn != fn)     // ако няма такъв номер
    { 
        cout << "Няма студент с този номер!" << endl;
        return 0;
    }

    // изискване на потвърждение за изтриване
    cout << "Изтриване на студент:" << endl;
    cout << info;
    cout << "<y/n>";
    char ans;
    cin >> ans;
    if(ans != 'y' && ans != 'Y')
    { 
        return 0;
    }

    // и извършване на самото изтриване
    if(remove_from_file(index, file, file_name))
    { 
        cout << "Изтриването на данните е неуспешно!" << endl;
        return 1;
    }
    return 0;
}

// Команда за търсене на всички студенти с определен успех
int search(fstream& file, const char file_name[])
{ 
    float grade;
    cout << "Оценка за търсене: ";
    cin >> grade;
    if(!validate_grade(grade))
    { 
        cout << setprecision(2) << grade
             << " не е валидна оценка!" << endl;
        return 0;
    }
    file.clear();
    file.seekg(0);

    student_info info;
    bool found = false;
    while(file.read((char*)&info, sizeof(info)))
    { 
        if(info.grade == grade)
        { 
            cout << "Информация за студента: " << endl;
            cout << info;
            found = true;
        }
    }

    if(!found)
    { 
        cout << "Не е намерен студент с такава оценка!" << endl;
    }
    return 0;
}

// Команда за променяне успеха на студент с определен номер
int update(fstream& file, const char file_name[])
{ 
    int fn;
    float new_grade;
    cout << "Номер на студент за промяна: ";
    cin >> fn;
    if(!validate_fn(fn))
    { 
        cout << fn << " не е валиден номер!" << endl;
        return 0;
    }
    long int count = get_count(file);
    long int index = seek_fn(file, fn, count);
    if(index < 0)
    { 
        cout << "Неуспешно търсене на студент!" << endl;
        return index;      // Прекратява изпълнението на програмата
    }

    if(index > count)
    {
        cout << "Няма студент с такъв номер!" << endl;
        return 0;
    }

    student_info info;
    if(read_at(file, info, index))
    { 
        cout << "Неуспешно четене на данни!" << endl;
        return 1;
    }

    if(info.fn != fn)
    { 
        cout << "Няма студент с такъв номер!" << endl;
        return 0;
    }

    // Извеждане на старите данни и изискване за въвеждане на нов успех
    cout << "Данни за студента: " << endl;
    cout << info;
    cout << "Нова оценка : ";
    cin >> new_grade;
    if(!validate_grade(new_grade))
    { 
        cout << new_grade << " не е валидна оценка!" << endl;
        return 0;
    }

    // Записване новите данни върху старите
    info.grade = new_grade;
    file.seekp(index * sizeof(student_info));
    if(!file.write((char*)&info, sizeof(info)))
    { 
        cout << "Неуспешен запис на данните!" << endl;
        return 1;
    }
    return 0;
}

// Команда за извеждане на екрана на всички записи
int print(fstream& file, const char file_name[])
{
    student_info info;
    file.clear();
    file.seekg(0);
    // извеждане на заглавен ред
    cout << setw(MAX_NAME_LENGTH) << setiosflags(ios::left)
         << "Име" << '|' << resetiosflags(ios::left)
         << setw(8) << "Номер" << '|'
         << setw(7) << "Оценка" << endl;
    // и на записите под него
    while(file.read((char*)&info, sizeof(info)))
        cout << info;
    return 0;
}

// Команда за записване на данните в текстов файл
int save(fstream& file, const char file_name[])
{ 
    student_info info;
    ofstream output(EXPORT_FILE_NAME);
    if(!output)
    { 
        cout << "Не може да се отвори " << EXPORT_FILE_NAME;
        return 1;
    }
    // извеждане на заглавен ред
    output << setw(MAX_NAME_LENGTH) << setiosflags(ios::left)
           << "Име" << '|' << resetiosflags(ios::left)
           << setw(8) << "Номер" << '|'
           << setw(7) << "Оценка" << endl;
    file.clear();
    file.seekg(0);

    // и на данните
    while(file.read((char*)&info, sizeof(info)))
    { 
        if(!(output << info))
        { 
            cout << "Записът в текстов файл е неуспешен!" << endl;
            output.close();
            return 1;
        }
    }
    output.close();
    cout << "Информацията е записана в " << EXPORT_FILE_NAME << endl;
    return 0;
}

    // Функции за реализиране на менюто с команди //

// Функция, извеждаща списък на командите
void print_menu()
{ 
    cout << "\t\t МЕНЮ\n";
    // За всеки запис от масива с команди
    for(int i = 0; commands[i].name; ++i)
    {
        cout << commands[i].key << " : "    // извеждане на символа
             << commands[i].name << "\n";   // и името на команда
    }
}

// Функция, четяща избора на потребителя
int read_command()
{ 
    char key = -1;
    // Чете символ
    cin >> key;
    if(!cin) return 1;
    // и търси за коя команда е той
    for(int i = 0; commands[i].name; ++i)
    {
        if(commands[i].key == key)
            return i;
    }
    // ако не е намерена такава команда
    cout << "Непозната команда!" << endl;
    return -1;
}

// Предизвиква изпълнението на команда с
// определен индекс в масива от команди.
// Предава на командите името и файла с данни.
int execute_command(int command, fstream& file,
                    const char file_name[])
{ 
    if(command >= 0 && commands[command].function)
    {
        return commands[command].function(file, file_name);
    }
    return 0;
}

// функция за начално инициализиране
void initialize(fstream& file, char file_name[MAX_PATH_SIZE])
{ 
    // четене на името на файла с данни
    cout << "Име на входния файл: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    // и отваряне
    file.open(file_name, ios::in|ios::out|ios::binary);
    if(!file)  // Ако файлът не съществува го създава
    {
        file.open(file_name, ios::in|ios::out|ios::binary|ios::trunc);
    }
}

int main()
{ 
    char file_name[MAX_PATH_SIZE];
    fstream file;

    // инициализиране на програмата
    initialize(file, file_name);
    int command, result = 0;

    // изпълняване в цикъл на команди
    do
    { 
        print_menu();
        command = read_command();
        if(command < 0) continue;
        result = execute_command(command, file, file_name);
    } while(result == 0);    // докато изпълнението им е успешно.

    // Използването на exit в края на main се препоръчва
    // за предпазване от евентуално рекурсивно извикване
    exit(EXIT_SUCCESS);
    return 0;
}
