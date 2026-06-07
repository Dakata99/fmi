#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

struct Product
{ 
    char description[28];   // описание на изделие
    int partNum;            // номер на изделие
    double cost;            // цена на изделие
};

//а)
void Create(ofstream&  f)
{ 
    Product Pr = {"", 0, 0.0};
    for(int i = 0; i <= 99; i++)
        f.write(reinterpret_cast<const char *>(&Pr), sizeof(Product));
    f.close();
}

//б) 
void Modify(ofstream& f)
{ 
    cout << "Въведете номер на изделие\n"
         << "(43000 to 43099, 0 за край) > ";
    Product Pr;
    cin >> Pr.partNum;
    while(Pr.partNum >= 43000 && Pr.partNum <= 43099)
    { 
        cin.ignore();    // прескача знака за край на ред
        cout << "Въведете описание на изделие > ";
        cin.getline(Pr.description, 28);
        cout << "Въведете цена на изделие > ";
        cin >> Pr.cost;
        f.seekp((Pr.partNum - 43000)*sizeof(Product));
        f.write(reinterpret_cast<const char *>(&Pr), sizeof(Product));
        cout << "Въведете номер на изделие > ";
        cin >> Pr.partNum;
    }
    f.close();
}

//в)
void OutLine(ostream &f, const Product &c)
{
    f << setiosflags(ios::left) << setw(35) << c.description
      << setw(10) << c.partNum << setw(10) << setprecision(2)
      << resetiosflags(ios::left)
      << setiosflags(ios::fixed|ios::showpoint)
      << c.cost << endl;
}

void WriteFile(fstream& f)
{
    cout << "Извеждане:\n";
    cout << setiosflags(ios::left) << setw(35)
         << "Описание на изделие"
         << setw(10) << "Номер"
         << resetiosflags(ios::left) << setw(10)
         << "Цена" << endl;
    Product Pr;
    f.read(reinterpret_cast<char*>(&Pr), sizeof(Product));
    while(f.good())
    {
        if(Pr.partNum != 0)
            OutLine(cout, Pr);
        f.read(reinterpret_cast<char *>(&Pr), sizeof(Product));
    }
    f.close();
}

//г)
void Update(fstream &f)
{
    cout << "Актуализиране:\n";
    cout << "Номер на изделие: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum != 0)
    {
        OutLine(cout, Pr);
        cout << "\n Нова цена: ";
        cin >> Pr.cost;
        OutLine(cout, Pr);
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char*)(&Pr), sizeof(Product));
    }
    else
    {
        cerr << "За номер # " << n << " няма информация." << endl;
    }
    f.close();
}

//д)
void Insert(fstream& f)
{
    cout << "Включване:\n";
    cout << "Номер на изделие: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum == 0)
    {
        Pr.partNum = n;
        cout << "Въведете описание на изделие > ";
        cin.ignore();
        cin.getline(Pr.description, 28);
        cout << "Въведете цена на изделие > ";
        cin >> Pr.cost;
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char *)(&Pr), sizeof(Product));
    }
    else
    {
        cerr << "Изделие с номер # " << n << " вече съдържа информация.\n";
    }
    f.close();
}

//е)
void Delete(fstream& f)
{
    cout << "Изтриване:\n";
    cout << "Номер на изделие: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum != 0 )
    {
        Product blank = {"", 0, 0.0};
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char*)(&blank), sizeof(Product));
        cout << "Изделие с номер # " << n << " е изтрито." << endl;
    }
    else
    {
        cerr << "Изделие с номер # " << n << "е празно." << endl;
    }
    f.close();
}

int getRequest()
{
    cout << "\nВъведете номер на заявка\n"
         << "1 - за извеждане на файл\n"
         << "2 - за актуализиране на файл\n"
         << "3 - за включване на нова компонента\n"
         << "4 - за изтриване на компонента\n"
         << "5 - за край\n";
    int req;
    do
    { 
        cout << "Заявка (1 - 5): ";
        cin >> req;
    }while(req < 1 || req > 5);
    return req;
}

int main()
{
    ofstream f1("Products.dat", ios::out);
    if(!f1)
    {
        cerr << "Файлът не може да бъде отворен!\n";
        return 1;
    }
    Create(f1);
    f1.open("Products.dat", ios::ate|ios::nocreate);
    if(!f1)
    {
        cerr << "Файлът не може да бъде отворен!\n";
        return 1;
    }
    Modify(f1);
    fstream f;
    int request;
    while((request = getRequest()) != 5)
    {
        f.open("Products.dat", ios::in|ios::out|ios::nocreate);
        if(!f)
        {
            cerr << "Файлът не може да бъде отворен!\n";
            return 1;
        }
        switch(request)
        {
        case 1: WriteFile(f); break;
        case 2: Update(f); break;
        case 3: Insert(f); break; 
        case 4: Delete(f);
        }
        f.clear();
    }
    return 0;
}
