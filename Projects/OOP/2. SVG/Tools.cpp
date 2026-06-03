#include "Tools.h"

std::string extract_string(std::string source, std::string start, std::string end)
{
    size_t start_index = source.find(start);

    if (start_index == std::string::npos) return source;
    
    start_index += start.length();
    size_t end_index = source.find(end, start_index);

    return source.substr(start_index, end_index - start_index);
}

std::string take_data(std::string& argument)
{
    std::string result;
    if (argument.find('\"') != std::string::npos)
    {
        result = extract_string(argument, "\"", "\"");
        argument.erase(0, argument.find(' ') + 1);
    }
    else 
    {
        result = argument.substr(0, argument.find(' '));
        argument.erase(0, result.size() + 1);
    }

    return result;
}

bool valid_arg(const std::string& argument) // TODO
{
    if (argument.find(' ') != std::string::npos) //has space
    {
        std::string leftSide = argument.substr(0, argument.find(' ')), 
                    rightSide = argument.substr(argument.find(' ') + 1, argument.size());
    }
    return false;
}