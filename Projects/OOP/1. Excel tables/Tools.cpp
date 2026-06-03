#include "Tools.h"

bool is_integer(const std::string& digit)
{
    if (digit == "") return false;
    
    size_t i = 0;

    if (digit[0] == '-') i = 1;

    for (; i < digit.size(); i++)
        if (!(digit[i] >= '0' && digit[i] <= '9')) return false;

    return true;
}

bool is_double(const std::string& source)
{
    if (source == "") return false;
    
    size_t counter = 0;
    for (size_t i = 0; i < source.size(); i++)
        if (source[i] == '.') counter++;


    if (counter > 1 || source[0] == '.' || source[source.size() - 1] == '.') return false;

    if (counter == 1)
    {
        if (source[0] == '-')
            return is_integer(source.substr(1, source.find('.') - 1)) && is_integer(source.substr(source.find('.') + 1, source.size()));
        else
            return is_integer(source.substr(0, source.find('.'))) && is_integer(source.substr(source.find('.') + 1, source.size()));
    }
    
    return is_integer(source);
}

bool is_cell(const std::string& operand)
{
    if (operand[0] != 'R' || operand[1] == 'C' || 
        operand[operand.size()] == 'C' || operand.find('C') == std::string::npos)
        return false;
    else if (!is_integer(operand.substr(1, operand.find('C') - 1)))
        return false;
    else if (!is_integer(operand.substr(operand.find('C') + 1, operand.size())))
        return false;

    return true;
}

bool is_string(const std::string& str)
{
    std::regex string("^\".*\"$"); /* Should contain quotes */

    return std::regex_match(str, string);
}

std::string check(const std::string& source)
{
    if (is_cell(source)) return "cell";
    else if (is_double(source)) return "number";
    else return "string";
    
    return "";
}

std::string extract_string(std::string source, const char end)
{
    // size_t startIndex = source.find(end); 
    // if (startIndex == std::string::npos)
    // {
    //     return source;
    // }

    // size_t endIndex = source.find(end, startIndex + 1);
    // std::string temp = source.substr(0, source.find(end));
    // return source.substr(startIndex, endIndex - startIndex);

    size_t startIndex = source.find(end), endIndex = source.find(end, startIndex + 1);
    return source.substr(0, source.find(end));
}

std::string extract_string(std::string source, std::string start, std::string end)
{
    size_t startIndex = source.find(start);
    if (startIndex == std::string::npos)
    {
        return source;
    }
    startIndex += start.length();

    size_t endIndex = source.find(end, startIndex);

    return source.substr(startIndex, endIndex - startIndex);
}

// std::string removeWhiteSpaces(Menu& m)
// {
//     m.file.clear();
//     m.file.seekg(0);
//     std::string temp;
//     char symbol;
//     while (m.file >> std::noskipws >> symbol)
//     {
//         if (symbol != ' ')
//         {
//             temp += symbol;
//         }
//     }
//     return temp;
// }

std::string removeWS(const std::string source)
{
    std::string temp;
    for (size_t i = 0; i < source.size(); i++)
        if (source[i] != ' ') temp += source[i];

    return temp;
}

size_t get_rows(std::fstream& file)
{
    file.clear();
    file.seekg(0);

    size_t rows = 0;
    std::string line;

    while (std::getline(file, line)) rows++;

    return rows;
}

size_t get_columns(std::fstream& file)
{
    file.clear();
    file.seekg(0);

    std::string line;
    size_t columns = 0;
    while (std::getline(file, line))
    {
        size_t counter = 0;
        for (size_t i = 0; i < line.size(); i++)
            if (line[i] == ',') counter++;
        
        if (columns <= counter) columns = counter;
    }

    return columns + 1;
}

void separate(void)
{
    std::fstream file("example");

    if (!file.is_open()) return;

    /*
    std::string line;
    while (std::getline(file, line))
    {
        const char* str = line.c_str();
    }
    */
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

    for (size_t i = 0; i < data.size(); i++) std::cout << data[i] << " ";

    /*
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
            table[row][column] = data[k];
            column++;
        }
    }
    */
}

bool valid_expr(const std::string& expr, const size_t& max_row, const size_t& max_column)
{
    std::string row = std::to_string(max_row);
    std::string column = std::to_string(max_column);
    
    std::string cell = "R[1-" + row + "]C[1-" + column + "]";

    std::regex assingment(" *" + cell + " *= *" + cell + " *");
    std::regex operation(" *R[1-9]C[1-9] *= *R[1-9]C[1-9] *[+-/*] *R[1-9]C[1-9]");
    /* TODO: more cases */
    // std::regex string();
    
    /*
        for any integer and double = ((^(([1-9])|(-[1-9]))([0-9])*)|(0)).[0-9]{1,}
        for any string = 
        for valid cell = 
    */

    return std::regex_match(expr, assingment) || std::regex_match(expr, operation);
}

// std::string removeWS(std::string source)
// {
//     std::string temp;
//     for (size_t i = 0; i < source.size(); i++)
//     {
//         if (source[i] != ' ')
//         {
//             temp += source[i];
//         }   
//     }
//     return temp;
// }

// std::string extractString(std::string source, const char end)
// {
//     size_t startIndex = source.find(end);
//     if (startIndex == std::string::npos)
//     {
//         return source;
//     }
    
//     return source.substr(0, source.find(end));
// }
// // std::string extractString(std::string source, std::string start, std::string end)
// // {
// //     size_t startIndex = source.find(start);
// //     if (startIndex == std::string::npos)
// //     {
// //         return "";
// //     }
// //     startIndex += start.length();

// //     size_t endIndex = source.find(end, startIndex);

// //     return source.substr(startIndex, endIndex - startIndex);
// // }



void separate_with_automata(void)
{
    std::fstream file("example");

    if (!file.is_open()) return;

    enum FLAG {  };

    std::vector<std::string> data;

    char symbol;
    bool opened_quote = false;
    std::string element;
    while (file >> std::noskipws >> symbol)
    {
        switch (symbol)
        {
        case '"' : 
        case ',' : data.push_back(element); element.clear(); break;
        default: element += symbol; break;
        }
    }
}

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}