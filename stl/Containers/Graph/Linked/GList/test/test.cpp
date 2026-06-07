#include "GList.hpp"
#include "doctest.h"

std::string city_names[] = {"Vidin",   "Sliven",     "Vraca",       "Sofiq",
                            "Plovdiv", "Kyustendil", "Blagoevgrad", "Razgrad",
                            "Pleven",  "Varna",      "Burgas",      "Dobrich"};

TEST_CASE("Oriented weighted graph tests") {
    GList<std::string, size_t> cities(true, true);

    for (const std::string& city_name : city_names) {
        cities.add_vertex(city_name);
    }

#if 1
    cities.add_edge("Blagoevgrad", "Kyustendil", 10);
    cities.add_edge("Kyustendil", "Sofiq", 20);
    cities.add_edge("Blagoevgrad", "Sofiq", 30);
    cities.add_edge("Vidin", "Sofiq", 40);
    cities.add_edge("Vraca", "Sofiq", 50);
    cities.add_edge("Vidin", "Vraca", 60);
    cities.add_edge("Vraca", "Pleven", 70);
    cities.add_edge("Pleven", "Razgrad", 80);
    cities.add_edge("Pleven", "Dobrich", 90);
    cities.add_edge("Razgrad", "Sofiq", 100);
    cities.add_edge("Razgrad", "Dobrich", 110);
    cities.add_edge("Razgrad", "Varna", 120);
    cities.add_edge("Dobrich", "Varna", 130);
    cities.add_edge("Razgrad", "Plovdiv", 140);
    cities.add_edge("Sofiq", "Plovdiv", 150);
    cities.add_edge("Plovdiv", "Burgas", 160);
    cities.add_edge("Varna", "Burgas", 170);
    cities.add_edge("Sliven", "Plovdiv", 180);
    cities.add_edge("Burgas", "Sliven", 190);
    cities.add_edge("Sofiq", "Varna", 200);
#endif

    cities.print();  // To make a vector somehow and check it

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Burgas", "Plovdiv") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);

    // cities.print_degrees();

#if 0
    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add_edge("Plovdiv", "Pleven", 210);
    cities.add_edge("Vidin", "Kyustendil", 220);
    cities.add_edge("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    std::cout << std::boolalpha << "Is there a vertex named Sofiq? - " << cities.has_vertex("Sofiq") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Razgrad? - " << cities.has_vertex("Razgrad") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Plovdiv? - " << cities.has_vertex("Plovdiv") << std::endl;

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    std::cout << std::boolalpha << "Is there a way from Blagoevgrad to Sliven? - " 
                                << cities.has_way("Blagoevgrad", "Sliven") << std::endl;

    std::cout << std::boolalpha << "Is there a way from Vidin to Varna? - " 
                                << cities.has_way("Vidin", "Varna") << std::endl;
    
    std::cout << std::boolalpha << "Is there a way from Kyustendil to Vidin? - " 
                                << cities.has_way("Kyustendil", "Vidin") << std::endl;

    cities.print_successors("Plovdiv");
    cities.print_predecessors("Plovdiv");
#endif

#if 0
    GList<std::string, size_t> graph(true, true);

    for(const std::string& city_name : city_names)  graph.add_vertex(city_name);
    
    for(size_t i = 0; i < 12; i++) 
    {
        size_t first = rand() % 11 + 0, second = rand() % 11 + 0;
        if(first != second)
            graph.add_edge(city_names[first], city_names[second], rand() % 600 + 0);
    }
    graph.print();
#endif
}

TEST_CASE("Oriented non-weighted graph test") {
    GList<std::string, size_t> cities(true, false);

    for (const std::string& city_name : city_names) {
        cities.add_vertex(city_name);
    }

#if 1
    cities.add_edge("Blagoevgrad", "Kyustendil", 10);
    cities.add_edge("Kyustendil", "Sofiq", 20);
    cities.add_edge("Blagoevgrad", "Sofiq", 30);
    cities.add_edge("Vidin", "Sofiq", 40);
    cities.add_edge("Vraca", "Sofiq", 50);
    cities.add_edge("Vidin", "Vraca", 60);
    cities.add_edge("Vraca", "Pleven", 70);
    cities.add_edge("Pleven", "Razgrad", 80);
    cities.add_edge("Pleven", "Dobrich", 90);
    cities.add_edge("Razgrad", "Sofiq", 100);
    cities.add_edge("Razgrad", "Dobrich", 110);
    cities.add_edge("Razgrad", "Varna", 120);
    cities.add_edge("Dobrich", "Varna", 130);
    cities.add_edge("Razgrad", "Plovdiv", 140);
    cities.add_edge("Sofiq", "Plovdiv", 150);
    cities.add_edge("Plovdiv", "Burgas", 160);
    cities.add_edge("Varna", "Burgas", 170);
    cities.add_edge("Sliven", "Plovdiv", 180);
    cities.add_edge("Burgas", "Sliven", 190);
    cities.add_edge("Sofiq", "Varna", 200);
#endif

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Burgas", "Plovdiv") == false);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    cities.print_degrees();

#if 0
    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add_edge("Plovdiv", "Pleven", 210);
    cities.add_edge("Vidin", "Kyustendil", 220);
    cities.add_edge("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    std::cout << std::boolalpha << "Is there a vertex named Sofiq? - " << cities.has_vertex("Sofiq") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Razgrad? - " << cities.has_vertex("Razgrad") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Plovdiv? - " << cities.has_vertex("Plovdiv") << std::endl;

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    std::cout << std::boolalpha << "Is there a way from Blagoevgrad to Sliven? - " 
                                << cities.has_way("Blagoevgrad", "Sliven") << std::endl;

    std::cout << std::boolalpha << "Is there a way from Vidin to Varna? - " 
                                << cities.has_way("Vidin", "Varna") << std::endl;
    
    std::cout << std::boolalpha << "Is there a way from Kyustendil to Vidin? - " 
                                << cities.has_way("Kyustendil", "Vidin") << std::endl;

    cities.print_successors("Plovdiv");
    cities.print_predecessors("Plovdiv");
#endif

#if 0
    GList<std::string, size_t> graph(true, true);

    for(const std::string& city_name : city_names)  graph.add_vertex(city_name);
    for(size_t i = 0; i < 12; i++) 
    {
        size_t first = rand() % 11 + 0, second = rand() % 11 + 0;
        if(first != second)
            graph.add_edge(city_names[first], city_names[second], rand() % 600 + 0);
    }
    graph.print();
#endif
}

TEST_CASE("Non-oriented weighted graph tests") {
    GList<std::string, size_t> cities(false, true);

    for (const std::string& city_name : city_names) {
        cities.add_vertex(city_name);
    }

#if 1
    cities.add_edge("Blagoevgrad", "Kyustendil", 10);
    cities.add_edge("Kyustendil", "Sofiq", 20);
    cities.add_edge("Blagoevgrad", "Sofiq", 30);
    cities.add_edge("Vidin", "Sofiq", 40);
    cities.add_edge("Vraca", "Sofiq", 50);
    cities.add_edge("Vidin", "Vraca", 60);
    cities.add_edge("Vraca", "Pleven", 70);
    cities.add_edge("Pleven", "Razgrad", 80);
    cities.add_edge("Pleven", "Dobrich", 90);
    cities.add_edge("Razgrad", "Sofiq", 100);
    cities.add_edge("Razgrad", "Dobrich", 110);
    cities.add_edge("Razgrad", "Varna", 120);
    cities.add_edge("Dobrich", "Varna", 130);
    cities.add_edge("Razgrad", "Plovdiv", 140);
    cities.add_edge("Sofiq", "Plovdiv", 150);
    cities.add_edge("Plovdiv", "Burgas", 160);
    cities.add_edge("Varna", "Burgas", 170);
    cities.add_edge("Sliven", "Plovdiv", 180);
    cities.add_edge("Burgas", "Sliven", 190);
    cities.add_edge("Sofiq", "Varna", 200);
#endif

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Burgas", "Plovdiv") == true);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    cities.print_degrees();

#if 0
    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add_edge("Plovdiv", "Pleven", 210);
    cities.add_edge("Vidin", "Kyustendil", 220);
    cities.add_edge("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    std::cout << std::boolalpha << "Is there a vertex named Sofiq? - " << cities.has_vertex("Sofiq") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Razgrad? - " << cities.has_vertex("Razgrad") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Plovdiv? - " << cities.has_vertex("Plovdiv") << std::endl;

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    std::cout << std::boolalpha << "Is there a way from Blagoevgrad to Sliven? - " 
                                << cities.has_way("Blagoevgrad", "Sliven") << std::endl;

    std::cout << std::boolalpha << "Is there a way from Vidin to Varna? - " 
                                << cities.has_way("Vidin", "Varna") << std::endl;
    
    std::cout << std::boolalpha << "Is there a way from Kyustendil to Vidin? - " 
                                << cities.has_way("Kyustendil", "Vidin") << std::endl;

    cities.print_successors("Plovdiv");
    cities.print_predecessors("Plovdiv");
#endif

#if 0
    GList<std::string, size_t> graph(false, true);

    for(const std::string& city_name : city_names)  graph.add_vertex(city_name);
    for(size_t i = 0; i < 12; i++) 
    {
        size_t first = rand() % 11 + 0, second = rand() % 11 + 0;
        if(first != second)
            graph.add_edge(city_names[first], city_names[second], rand() % 600 + 0);
    }
    graph.print();
#endif
}

TEST_CASE("Non-oriented non-weighted graph tests") {
    GList<std::string, size_t> cities(false, false);

    for (const std::string& city_name : city_names) {
        cities.add_vertex(city_name);
    }

#if 1
    cities.add_edge("Blagoevgrad", "Kyustendil", 10);
    cities.add_edge("Kyustendil", "Sofiq", 20);
    cities.add_edge("Blagoevgrad", "Sofiq", 30);
    cities.add_edge("Vidin", "Sofiq", 40);
    cities.add_edge("Vraca", "Sofiq", 50);
    cities.add_edge("Vidin", "Vraca", 60);
    cities.add_edge("Vraca", "Pleven", 70);
    cities.add_edge("Pleven", "Razgrad", 80);
    cities.add_edge("Pleven", "Dobrich", 90);
    cities.add_edge("Razgrad", "Sofiq", 100);
    cities.add_edge("Razgrad", "Dobrich", 110);
    cities.add_edge("Razgrad", "Varna", 120);
    cities.add_edge("Dobrich", "Varna", 130);
    cities.add_edge("Razgrad", "Plovdiv", 140);
    cities.add_edge("Sofiq", "Plovdiv", 150);
    cities.add_edge("Plovdiv", "Burgas", 160);
    cities.add_edge("Varna", "Burgas", 170);
    cities.add_edge("Sliven", "Plovdiv", 180);
    cities.add_edge("Burgas", "Sliven", 190);
    cities.add_edge("Sofiq", "Varna", 200);
#endif

    cities.print();

    CHECK(cities.has_vertex("Dupnicca") == false);
    CHECK(cities.has_edge("Dupnica", "Varna") == false);
    CHECK(cities.has_edge("Plovdiv", "Burgas") == true);
    CHECK(cities.has_edge("Burgas", "Plovdiv") == true);
    CHECK(cities.has_edge("Dupnica", "Burgas") == false);

    cities.print_degrees();

#if 0
    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add_edge("Plovdiv", "Pleven", 210);
    cities.add_edge("Vidin", "Kyustendil", 220);
    cities.add_edge("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    std::cout << std::boolalpha << "Is there a vertex named Sofiq? - " << cities.has_vertex("Sofiq") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Razgrad? - " << cities.has_vertex("Razgrad") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Plovdiv? - " << cities.has_vertex("Plovdiv") << std::endl;

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    std::cout << std::boolalpha << "Is there a way from Blagoevgrad to Sliven? - " 
                                << cities.has_way("Blagoevgrad", "Sliven") << std::endl;

    std::cout << std::boolalpha << "Is there a way from Vidin to Varna? - " 
                                << cities.has_way("Vidin", "Varna") << std::endl;
    
    std::cout << std::boolalpha << "Is there a way from Kyustendil to Vidin? - " 
                                << cities.has_way("Kyustendil", "Vidin") << std::endl;

    cities.print_successors("Plovdiv");
    cities.print_predecessors("Plovdiv");
#endif

#if 0
    GList<std::string, size_t> graph(false, true);

    for(const std::string& city_name : city_names)  graph.add_vertex(city_name);
    for(size_t i = 0; i < 12; i++) 
    {
        size_t first = rand() % 11 + 0, second = rand() % 11 + 0;
        if(first != second)
            graph.add_edge(city_names[first], city_names[second], rand() % 600 + 0);
    }
    graph.print();
#endif
}

TEST_CASE("Integer graph tests") {
    GList<int, int> g(true, false);

    for (size_t i = 1; i <= 12; i++) {
        g.add_vertex(i);
    }

#if 1
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    g.add_edge(4, 7);
    g.add_edge(5, 8);
    g.add_edge(5, 9);
    g.add_edge(6, 7);
    g.add_edge(6, 10);
    g.add_edge(6, 11);
    g.add_edge(7, 8);
    g.add_edge(10, 11);
    g.add_edge(11, 12);
#endif

    CHECK(g.has_vertex(99) == false);
    CHECK(g.has_vertex(8) == true);
    CHECK(g.has_edge(99, 1) == false);
    CHECK(g.has_edge(7, 8) == true);
    CHECK(g.has_edge(12, 11) == false);

    // for(size_t i = 1; i <= 12; i++) { g.BFS(i); g.DFS(i); } // TODO vectors
    // and compare them

#if 0
    g.print();
    g.remove_vertex(6);
    g.print();

    g.remove_edge(11, 12);
    g.print();

    g.print();
#endif
}
