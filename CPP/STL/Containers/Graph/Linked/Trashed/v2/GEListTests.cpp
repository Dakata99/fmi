#pragma once
#include <iostream>
#include <string>

#include "GEList.h"
#include "Graph.h"

void oriented_weighted_GEList_test() {
    GEList<std::string, size_t> cities(5, true, true);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq", 60);
    cities.add_edge("Sofiq", "Plovdiv", 220);
    cities.add_edge("Sofiq", "Varna", 560);
    cities.add_edge("Sofiq", "Burgas", 500);
    cities.add_edge("Varna", "Burgas", 115);
    cities.add_edge("Plovdiv", "Burgas", 250);

    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

    cities.print();

    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
}

void oriented_non_weighted_GEList_test() {
    GEList<std::string, size_t> cities(5, true, true);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq", 60);
    cities.add_edge("Sofiq", "Plovdiv", 220);
    cities.add_edge("Sofiq", "Varna", 560);
    cities.add_edge("Sofiq", "Burgas", 500);
    cities.add_edge("Varna", "Burgas", 115);
    cities.add_edge("Plovdiv", "Burgas", 250);

    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

    cities.print();

    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
}

void non_oriented_weighted_GEList_test() {
    GEList<std::string, size_t> cities(5, true, true);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq", 60);
    cities.add_edge("Sofiq", "Plovdiv", 220);
    cities.add_edge("Sofiq", "Varna", 560);
    cities.add_edge("Sofiq", "Burgas", 500);
    cities.add_edge("Varna", "Burgas", 115);
    cities.add_edge("Plovdiv", "Burgas", 250);

    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

    cities.print();

    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
}

void non_oriented_non_weighted_GElist_test_test() {
    GEList<std::string, size_t> cities(5, true, true);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq", 60);
    cities.add_edge("Sofiq", "Plovdiv", 220);
    cities.add_edge("Sofiq", "Varna", 560);
    cities.add_edge("Sofiq", "Burgas", 500);
    cities.add_edge("Varna", "Burgas", 115);
    cities.add_edge("Plovdiv", "Burgas", 250);

    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

    cities.print();

    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
}

void gelist_tests(void) {
    std::cout << "-------- ORIENTED WEIGHTED GRAPH --------\n";
    oriented_weighted_GEList_test();
    std::cout << "-------- ORIENTED WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- ORIENTED NON-WEIGHTED GRAPH --------\n";
    // oriented_non_weighted_GEList_test();
    std::cout << "-------- ORIENTED NON-WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- NON-ORIENTED WEIGHTED GRAPH --------\n";
    // non_oriented_weighted_GEList_test();
    std::cout << "-------- NON-ORIENTED WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- NON-ORIENTED NON-WEIGHTED GRAPH --------\n";
    // non_oriented_non_weighted_GElist_test_test();
    std::cout << "-------- NON-ORIENTED NON-WEIGHTED GRAPH --------\n\n";
}
