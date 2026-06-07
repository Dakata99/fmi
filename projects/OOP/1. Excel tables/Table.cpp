#include <vector>
#include <cmath>
#include <sstream>

#include "Tools.h"
#include "Table.h"

size_t Table::set_width(const size_t& index) const
{
    size_t max = 0;
    for (size_t i = 0; i < table.size(); i++)
    {
        size_t len = table[i][index].size();
        if (max <= len) max = len;
    }
    
    return max;
}

void Table::read(Menu& m)
{
    //m.file.clear();
    //m.file.seekg(0);
    
    std::vector<std::string> vec;
    std::string line;
    //while (std::getline(m.file, line))
    {
        //simplifying by removing all white spaces
        std::string temp = removeWS(line);
        vec.push_back(temp);
    }
    
    //then pushing the actual data(strings before ',' its the data in the cell)
    std::vector<std::string> vec2;
    for (size_t i = 0; i < vec.size(); i++)
    {
        while (vec[i] != "")
        {
            vec2.push_back(extract_string(vec[i], ','));
            vec[i] = vec[i].erase(0, extract_string(vec[i], ',').size() + 1);
        }
        vec2.push_back("\n");
    }
    
    std::vector<std::string> temp;
    for (size_t i = 0; i < vec2.size(); i++)
        temp.push_back(extract_string(vec2[i], "\"", "\""));

    // for (size_t i = 0; i < temp.size(); i++)
    // {
    //     std::cout << temp[i] << std::endl;
    // }
    
    
    // for (size_t i = 0; i < vec2.size(); i++)
    // {
    //     std::cout << vec2[i] << " ";
    // }
    


    size_t i = 0, j = 0;
    for (size_t k = 0; k < vec2.size(); k++)
    {
        if (vec2[k] == "\n")
        {
            i++;
            j = 0;
        }
        else
        {
            table[i][j] = vec2[k];
            j++;
        }
    }

    // for (size_t i = 0; i < rows; i++)
    // {
    //     for (size_t j = 0; j < columns; j++)
    //     {
    //         std::cout << table[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

bool Table::valid_cell(const size_t& row, const size_t& column)
{ return true; } //return row >= 1 && row <= rows && column >= 1 && column <= columns; }

size_t Table::get_row(const std::string source) const { return std::stoi(source.substr(1, source.find('C'))); }

size_t Table::get_column(const std::string source) const { return std::stoi(source.substr(source.find('C') + 1, source.size())); }

void Table::execute(const std::string lhs, const std::string rhs)
{
    size_t row = get_row(lhs), column = get_column(lhs);
    if (!(row >= 1 && row <= rows && column >= 1 && column <= columns))
    {
        std::cout << "No such cell(" << lhs << ") in table!\n";
        std::cout << "This table has " << rows << " rows and " << columns << " columns.\n";
        return;
    }
    
    std::string type = check(rhs);
    if (type == "cell")
    {
        size_t rhsRow = get_row(rhs), rhsColumn = get_column(rhs);

        if (rhsRow >= 1 && rhsRow <= rows && rhsColumn >= 1 && rhsColumn <= columns)
            table[row - 1][column - 1] = table[rhsRow - 1][rhsColumn - 1];
        else 
            table[row - 1][column - 1] = "0";
    }
    else if (type == "number")
    {
            double number = std::stod(rhs);
            std::stringstream s;
            s << number;
            table[row - 1][column - 1] = s.str();
    }
    else if (type == "string")
    {
        table[row - 1][column - 1] = rhs;
    }
}

void Table::execute(const std::string cell, const std::string larg, const char oper, const std::string rarg)
{
    size_t row =  get_row(cell), column = get_column(cell);
    if (!(row >= 1 && row <= rows && column >= 1 && column <= columns))
    {
        std::cout << "No such cell(" << cell << ") in this table\n";
        std::cout << "This table has " << rows << " rows and " << columns << " columns.\n";
        return;
    }
     
    std::string type1 = check(larg);
    std::string type2 = check(rarg);
    if (type1 == "cell" && type2 == "cell")
    {
        calculate(row, column, larg, oper, rarg);
    }
    else if (type1 == "cell" && type2 == "number")
    {
        size_t largRow = get_row(larg), largColumn = get_column(larg);
                
        type1 = check(table[largRow - 1][largColumn - 1]);
        if (type1 == "number")
        {
            double num1 = std::stod(table[largRow - 1][largColumn - 1]);
            double num2 = std::stod(rarg);

            std::stringstream s;
            switch (oper)
            {
                case '+': s << num1 + num2; table[row - 1][column - 1] = s.str(); break;
                case '-': s << num1 - num2; table[row - 1][column - 1] = s.str(); break;
                case '*': s << num1 * num2; table[row - 1][column - 1] = s.str(); break;
                case '/': 
                    if (num2 == 0)
                    {
                        table[row - 1][column - 1] = "ERROR";
                    }
                    else
                    {
                        s << num1 / num2; 
                        table[row - 1][column - 1] = s.str();
                    }break;
                case '^': s << pow(num1, num2); table[row - 1][column - 1] = s.str(); break;
            }
        }
        else
        {
            table[row - 1][column - 1] = "0";
        }
    }
    else if (type1 == "number" && type2 == "cell")
    {
        size_t rargRow = get_row(rarg), rargColumn = get_column(rarg);

        type2 = check(table[rargRow - 1][rargColumn - 1]);
        if (type2 == "number")
        {
            double num1 = std::stod(larg);
            double num2 = std::stod(table[rargRow - 1][rargColumn - 1]);

            std::stringstream s;
            switch (oper)
            {
                case '+': s << num1 + num2; table[row - 1][column - 1] = s.str(); break;
                case '-': s << num1 - num2; table[row - 1][column - 1] = s.str(); break;
                case '*': s << num1 * num2; table[row - 1][column - 1] = s.str(); break;
                case '/': 
                    if (num2 == 0)
                    {
                        table[row - 1][column - 1] = "ERROR";
                    }
                    else
                    {
                        s << num1 / num2; 
                        table[row - 1][column - 1] = s.str();
                    } 
                    break;
                case '^': s << pow(num1, num2); table[row - 1][column - 1] = s.str(); break;
            }
        }
        else
        {
            if (oper == '^')
            {
                std::stringstream s;
                s << pow(std::stod(larg), 0);
                table[row - 1][column - 1] = s.str();
            }
            else
            {
                table[row - 1][column - 1] = "ERROR";
            }
        }
    }
    else if (type1 == "number" && type2 == "number")
    {
        double num1 = std::stod(larg), num2 = std::stod(rarg);

        std::stringstream s;
        switch (oper)
        {
            case '+': s << num1 + num2; table[row - 1][column - 1] = s.str(); break;
            case '-': s << num1 - num2; table[row - 1][column - 1] = s.str(); break;
            case '*': s << num1 * num2; table[row - 1][column - 1] = s.str(); break;
            case '/': 
                if (num2 == 0)
                {
                    table[row - 1][column - 1] = "ERROR";
                }
                else
                {
                    s << num1 / num2;
                    table[row - 1][column - 1] = s.str();
                }   
                break;
            case '^': s << pow(num1, num2); table[row - 1][column - 1] = s.str(); break;
        }
    } 
}

void Table::calculate(const size_t row, const size_t column, const std::string larg, const char oper, const std::string rarg)
{
    size_t largRow = get_row(larg), largColumn = get_column(larg);
    size_t rargRow = get_row(rarg), rargColumn = get_column(rarg);        

    bool cell1 = valid_cell(largRow, largColumn), cell2 = valid_cell(rargRow, rargColumn);
    if (cell1 && cell2)
    {
        std::string type1 = check(table[largRow - 1][largColumn - 1]);
        std::string type2 = check(table[rargRow - 1][rargColumn - 1]);
        if (type1 == "number" && type2 == "number")
        {
            double num1 = std::stod(table[largRow - 1][largColumn - 1]);
            double num2 = std::stod(table[rargRow - 1][rargColumn - 1]);

            std::stringstream s;
            switch (oper)
            {
                case '+': s << num1 + num2; table[row - 1][column - 1] = s.str(); break;
                case '-': s << num1 - num2; table[row - 1][column - 1] = s.str(); break;
                case '*': s << num1 * num2; table[row - 1][column - 1] = s.str(); break;
                case '/': 
                    if (num2 == 0)
                    {
                        table[row - 1][column - 1] = "ERROR";
                    }
                    else
                    { 
                        s << num1 / num2; 
                        table[row - 1][column - 1] = s.str();
                    }                      
                    break;
                case '^': s << pow(num1, num2); table[row - 1][column - 1] = s.str(); break;
            }
        }
        else if(type1 == "number" && type2 != "number")
        {
            double num1 = std::stod(table[largRow - 1][largColumn - 1]);
            double num2 = 0.0;
            double result = 0.0;
        
            std::stringstream s;
            switch (oper)
            {
                case '+': result = num1 + num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '-': result = num1 - num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '*': result = num1 * num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '/': table[row - 1][column - 1] = "ERROR"; break;
                case '^': s << pow(num1, 0); table[row - 1][column - 1] = s.str(); break;
            }
        }
        else if (type1 != "number" && type2 == "number")
        {
            double num1 = 0.0;
            double num2 = std::stod(table[rargRow - 1][rargRow - 1]);
            double result = 0.0;

            std::stringstream s;
            switch (oper)
            {
                case '+': result = num1 + num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '-': result = num1 - num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '*': result = num1 * num2; s << result; table[row - 1][column - 1] = s.str(); break;
                case '/': table[row - 1][column - 1] = "0"; break;
                case '^': table[row - 1][column - 1] = "0";
            }
        }
        else //?
        {
            table[row - 1][column - 1] = "0"; //or "Invalid type"
        }
    }
    else
    {
        table[row - 1][column - 1] = "0";
    }
}

// public funcs
Table::Table(const size_t& rows, const size_t& columns) : table(rows)
{
    for (size_t row = 0; row < rows; row++) table[row].resize(columns);
}

void Table::edit(const std::string& expression)
{
    std::string expr = expression;
    std::string result = expr.substr(0, expr.find('=') - 1);
    expr.erase(0, result.size() + 3);

    std::string first_operand, second_operand;
    char oper;
    if (expr.find(' ') != std::string::npos)
    {
        first_operand = expr.substr(0, expr.find(' '));
        expr.erase(0, first_operand.size() + 1);

        oper = expr[0];
        second_operand = expr.substr(2, expr.size());
         
        if (oper != '+' && oper != '-' && oper != '*' && oper != '/' && oper != '^')
        {
            std::cout << "Invalid operator in expression!\n";
            return;
        }
    }
    else first_operand = expr.substr(0, expr.size());
    
    if (!is_cell(result)) { std::cout << "Invalid expression!\n"; return; }
    
    if (second_operand == "") execute(result, first_operand);
    else execute(result, first_operand, oper, second_operand);
}
