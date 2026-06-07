#include <iostream.h>
#include <math.h>

const int SIZEMAX = 100;

// декларация на структурата Point
struct Point
{
    double x, y;    // декартови координати на точка от равнината
};

// създаване на точка от равнината
void create_point(Point& t)
{
    cout << "абсциса: "; cin >> t.x;
    cout << "ордината: "; cin >> t.y;
}

// извеждане на точка от равнината
void show_point(const Point& p)
{
    cout << "Point(" << p.x << ", " << p.y << ")\n";
}

// намиране на разстоянието между две точки от равнината
double segment(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) +
                (p2.y - p1.y)*(p2.y - p1.y));
}

// въвеждане на масив от точки
void read_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
    {
        cout << "x, y= ";
        cin >> P[i].x >> P[i].y; 
        // или create_point(P[i]);
    }
}

// извеждане на масив от точки
void show_points(int n, Point *P)
{
    for(int i = 0; i < n; i++)
        cout << "Point(" << P[i].x << ", " << P[i].y << ")\n";
    // или show_point(P[i]);
}

// намиране на най-голямото разстояние между точките
double max_distance(int n, Point *P)
{
    double max = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
        {
            double temp = segment(P[i], P[j]);
            if (temp > max) max = temp;
        }
        return max;
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

    // извеждане на най-голямото разстояние между точките
    cout << "Максималното разстояние между точките е "
         << max_distance(n, P) << endl;
    return 0;
}
