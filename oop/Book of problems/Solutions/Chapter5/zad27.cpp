#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

struct PersonalData
{ 
    bool read(istream &in)
    {
        // очакван формат
        // факултетен номер (цяло число)
        // име (до 199 символа)
        return (in >> fn) && in.getline(name,199);
    }
    int fn;                // факултетен номер
    char name[200];        // име
};

struct ExamData
{
    bool read(istream &in)
    {
        // очакван формат
        // факултетен номер (цяло число)
        // оценка (double)
        // предмет (до 199 символа)
        return in >> fn && in >> mark &&
            in.getline(subject, 199);
    }

    int fn;                // факултетен номер
    double mark;           // оценка
    char subject[200];     // предмет
};

struct CombinedExamData
{
    // конструира комбинираните данни като копира
    // данните от PersonalData и ExamData обекти
    CombinedExamData(const PersonalData& _personalData,
        const ExamData& _examData)
    {
        personalData = _personalData;
        strcpy(personalData.name, _personalData.name);
        examData = _examData;
        strcpy(examData.subject, _examData.subject);
        count = 1;
    }

    PersonalData personalData;
    ExamData examData;
    // от колко изпита са натрупаните оценки
    int count;
};

// помощна функция
// Претърсва масива dataArray за данни за оценка
// на даден студент по даден предмет. Ако такива
// данни са намерени, data.examData.mark се
// добавя към съществуващата оценка и броячът на
// CombinedData се увеличава. В противен случай се
// добавя нов елемент към масива с данните
void addEntry(CombinedExamData *dataArray[],
              const PersonalData& personalData,
              const ExamData& examData,
              int& count)
{
    int i = 0;
    // търсене на данни за дадения студент по дадения предмет
    while(i < count &&
         (strcmp(dataArray[i]->personalData.name, personalData.name) != 0 ||
          strcmp(dataArray[i]->examData.subject, examData.subject) != 0))
        i++;

    // намерен ли е такъв запис?
    if(i < count)
    {
        dataArray[i]->examData.mark += examData.mark;
        dataArray[i]->count++;
    }
    else
    {
        dataArray[count] = new CombinedExamData(personalData, examData);
        count++;
    }
}

void printResults(CombinedExamData *dataArray[], int count)
{
    cout << setiosflags(ios::left);
    for(int i = 0; i < count; i++)
        cout << setw(5) << dataArray[i]->personalData.fn 
             << setw(40) << dataArray[i]->examData.subject
             << setprecision(2) << setw(5) 
             << dataArray[i]->examData.mark / dataArray[i]->count
             << endl;
}

void readUnsorted()
{
    ifstream personalDataFile("personal.txt");
    // масив, в който се натрупват резултати
    CombinedExamData *combined[500];
    // брой събрани резултати
    int count = 0;
    PersonalData personalData;
    ExamData examData;
    while(personalDataFile && personalData.read(personalDataFile))
    {
        ifstream examDataFile("exams.txt");
        // търсят се данни за всички изпити, издържани от дадения студент
        while(examDataFile && examData.read(examDataFile))
            if(examData.fn == personalData.fn)
                addEntry(combined, personalData, examData, count);
    }
    printResults(combined, count);
    for(int i = 0; i < count; i++)
        delete combined[i];
}

int main()
{
    readUnsorted();
    return 0;
}
