#pragma once

#include<string>
#include<vector>
#include<sstream>

std::string mem(const std::string& i_str)
{
    std::stringstream ss;
    ss << (void*)i_str.c_str() << ": " << i_str;
    return ss.str();
}

class Cont
{
    std::vector<std::string> vals;
    public:

    Cont() = default;

    void insert(const std::string& i_str)
    {
        vals.push_back(i_str);
    }

    void insert(std::string&& i_str)
    {
        vals.push_back(std::move(i_str));
    }

    void print() const
    {
        std::cout << "Cont:\n";

        for(const auto& v: vals)
        {
            std::cout << "> " << mem(v) << '\n';
        }
        
    }
};