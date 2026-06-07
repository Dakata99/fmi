#include <iostream>
#include <string>

#include "GList.h"

void oriented_weighted_GList_test(void) {
    GList<std::string, size_t> cities(5, true, true);
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
    std::cout << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    cities.print();

    cities.remove_edge("Sofiq", "Varna");
    cities.remove_edge("Varna", "Burgas");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.print();

#if 1
    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge between Burgas and Plovdiv ? - "
              << std::boolalpha << cities.has_edge("Burgas", "Plovdiv")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
#endif
}

void oriented_non_weighted_GList_test(void) {
    GList<std::string, size_t> cities(5, true, false);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq");
    cities.add_edge("Sofiq", "Plovdiv");
    cities.add_edge("Sofiq", "Varna");
    cities.add_edge("Sofiq", "Burgas");
    cities.add_edge("Varna", "Burgas");
    cities.add_edge("Plovdiv", "Burgas");
    cities.add_edge("Plovdiv", "Qmbol");

    cities.print();

    cities.remove_edge("Sofiq", "Varna");
    cities.remove_edge("Varna", "Burgas");
    cities.print();

    cities.remove_vertex("Plovdiv");
    cities.print();

#if 1
    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge between Burgas and Plovdiv ? - "
              << std::boolalpha << cities.has_edge("Burgas", "Plovdiv")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
#endif
}

void non_oriented_weighted_GList_test(void) {
    GList<std::string, size_t> cities(5, false, true);
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
    cities.add_edge("Plovdiv", "Qmbol", 555);

    cities.print();

    cities.remove_edge("Sofiq", "Varna");
    cities.remove_edge("Varna", "Burgas");
    cities.print();

    cities.remove_vertex("Burgas");
    cities.print();

#if 1
    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
#endif
}

void non_oriented_non_weighted_graph_test(void) {
    GList<std::string, size_t> cities(5, false, false);
    cities.add_vertex("Sofiq");
    cities.add_vertex("Plovdiv");
    cities.add_vertex("Varna");
    cities.add_vertex("Burgas");
    cities.add_vertex("Dupnica");

    cities.add_edge("Dupnica", "Sofiq");
    cities.add_edge("Sofiq", "Plovdiv");
    cities.add_edge("Sofiq", "Varna");
    cities.add_edge("Sofiq", "Burgas");
    cities.add_edge("Varna", "Burgas");
    cities.add_edge("Plovdiv", "Burgas");
    cities.add_edge("Plovdiv", "Qmbol");

    cities.print();

    cities.remove_edge("Sofiq", "Varna");
    cities.remove_edge("Plovdiv", "Burgas");
    cities.print();

    cities.remove_vertex("Varna");
    cities.print();

#if 1
    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;
#endif
}

void glist_tests(void) {
    fp_t func[] = {
        oriented_weighted_GList_test, oriented_non_weighted_GList_test,
        non_oriented_weighted_GList_test, non_oriented_non_weighted_graph_test};

    std::cout << "-------- ORIENTED WEIGHTED GRAPH --------\n";
    func[0]();
    std::cout << "-------- ORIENTED WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- ORIENTED NON-WEIGHTED GRAPH --------\n";
    func[1]();
    std::cout << "-------- ORIENTED NON-WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- NON-ORIENTED WEIGHTED GRAPH --------\n";
    func[2]();
    std::cout << "-------- NON-ORIENTED WEIGHTED GRAPH --------\n\n";

    std::cout << "-------- NON-ORIENTED NON-WEIGHTED GRAPH --------\n";
    func[3]();
    std::cout << "-------- NON-ORIENTED NON-WEIGHTED GRAPH --------\n\n";
}
