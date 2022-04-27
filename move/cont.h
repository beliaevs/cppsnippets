#pragma once

#include<string>
#include<vector>
#include<sstream>
#include"util.h"

inline std::string mem(const std::string& i_str)
{
    std::stringstream ss;
    ss << static_cast<const void*>(i_str.c_str()) << ": " << i_str;
    return ss.str();
}

template<typename T>
std::string mem(const T& arg)
{
    std::stringstream ss;
    ss << static_cast<const void*>(std::addressof(arg)) << ": " << arg << "\n";
    return ss.str();
}

template<typename T>
class ContT
{
    std::vector<T> vals;

    public:
    ContT() = default;
    void insert(T v)
    {
        // it works if you have to create a copy anyway
        vals.push_back(std::move(v));
    }

    // not recommended
    template<typename Pred>
    bool insertIf(T v, Pred p)
    {
        if(p(v))
        {
            vals.push_back(std::move(v));
            return true;
        }
        return false;
    }

    template<typename U, typename Pred>
    bool insertIf1(U&& v, Pred p) // universal or forwarding reference
    {
        print_typename<U>();
        if(p(v))
        {
            vals.push_back(std::forward<U>(v));
            // vals.push_back(std::move(v)); // danger! insertIf1(a) will leave a empty without notice 
            return true;
        }
        return false;
    }

    void print() const
    {
        std::cout << "ContT<>:\n";

        for(const auto& v: vals)
        {
            std::cout << "> " << mem(v) << '\n';
        }
    }
};

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

    void insert(const std::string&& i_str)
    {
        std::cout << "insert const&&\n" << "\n";
        vals.push_back(i_str);
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