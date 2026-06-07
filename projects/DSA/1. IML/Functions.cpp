

bool member(const std::vector<double>& vec, const double number)
{
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i] == number) return true;

    return false;
}

void to_string(const double result, std::string& data)
{
    std::stringstream s;
    s << result << " ";
    data = s.str();
}
void vector_to_string(const std::vector<double>& vec, std::string& data)
{
    std::stringstream s;
    for (size_t i = 0; i < vec.size(); i++)
        s << vec[i] << " ";
    
    data = s.str();
}

double AGG_SUM(const std::vector<double>& vec)
{
    double result = 0;

    for (size_t i = 0; i < vec.size(); i++) result += vec[i];

    return result;
}

double AGG_PRO(const std::vector<double>& vec)
{
    double result = 1;

    for (size_t i = 0; i < vec.size(); i++) result *= vec[i];

    return result;
}

double AGG_AVG(const std::vector<double>& vec) { return AGG_SUM(vec) / vec.size(); }

std::vector<double> MAP_INC(const double& inc, std::vector<double>& vec)
{
    for (size_t i = 0; i < vec.size(); i++) vec[i] += inc;

    return vec;
}

std::vector<double> MAP_MLT(const double mul, std::vector<double> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        vec[i] *= mul;
    }
    return vec;
}

std::vector<double> SRT_REV(std::vector<double> vec)
{
    std::vector<double> temp;
    for (size_t i = 0; i < vec.size(); i++)
    {
        temp.push_back(vec[vec.size() - 1 - i]);
    }
    return temp;
}

std::vector<double> SRT_ASC(const std::vector<double>& vec)
{
    std::vector<double> temp = vec;

    for (size_t i = 0; i < temp.size(); i++)
        for (size_t j = i; j < temp.size(); j++)
            if (temp[i] > temp[j])
                std::swap(temp[i], temp[j]);

    return temp;
}

std::vector<double> SRT_DSC(const std::vector<double>& vec)
{
    std::vector<double> temp = vec;

    for (size_t i = 0; i < temp.size(); i++)
        for (size_t j = i; j < temp.size(); j++)
            if (temp[i] < temp[j])
                std::swap(temp[i], temp[j]);

    return temp;
}

std::vector<double> SRT_SLC(const std::vector<double>& vec, const size_t index)
{
    std::vector<double> temp;
    for (size_t i = 0; i < vec.size(); i++)
        if (i + 1 > index)
            temp.push_back(vec[i]);

    return temp;
}

std::vector<double> SRT_DST(const std::vector<double>& vec)
{
    std::vector<double> temp;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (!member(temp, vec[i]))
        {
            temp.push_back(vec[i]);
        }
    }
    return temp;
}

void execute(const std::string function, std::vector<double> real_data, std::string& data)
{
    if (function == "<AGG-SUM>")
    {
        double result = AGG_SUM(real_data);
        to_string(result, data);
    }
    else if (function == "<AGG-PRO>")
    {
        double result = AGG_PRO(real_data);
        to_string(result, data);
    }
    else if (function == "<AGG-AVG>")
    {
        double result = AGG_AVG(real_data);
        to_string(result, data);
    }
    else if (function == "<AGG-FST>")
    {
        double result = real_data[0];
        to_string(result, data);
    }
    else if (function == "<AGG-LST>")
    {
        double result = real_data[real_data.size() - 1];
        to_string(result, data);
    }
    else if (function.substr(0, function.find(' ')) == "<MAP-INC")
    {
        double inc = std::stod(extract_string(function, '\"', '\"'));
        std::vector<double> temp = MAP_INC(inc, real_data);
        
        vector_to_string(temp, data);
    }
    else if (function.substr(0, function.find(' ')) == "<MAP-MLT")
    {
        double mul = std::stod(extract_string(function, '\"', '\"'));
        std::vector<double> temp = MAP_MLT(mul, real_data);
        
        vector_to_string(temp, data);
    }
    else if (function == "<SRT-REV>")
    {
        std::vector<double> temp = SRT_REV(real_data);
        vector_to_string(temp, data);
    }
    else if (function == "<SRT-ORD \"ASC\">")
    {
        std::vector<double> temp = SRT_ASC(real_data);
        vector_to_string(temp, data);
    }
    else if (function == "<SRT-ORD \"DSC\">")
    {
        std::vector<double> temp = SRT_DSC(real_data);
        vector_to_string(temp, data);
    }
    else if (function.substr(0, function.find(' ')) == "<SRT-SLC")
    {
        size_t index = std::stoi(extract_string(function, '\"', '\"'));
        std::vector<double> temp = SRT_SLC(real_data, index);
        vector_to_string(temp, data);
    }
    else if (function == "<SRT-DST>")
    {
        std::vector<double> temp = SRT_DST(real_data);
        vector_to_string(temp, data);
    }
}