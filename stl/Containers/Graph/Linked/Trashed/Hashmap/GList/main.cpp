#include <iostream>
#include <string>

#include "GList.h"

typedef void (*fp_t)(void);

void oriented_weighted_GList_test(void) {
    GList<std::string, size_t> cities(true, true);
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
    cities.BFS("Dupnica");

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
    GList<std::string, size_t> cities(true, false);
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
    GList<std::string, size_t> cities(false, true);
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
    GList<std::string, size_t> cities(false, false);
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

void tests(void) {
    fp_t func[] = {
        oriented_weighted_GList_test, oriented_non_weighted_GList_test,
        non_oriented_weighted_GList_test, non_oriented_non_weighted_graph_test};

    func[0]();
    func[1]();
    func[2]();
    func[3]();
}

int main(void) {
    // tests();

#if 1
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

#if 0
    std::cout << std::boolalpha << g.has_vertex(99) << std::endl;
    std::cout << std::boolalpha << g.has_vertex(8) << std::endl;
    std::cout << std::boolalpha << g.has_edge(99, 1) << std::endl;
    std::cout << std::boolalpha << g.has_edge(7, 8) << std::endl;
    std::cout << std::boolalpha << g.has_edge(12, 11) << std::endl;
#endif

#if 1
    for (size_t i = 1; i <= 12; i++) {
        g.BFS(i);
    }
    for (size_t i = 1; i <= 12; i++) {
        g.DFS(i);
    }

    g.remove_vertex(6);
    // g.print();

    // g.remove_edge(11, 12);
    // g.print();

    // g.print();
#endif
#endif

    return 0;
}
