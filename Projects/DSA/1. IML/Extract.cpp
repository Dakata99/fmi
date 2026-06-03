std::string extract_data(std::string source, std::string start, std::string end)
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
std::string extract_string(std::string source, const std::string start, const std::string end)
{
    size_t startIndex = source.find(start);
    if (startIndex == std::string::npos)
    {
        return source;
    }
    startIndex += start.length();
    size_t endIndex = source.find(end, startIndex);

    return source.substr(startIndex - 1, endIndex - startIndex + 2);
}
std::string extract_string(std::string source, const char end)
{
    size_t index = source.find(end);
    if (index == std::string::npos)
    {
        return source;
    }
    return source.substr(0, index);
}
std::string extract_string(std::string source, const char start, const char end)
{
    size_t startIndex = source.find(start);
    if (startIndex == std::string::npos)
    {
        return "";
    }
    startIndex++;
    size_t endIndex = source.find(end, startIndex);
    
    return source.substr(startIndex, endIndex - startIndex);
}
