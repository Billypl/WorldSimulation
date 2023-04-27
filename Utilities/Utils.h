#pragma once
#include <string>
#include <vector>

class Utils
{

public:

    static std::vector<std::string> splitString(const std::string& str, char separator)
    {
        std::vector<std::string> result;
        std::string splitted;
        for (char ch : str)
        {
            if (ch == separator)
            {
                result.push_back(splitted);
                splitted.clear();
                continue;
            }
            splitted += ch;
        }
        if(!splitted.empty())
            result.push_back(splitted);
        return result;
    }
};
