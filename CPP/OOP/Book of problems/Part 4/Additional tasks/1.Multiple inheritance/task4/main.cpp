#include <iostream>
#include "Album.cpp"
#include "AlbumOrd.cpp"
#include "AlbumClassic.cpp"

int main()
{
    AlbumOrd ao1(Album("Kavali", 1978), 50);
    ao1.print();

    AlbumClassic ac1(Album("Duhoven", 1989), "Pishoman");
    ac1.print();

    

    return 0;
}