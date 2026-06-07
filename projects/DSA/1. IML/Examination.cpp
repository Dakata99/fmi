#include "../../../c++/library/Strlib.h"

bool check_argument(const std::string openTag)
{
    std::string argument = extract_string(openTag, '\"', '\"');

    if (argument == "ASC" || argument == "DSC" || is_number(argument)) return true;

    return false;
}

std::string opposite(const std::string& open_tag)
{
    if (open_tag == "<MAP-INC") return "</MAP-INC>";
    else if (open_tag == "<MAP-MLT") return "</MAP-MLT>";
    else if (open_tag == "<AGG-SUM>") return "</AGG-SUM>";
    else if (open_tag == "<AGG-PRO>") return "</AGG-PRO>";
    else if (open_tag == "<AGG-AVG>") return "</AGG-AVG>";
    else if (open_tag == "<AGG-FST>") return "</AGG-FST>";
    else if (open_tag == "<AGG-LST>") return "</AGG-LST>";
    else if (open_tag == "<SRT-REV>") return "</SRT-REV>";
    else if (open_tag == "<STR-ORD \"ASC\">") return "</SRT-ORD>";
    else if (open_tag == "<STR-ORD \"DSC\">") return "</SRT-ORD>";
    else if (open_tag == "<STR-SLC") return "</SRT-SLC>";
    else if (open_tag == "<STR-DST>") return "</SRT-DST>";

    return "Invalid tag!\n";
}

bool check_tag(const std::string tag)
{
    if ((tag.substr(0, tag.find(' ')) == "<MAP-INC" && check_argument(tag)) || (tag.substr(0, tag.find(' ')) == "<MAP-MLT" && check_argument(tag)))
    {
        return true;
    }
    else if (tag == "<AGG-SUM>" || tag == "<AGG-PRO>" || tag == "<AGG-AVG>" || tag == "<AGG-FST>" || tag == "<AGG-LST>")
    {
        return true;
    }
    else if (tag == "<SRT-REV>" || tag == "<SRT-ORD \"ASC\">" || tag == "<SRT-ORD \"DSC\">" || (tag.substr(0, tag.find(' ')) == "<SRT-SLC" && check_argument(tag)) || tag == "<SRT-DST>")
    {
        return true;
    }
    else if (tag == "</MAP-INC>" || tag == "</MAP-MLT>")
    {
        return true;
    }
    else if (tag == "</AGG-SUM>" || tag == "</AGG-PRO>" || tag == "</AGG-AVG>" || tag == "</AGG-FST>" || tag == "</AGG-LST>")
    {
        return true;
    }
    else if (tag == "</SRT-REV>" || tag == "</SRT-ORD>" || tag == "</SRT-SLC>" || tag == "</SRT-DST>")
    {
        return true;
    }
    
    return false;
}

bool examine(std::stack<std::string> tags)
{
    static size_t index = 1;
    bool flag = true;
    while (!tags.empty())
    {
        if (!check_tag(tags.top()))
        {    
            std::cout << index++ << ". Invalid tag - " << tags.top() << std::endl; 
            flag = false;
        }

        tags.pop();
    }

    return flag;
}