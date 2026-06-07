#include <iostream>
#include <string>

#include "../Graph.h"
#include "GEList.h"

typedef void (*fp_t)(void);

void oriented_weighted_GEList_test() {
    GEList<std::string, size_t> cities(5, true, true);

    std::cout << "Is there a vertex, name Dupnicca ? - " << std::boolalpha
              << cities.has_vertex("Dupnicca") << std::endl;

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
    cities.add("Burgas", "Plovdiv", 999);

    cities.set("Qmbol", "Dobrich");
    cities.set("Qmbol", "Dobrich", 111);

    std::cout << "Is there a vertex, name Dupnica ? - " << std::boolalpha
              << cities.has_vertex("Dupnica") << std::endl;

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
    GEList<std::string, size_t> cities(5, true, false);

    cities.add("Dupnica", "Sofiq");
    cities.add("Sofiq", "Plovdiv");
    cities.add("Sofiq", "Varna");
    cities.add("Varna", "Burgas");
    cities.add("Plovdiv", "Burgas");
    cities.add("Qmbol");

    std::cout << "Is there a vertex, name Dupnicca ? - " << std::boolalpha
              << cities.has_vertex("Dupnicca") << std::endl;

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
    GEList<std::string, size_t> cities(5, false, true);
    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

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

    std::cout << "Is there a vertex, name Dupnicca ? - " << std::boolalpha
              << cities.has_vertex("Dupnicca") << std::endl;

    std::cout << "Is there an edge between Dupnica and Varna ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Varna")
              << std::endl;

    std::cout << "Is there an edge between Plovdiv and Burgas ? - "
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas")
              << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - "
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas")
              << std::endl;

    cities.remove_edge("Sofiq", "Burgas");
    cities.print();
    cities.remove_vertex("Plovdiv");
    cities.print();
}

void non_oriented_non_weighted_GElist_test_test() {
    GEList<std::string, size_t> cities(5, false, false);

    cities.add("Dupnica", "Sofiq");
    cities.add("Sofiq", "Plovdiv");
    cities.add("Sofiq", "Varna");
    cities.add("Sofiq", "Burgas");
    cities.add("Varna", "Burgas");
    cities.add("Plovdiv", "Burgas");

    std::cout << "Is there a vertex, name Dupnicca ? - " << std::boolalpha
              << cities.has_vertex("Dupnicca") << std::endl;

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

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.print();
}

void tests(void) {
    fp_t func[] = {oriented_weighted_GEList_test,
                   oriented_non_weighted_GEList_test,
                   non_oriented_weighted_GEList_test,
                   non_oriented_non_weighted_GElist_test_test};

    func[0]();
    // func[1]();
    // func[2]();
    // func[3]();
}

int main(void) {
    tests();

    return 0;
}
