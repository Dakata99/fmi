#ifndef _TABLE_H_
#define _TABLE_H_

#include <string>
#include <vector>
#include <iostream>

class Menu;

class Table
{
private:
    friend Menu;
    
    typedef std::vector<std::string> cells;
    std::vector<cells> table;

    size_t rows, columns;

private:
    size_t set_width(const size_t&) const;
   
    void read(Menu&);

    //std::string check(std::string) const;

    size_t get_row(const std::string) const;
    size_t get_column(const std::string) const;

    bool valid_cell(const size_t&, const size_t&);

    void execute(const std::string, const std::string);
    void execute(const std::string, const std::string, const char, const std::string);
    void calculate(const size_t, const size_t, const std::string, const char, const std::string);

public:
    Table(const size_t& = 1, const size_t& = 1);

    //void init(Menu&);
    void edit(const std::string&);
};

#endif