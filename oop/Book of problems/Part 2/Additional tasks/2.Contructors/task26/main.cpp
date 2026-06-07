#include <iostream>
#include "Song.cpp"
#include "Playlist.cpp"
#include "Playlists.cpp"

int main()
{
    Playlist p("Satan");
    p.add(Song("Du hast", "Rammstein", "ALBUM", 355));
    p.add(Song("Break", "Three days grace", "Tomorrow", 342));

    Playlist p2("Amino");
    p2.add(Song("Let the sparks fly", "Thousand foot krunch", "Evening", 654));

    Playlists all;
    all.add(p);
    all.add(p2);
    all.print();

    return 0;
}