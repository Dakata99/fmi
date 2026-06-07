std::vector<double> convert_data(std::string source)
{
    if (source[0] == ' ')
    {
        source = source.substr(1, source.size() - 1);
    }
    if (source[source.size() - 1] == ' ')
    {
        source = source.substr(0, source.size() - 1);
    }
    
    std::vector<double> vec;
    while (source != "")
    {
        std::string temp = extract_string(source, ' ');
        source = source.erase(0, temp.size() + 1);
        
        double number = std::stod(temp);
        vec.push_back(number);
    }
    return vec;
}
// std::stack<std::vector<double>> convert2(std::stack<std::string>& data)
// {
//     std::stack<std::vector<double>> realData;
//     while (!data.empty())
//     {
//         realData.push(convertData(data.top()));
//         data.pop();
//     }
//     return realData;
// }
// std::vector<std::vector<double>> convert(std::stack<std::string>& data)
// {
//     std::vector<std::vector<double>> realData;
//     while (!data.empty())
//     {
//         realData.push_back(convertData(data.top()));
//         data.pop();
//     }
//     return realData;
// }
