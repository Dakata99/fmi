#include "Menu.h"

// public functions which can be executed outside
void Menu::open(const std::string& file_name, Figures& obj)
{
    file.open(file_name);
    if (file.is_open())
    {
        name = file_name;
        std::cout << "Successfully opened " << name  << "...\n"; 
        init(obj); // file is opened and we initialize figures
    }
    else std::cout << "Could not open " << file_name << "...\n";   
}

void Menu::close(void)
{
    if (file.is_open())
    {
        std::cout << "Successfully closed " << name << "...\n";
        file.close();
    }
    else std::cout << "OPEN A FILE FIRST!\n";
}

void Menu::save(const Figures& obj)
{
    if (file.is_open())
    {
        file.close();
        file.open(name, std::fstream::trunc | std::fstream::out);

        file << "<svg>\n";

        for (size_t i = 0; i < obj.figures.size(); i++) file << obj.figures[i]->get_info();
        
        file << "</svg>\n";

        std::cout << "Successfully saved changes to " << name << "...\n";
    }
    else std::cout << "OPEN A FILE FIRST!\n";
}

void Menu::saveas(const std::string& new_file, const Figures& obj)
{
    if (file.is_open())
    {
        std::fstream out(new_file, std::ofstream::out | std::ofstream::trunc);

        out << "<svg>\n";

        for (size_t i = 0; i < obj.figures.size(); i++) out << obj.figures[i]->get_info();

        out << "</svg>\n";
        
        std::cout << "Successfully saved as " << new_file << "...\n";
    }
    else std::cout << "OPEN A FILE FIRST!\n";
}

void Menu::help(void) const
{
    std::cout << "The following commands are supported:\n"
                 "open <file>       -   opens <file>\n"
                 "close             -   closes currently opened file\n"
                 "save              -   saves the currently open file\n"
                 "saveas <file>     -   saves the currently open file in <file>\n"
                 "help              -       prints this information\n"
                 "exit              -       exits the program\n";
}

void Menu::execute(const std::string& command, const std::string& argument, Figures& obj)
{
    if (command == "open")
    {
        if (!file.is_open())
            open(argument, obj); // open and initialize figures
        else
            std::cout << "CLOSE CURRENT FILE FIRST!\n";
    }
    else if (command == "save")
    {
        save(obj);
    }
    else if (command == "saveas")
    {
        saveas(argument, obj);
    }
    else if (command == "close")
    {
        obj.figures.clear();
        close();
    }
    else if (command == "print")
    {
        if (file.is_open())
            print(obj);
        else 
            std::cout << "OPEN A FILE FIRST!\n";
    }
    else if (command == "create")
    {
        create(argument, obj); //create a figure and add it to the vector of figures
        std::cout << "Successfully created " << argument.substr(0, argument.find(' ')) << " (" << obj.figures.size() << ")\n";
    }
    else if (command == "erase")
    {
        erase(argument, obj);
    }
    else if (command == "translate")
    {
        translate(argument, obj);
    }
    else if (command == "within")
    {
        within(argument, obj);
    }
    else if (command == "exit")
    {
        std::cout << "Exiting the program...\n";
    }
    else std::cout << "Invalid command!\n";
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
                 "--------------------------\n";
}

// private functions which initialize all the data
void Menu::reset_file(void)
{
    file.clear();
    file.seekg(0);
}

void Menu::init(Figures& obj)
{
    reset_file();
    std::string line;
    while (std::getline(file, line))
    {
        if (line[0] == '\t')
        {
            line = extract_string(line, "<", "/>");
            std::string figure = line.substr(0, line.find(' '));
            line.erase(0, line.find(' ') + 1);
            
            if (figure == "rect")           create_rectangle(line, obj);
            else if (figure == "circle")    create_circle(line, obj);
            else if (figure == "line")      create_line(line, obj);
        }
    }
}

void Menu::create_rectangle(std::string& argument, Figures& obj)
{
    std::string x = take_data(argument),
                y = take_data(argument),
                width = take_data(argument),
                height = take_data(argument),
                color = take_data(argument);

    obj.figures.push_back(obj.create_rectangle(x, y, width, height, color));
}

