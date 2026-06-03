#include <iostream.h>
#include <math.h>

const int SIZEMAX = 100;

// декларация на структурата Point
struct Point
{
    double x, y;    // декартови координати на точка от равнината
};

// въвеждане на масив от точки
void read_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
    {
        cout << "x, y= ";
        cin >> P[i].x >> P[i].y; 
    }
}

// извеждане на масив от точки
void show_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
        cout << "Point(" << P[i].x << ", " << P[i].y << ")\n";
}

void sort_points(int n, Point* P)
{ 
    for(int i = 0; i < n-1; i++)
    { 
        int k = i;
        Point Min = P[i];
        for(int j = i+1; j < n; j++)
        {
            if(P[j].x < Min.x || P[j].x == Min.x && P[j].y < Min.y)
            { 
                Min = P[j];
                k = j;
            }
        }
        P[k] = P[i]; P[i] = Min;
    }
}

int main()
{
    // въвеждане на броя на точките
    int n;
    do
    {
        cout << "Въведете стойност на n – от 2 до "
             << SIZEMAX << ": ";
        cin >> n;
    } while (n < 2 || n > SIZEMAX);

    // деклариране на масив от точки в равнината
    Point P[SIZEMAX];

    // въвеждане на точките на масива
    read_points(n, P);

    // извеждане на точките на масива
    show_points(n, P);
    
    // Сортиране и повторно извеждане
    cout << endl;
    sort_points(n, P);
    show_points(n, P);

    return 0;
}
