#include <iostream>
#include <string>
#include <fstream>

//#include "Menu.h"
//#include "Table.h"
#include "Tools.h"

void run(void)
{
    Menu menu;
    menu.print_menu();
    Table table;

    std::string operation;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, operation);

        /* if operation has an argument like open then we seperate it in 2 strings, otherwise it does not have */
        std::string command = operation, argument; 
        if (operation.find(' ') != std::string::npos)
        {
            command = operation.substr(0, operation.find(' '));
            argument = operation.substr(operation.find(' ') + 1, operation.size());
        }

        menu.execute(command, argument, table);
    } while (operation != "exit");
}

int main(void)
{
    //run();
    //separate();
    //std::cout << std::boolalpha << is_string("\"hellow world!\"") << std::endl
                                //<< is_string("nsofjng\"asdfpgksdf\"dmfogkmdg") << std::endl
                                //<< is_string("") << std::endl;
    //separate_with_automata();

    std::filebuf fb;
    fb.open("example", std::ios::in);
    std::istream f(&fb);
    std::vector<std::string> data = getNextLineAndSplitIntoTokens(f);

    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    

    return 0;
}