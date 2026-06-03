#include "Menu.h"
#include "Figure.h"
#include "Figures.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

void run(void)
{
    Menu menu;
    menu.print_menu();

    Figures figures; // object of figures
    
    std::string operation;
    bool initialized = false;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, operation);
        
        std::string command = operation.substr(0, operation.find(' ')), argument;
                    
        if (operation.find(' ') != std::string::npos)
            argument = operation.substr(operation.find(' ') + 1, operation.size());
        
        menu.execute(command, argument, figures);

    } while (operation != "exit");
}

int main(void)
{
    run();
    
    return 0;
}