#pragma once

#include<string>
#include<vector>
#include"util.h"

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

    template<typename Pred, typename... U>
    void insertIfV(Pred p, U&&... v)
    {
        auto push = [&](auto&& x){
            if(p(std::forward<decltype(x)>(x))){
                vals.push_back(std::forward<decltype(x)>(x));
            }
        };
        vals.reserve(vals.size() + sizeof...(U));
        (..., push(std::forward<U>(v)));
    }

    void setAll(const T& v)
    {
        for(auto&& e: vals) // works even for vector<bool>
            e = v;
    }

    std::vector<T> getValues() const // safe but slow
    {
        return vals;
    }

    const std::vector<T>& getValuesFlawed() const
    {
        return vals;
    }

    const std::vector<T>& getValuesRight() const&
    {
        return vals;
    }

    std::vector<T> getValuesRight() &&
    {
        return std::move(vals);
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