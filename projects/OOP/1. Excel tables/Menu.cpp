#include <iomanip>

#include "Tools.h"
#include "Menu.h"

void Menu::open(const std::string& argument)
{
    file.open(argument);
    file_name = argument.substr(argument.rfind('/') + 1, argument.size());
    if (file.is_open())
    {
        std::cout << "Successfully opened " << file_name << "...\n";
        return;
    }

    file.open("empty.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (file.is_open())
    {
        std::cout << "Created and opened an empty file with file_name empty.txt ...\n";
        return;
    }
}

void Menu::close(void)
{
    if (file.is_open())
    {
        file.close();
        std::cout << "Successfully closed " << file_name << "..." << std::endl;
    }
    else std::cout << "No file opened in order to close it...\n";
}

void Menu::save(void)
{
    if (file.is_open())
    {
        file.flush();
        std::cout << "Successfully saved " << file_name << std::endl;
    }
    else std::cout << "No file opened in order to save it!\n";
}

void Menu::save_as(const std::string &file_path)
{
    if (file.is_open())
    {
        std::ofstream temp_file(file_path);
        std::string file_name = file_path.substr(file_path.rfind('/') + 1, file_path.size());
        temp_file << file.rdbuf();
        std::cout << "Successfully saved another " << file_name << "...\n";
    }
    else std::cout << "No file opened in order to save it as other file!\n";
}

void Menu::help(void) const
{
    std::cout << "The following commands are supported:\n"
                 "open <file>       -     opens a file named <file>\n"
                 "close             -     closes currently opened file\n"
                 "save              -     saves the currently open file\n"
                 "saveas <file>     -     saves the currently open file as <file>\n"
                 "help              -     prints information\n"
                 "exit              -     exits the program (without saving changes)\n";
}

void Menu::print(Table& t) const
{
    size_t rows = t.table.size();

    for (size_t i = 0; i < rows; i++)
    {
        size_t columns = t.table[i].size();
        for (size_t j = 0; j < columns; j++)
        {
            size_t width = t.set_width(j);
            std::cout << t.table[i][j] << std::setw(width - t.table[i][j].size() + 3) << " | ";
        }
        std::cout << std::endl;
    }
}

void Menu::edit(Table& t)
{

}

std::string Menu::change(const std::string& line)
{
    std::string temp;
    for (size_t i = 0; i < line.size(); i++)
    {
        switch (line[i])
        {
        case ',':
            temp += '|'; break;
        case '\0':
            temp += '\n'; break;
        default:
            temp += line[i]; break;
        }
    }
    return temp;
}

void Menu::simplify(void)
{
    if (file.is_open())
    {
        char symbol;
        std::string temp;

        while (file >> std::noskipws >> symbol)
        {
            if (symbol == ',') temp += '|';
            else temp += symbol;
        }

        file.close();
        file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc);
        file << temp;
    }
}

void Menu::read(Table& t)
{
    file.clear();
    file.seekg(0);

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
    {
        // simplifying by removing all white spaces
        //std::string temp = removeWS(line);
        lines.push_back(line);
    }

    // then pushing the actual data (strings before ',' its the data in the cell)
    std::vector<std::string> data;
    for (size_t i = 0; i < lines.size(); i++)
    {
        while (lines[i] != "")
        {
            data.push_back(extract_string(lines[i], ','));
            lines[i] = lines[i].erase(0, extract_string(lines[i], ',').size() + 1);
        }
        data.push_back("\n");
    }

    std::vector<std::string> temp;
    for (size_t i = 0; i < data.size(); i++)
        temp.push_back(extract_string(data[i], "\"", "\""));

    // for (size_t i = 0; i < temp.size(); i++) std::cout << temp[i] << std::endl;

    // for (size_t i = 0; i < data.size(); i++) std::cout << data[i] << " ";

    size_t row = 0, column = 0;
    for (size_t k = 0; k < data.size(); k++)
    {
        if (data[k] == "\n")
        {
            row++;
            column = 0;
        }
        else
        {
            t.table[row][column] = data[k];
            column++;
        }
    }
}

void Menu::init(Table &table)
{
    if (file.is_open())
    {
        size_t rows = get_rows(file);
        size_t columns = get_columns(file);  
        
        table = Table(rows, columns);      
        read(table);
    }
    else std::cout << "Can not initialize table...\n";
}

Menu::Menu() : printable(false), editable(false) {}

void Menu::execute(const std::string& command, const std::string& argument, Table& table)
{
    if (command == "open" && !file.is_open()) { open(argument); init(table); printable = editable = true; }
    else if (command == "open" && file.is_open()) std::cout << "You have already opened a file. To open other one - first close the current!\n";
    else if (command == "close" && file.is_open()) { close(); printable = editable = false; }
    else if (command == "save" && file.is_open()) save();
    else if (command == "saveas" && file.is_open()) save_as(argument);
    else if (command == "help") help();
    else if (command == "exit") { close(); std::cout << "Exiting the program...\n"; }
    else if (command == "print" && printable) print(table);
    else if (command == "edit" && editable) table.edit(argument);
    else if (!file.is_open()) std::cout << "Cannot execute " << command << " - invalid command or unopened file!\n";
    else std::cout << "The command maybe invalid or you have chosen an operation without opening a file!\n";
}

void Menu::print_menu(void) const
{
    std::cout << "---------- MENU ----------\n"
                 "1. Open\n"
                 "2. Close\n"
                 "3. Save\n"
                 "4. Save as\n"
                 "5. Help\n"
                 "6. Exit\n"
                 "7. Print\n"
                 "8. Edit\n"
                 "** Note: if an invalid command is entered or no file is opend - the program will continue till a valid command is entered (in the right order)!\n";
                 "--------------------------\n";
}

bool Menu::opened(void) const { return file.is_open(); }