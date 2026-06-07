#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <fstream>

#include "Table.h"

class Menu
{
private:
    friend Table;
    std::fstream file;
    std::string file_name;

    bool printable, editable;

    void open(const std::string&);
    void close(void);
    void save(void);
    void save_as(const std::string&);
    void help(void) const;

    void print(Table&) const;
    void edit(Table&);

    std::string change(const std::string&);
    void simplify(void);

    void read(Table&);
    void init(Table&);

public:
    Menu();
    
    void execute(const std::string&, const std::string&, Table&);
    void print_menu(void) const;
    bool opened(void) const;
};

#endif