void Menu::create_circle(std::string& argument, Figures& obj)
{
    std::string x = take_data(argument),
                y = take_data(argument),
                radius = take_data(argument),
                color = take_data(argument);

    obj.figures.push_back(obj.create_circle(x, y, radius, color));
}

void Menu::create_line(std::string& argument, Figures& obj)
{
    std::string x1 = take_data(argument), 
                y1 = take_data(argument), 
                x2 = take_data(argument),
                y2 = take_data(argument),
                stroke_width = take_data(argument),
                color = take_data(argument);

    obj.figures.push_back(obj.create_line(x1, y1, x2, y2, stroke_width, color));
}

void Menu::print(const Figures& obj) { obj.print(); }

void Menu::create(const std::string& argument, Figures& obj)
{
    std::string arg = argument;
    std::string figure = arg.substr(0, arg.find(' '));
    arg.erase(0, figure.size() + 1);

    if (figure == "rect" || figure == "rectangle") create_rectangle(arg, obj);
    else if (figure == "circle") create_circle(arg, obj);
    else if (figure == "line") create_line(arg, obj);
    else std::cout << "This figure is not supported!\n";
}

void Menu::erase(const std::string& index, Figures& obj)
{
    if (index == "all")
    {
        obj.figures.clear();
        std::cout << "All figures are erased!\n";
        return;
    }
    
    size_t i = abs(std::stoi(index));
    if (!(i >= 1 && i <= obj.figures.size()))
    {
        std::cout << "There is no figure number " << i << "!\n";
        return;
    }
    
    const std::string type = obj.figures[i - 1]->get_type();
    obj.figures.erase(obj.figures.begin() + i - 1);
    std::cout << "Erased a " << type << " (" << i << ")\n";
}

void Menu::translate(const std::string& argument, Figures& obj)
{
    if (!valid_arg(argument)) //vTODO
    {
        /* code */
    }
    
    size_t number = 0;
    std::string vertical, horizontal;
    if (argument[0] == 'v')
    {
        vertical = argument.substr(0, argument.find(' '));
        horizontal = argument.substr(argument.find(' ') + 1, argument.size());
        
        double vert = fabs(std::stod(vertical.substr(vertical.find('=') + 1, vertical.size())));
        double horiz = fabs(std::stod(horizontal.substr(horizontal.find('=') + 1, horizontal.size())));

        obj.translate(number, horiz, vert);
        std::cout << "Translated all figures\n";
    }
    else
    {
        std::string temp = argument;
        std::string index = temp.substr(0, temp.find(' '));
        temp.erase(0, temp.find(' ') + 1);
        number = abs(std::stoi(index));

        vertical = temp.substr(0, temp.find(' '));
        horizontal = temp.substr(temp.find(' ') + 1, temp.size());
        
        double vert = fabs(std::stod(vertical.substr(vertical.find('=') + 1, vertical.size())));
        double horiz = fabs(std::stod(horizontal.substr(horizontal.find('=') + 1, horizontal.size())));
        
        obj.translate(number, horiz, vert);
        std::cout << "Translated a " << obj.figures[number - 1]->get_type() << " (" << number - 1 << ")\n";
    }
}

void Menu::within(const std::string& argument, Figures& obj)
{
    std::string figure = argument.substr(0, argument.find(' '));
    if (figure == "rectangle")
    {
        std::string temp = argument.substr(figure.size() + 1, argument.size());
        std::string x = take_data(temp),
                    y = take_data(temp),
                    width = take_data(temp),
                    height = take_data(temp),
                    color = take_data(temp);

        Figure* r = new Rectangle(std::stod(x), std::stod(y), std::stod(width), std::stod(height), "");
        obj.within(r);
        delete r;
    }
    else if (figure == "circle")
    {
        std::string temp = argument.substr(figure.size() + 1, argument.size());
        std::string x = take_data(temp),
                    y = take_data(temp),
                    radius = take_data(temp);

        Figure* c = new Circle(std::stod(x), std::stod(y), std::stod(radius), "");
        obj.within(c);
        delete c;
    }
    else std::cout << "Invalid region - you can choose only between rectangle and circle!\n";
}