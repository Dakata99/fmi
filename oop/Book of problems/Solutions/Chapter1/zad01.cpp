#include <iostream.h>
#include <iomanip.h>

struct Product
{ 
    char description[32];	// описание на изделие
    int partNum;			// номер на изделие
    double cost;			// цена на изделие
};

int main()
{
    ////а) 
    Product p1 = {"screw-driver", 456, 5.50},
            p2 = {"hammer", 324, 8.20};

    ////б) 
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << setw(35) << p1.description 
         << setw(15) << p1.partNum
         << setw(20) << p1.cost << endl;
    cout << setw(35) << p2.description 
         << setw(15) << p2.partNum
         << setw(20) << p2.cost << endl;
    ////в)
    Product P[10];

    ////г)
    int i;
    for(i = 0; i < 10; i++)
    {
        strcpy(P[i].description, "");
        P[i].partNum = 0;
        P[i].cost = 0.0;
    }

    ////д)
    Product Q[5] = {{"screw-driver", 456, 5.50},
                    {"hammer", 324, 8.20},
                    {"socket", 458, 5.75},
                    {"plier", 929, 10.50},
                    {"hand-saw", 536, 7.45}};

    ////е) 
    for(i = 0; i < 5; i++)
        cout << setw(35) << Q[i].description
             << setw(15) << Q[i].partNum
             << setw(20) << Q[i].cost << endl;
    return 0;
}
