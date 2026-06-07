TEST_CASE("Example")
{
    std::fstream fs;

    Menu menu;
    // menu.print_menu();

    Figures figures; // object of figures
    
    std::string operation;
    bool initialized = false;
        
    menu.execute("open", "examples/example", figures);
    menu.execute("print", "", figures);
    menu.execute("create", "rectangle -1000 -1000 10 20 yellow", figures);
    menu.execute("print", "", figures);
    menu.execute("within", "rectangle 0 0 30 30", figures);
    menu.execute("within", "circle 0 0 5", figures);
    menu.execute("erase", "2", figures);
    menu.execute("erase", "100", figures);
    menu.execute("print", "", figures);
    menu.execute("translate", "vertical=10 horizontal=100", figures);
    menu.execute("print", "", figures);
    menu.execute("saveas", "examples/example_new", figures);
    menu.execute("exit", "", figures);
}