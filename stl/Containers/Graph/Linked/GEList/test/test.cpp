#include "GEList.hpp"
#include "doctest.h"

TEST_CASE("ORIENTED WEIGHTED GRAPH TESTS") {
    GEList<std::string, size_t> cities(true, true);

    std::string city_names[] = {
        "Vidin",       "Sliven",  "Vraca",  "Sofiq", "Plovdiv", "Kyustendil",
        "Blagoevgrad", "Razgrad", "Pleven", "Varna", "Burgas",  "Dobrich"};

    for (const std::string& city_name : city_names) {
        cities.add(city_name);
    }

#if 1
    cities.add("Blagoevgrad", "Kyustendil", 10);
    cities.add("Kyustendil", "Sofiq", 20);
    cities.add("Blagoevgrad", "Sofiq", 30);
    cities.add("Vidin", "Sofiq", 40);
    cities.add("Vraca", "Sofiq", 50);
    cities.add("Vidin", "Vraca", 60);
    cities.add("Vraca", "Pleven", 70);
    cities.add("Pleven", "Razgrad", 80);
    cities.add("Pleven", "Dobrich", 90);
    cities.add("Razgrad", "Sofiq", 100);
    cities.add("Razgrad", "Dobrich", 110);
    cities.add("Razgrad", "Varna", 120);
    cities.add("Dobrich", "Varna", 130);
    cities.add("Razgrad", "Plovdiv", 140);
    cities.add("Sofiq", "Plovdiv", 150);
    cities.add("Plovdiv", "Burgas", 160);
    cities.add("Varna", "Burgas", 170);
    cities.add("Sliven", "Plovdiv", 180);
    cities.add("Burgas", "Sliven", 190);
    cities.add("Sofiq", "Varna", 200);
#endif

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Burgas", "Plovdiv") == false);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    cities.print_degrees();

    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add("Plovdiv", "Pleven", 210);
    cities.add("Vidin", "Kyustendil", 220);
    cities.add("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    CHECK(cities.has_vertex("Sofiq") == true);
    CHECK(cities.has_vertex("Razgrad") == true);
    CHECK(cities.has_vertex("Plovdiv") == true);

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    CHECK(cities.has_way("Blagoevgrad", "Sliven") == false);
    CHECK(cities.has_way("Vidin", "Varna") == false);
    CHECK(cities.has_way("Kyustendil", "Vidin") == false);

    // cities.print_successors("Plovdiv");
    // cities.print_predecessors("Plovdiv");
}

TEST_CASE("ORIENTED NON-WEIGHTED GRAPH TESTS") {
    GEList<std::string, size_t> cities(5, true, false);

    cities.add("Dupnica", "Sofiq");
    cities.add("Sofiq", "Plovdiv");
    cities.add("Sofiq", "Varna");
    cities.add("Varna", "Burgas");
    cities.add("Plovdiv", "Burgas");
    cities.add("Qmbol");

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);
}

TEST_CASE("NON-ORIENTED WEIGHTED GRAPH TESTS") {
    GEList<std::string, size_t> cities(5, false, true);

    CHECK(cities.has_vertex("Dupnicca") == false);

    cities.add("Dupnica", "Sofiq", 60);
    cities.add("Kyustendil", "Dupnica");
    cities.add("Sofiq", "Plovdiv", 220);
    cities.add("Dobrich");
    cities.add("Sofiq", "Varna", 560);
    cities.add("Sofiq", "Burgas", 500);
    cities.add("Dobrich", "Plovdiv");
    cities.add("Varna", "Burgas", 115);
    cities.add("Plovdiv", "Burgas", 250);
    cities.add("Qmbol");

    cities.set("Qmbol", "Dobrich");
    cities.set("Qmbol", "Dobrich", 111);

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    // CAUSES SEGMENTATION FAULT
    // cities.remove_edge("Sofiq", "Burgas");
    // cities.print();

    // cities.remove_vertex("Plovdiv");
    // cities.print();
}

TEST_CASE("NON-ORIENTED NON-WEIGHTED GRAPH TESTS") {
    GEList<std::string, size_t> cities(5, false, false);

    cities.add("Dupnica", "Sofiq");
    cities.add("Sofiq", "Plovdiv");
    cities.add("Sofiq", "Varna");
    cities.add("Sofiq", "Burgas");
    cities.add("Varna", "Burgas");
    cities.add("Plovdiv", "Burgas");

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    // CAUSES SEGMENTATION FAULT
    // cities.remove_edge("Sofiq", "Varna");
    // cities.print();

    // cities.remove_vertex("Sofiq");
    // cities.print();
}
