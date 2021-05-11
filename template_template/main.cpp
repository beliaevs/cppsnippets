#include<vector>
#include<deque>
#include<iostream>
#include<boost/type_index.hpp>

template<template<typename> class Out_container, template<typename> class In_container, typename T>
Out_container<T> resequence(const In_container<T>& i_seq)
{
    Out_container<T> res;
    for(auto a: i_seq)
    {
        res.push_back(a);
    }
    return res;
}


int main()
{
    auto v = std::vector({1,3,2,5,4});

    auto res = resequence<std::deque>(v);
    std::cout << typeid(res).name() << "\n";
    std::cout << boost::typeindex::type_id_with_cvr<decltype(res)>() << "\n";
    return 0;
}