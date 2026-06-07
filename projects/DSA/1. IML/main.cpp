#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

#include "../../../c++/library/Strlib.cpp"
#include "Extract.cpp"
#include "Reverse.cpp"
#include "Convert.cpp"
#include "Functions.cpp"
#include "Examination.cpp"
#include "Tags.cpp"

void run(void)
{
    std::ifstream input;
    std::string inputFile, outputFile;
    do
    {
        std::cout << "Enter input file: ";
        std::getline(std::cin, inputFile);

        input.open(inputFile);
        if (!input.is_open())
        {
            std::cout << "Could not open " << inputFile << std::endl;
        }
        else 
        {
            std::cout << "Enter output file: "; 
            std::getline(std::cin, outputFile);
        }

    } while (!input.is_open());

    std::string line;
    std::getline(input, line);

    //openTags + closeTags = tags
    std::stack<std::string> tags = get_tags(line);
    std::stack<std::string> openTags;
    std::stack<std::string> closeTags;
    std::stack<std::string> data;

    size_t half = tags.size() / 2; //we know that the top is a close tag and they are half of the all
    while (half > 0)
    {
        closeTags.push(tags.top());
        tags.pop();
        half--;
    }
    half = tags.size(); //only open tags left - openTags + closeTags = tags
    while (half > 0)
    {
        openTags.push(tags.top());
        tags.pop();
        half--;
    }
    
    bool tags1 = examine(openTags), tags2 = examine(closeTags);
    if (!(tags1 && tags2)) //to check data too
    {
        std::cout << "Correct your file and then start it again!\n";
        return;
    }

    //For SRT-SLC to check the argument if its in the range or the vector
    
    openTags = reverse_tags(openTags);

    std::string result;
    while (!openTags.empty())
    {
        std::string function = openTags.top();
        std::string data = extract_data(line, openTags.top(), closeTags.top());
        std::string tobeReplaced = openTags.top() + data + closeTags.top();
        
        std::vector<double> realData = convert_data(data);
        execute(function, realData, data);
        
        line.replace(line.find(tobeReplaced), tobeReplaced.size(), " " + data);
        
        if (openTags.size() == 1)
            result = data;

        openTags.pop();
        closeTags.pop();
    }
    
    
    std::ofstream output(outputFile, std::ofstream::trunc|std::ofstream::out);
    //if (output.is_open())
        output << result;
    
    output.close();
    input.close();
}

int main(void)
{
    run();

    return 0;
}