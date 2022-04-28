#pragma once

#include<iostream>
#include<boost/type_index.hpp>
#include<sstream>

template<typename T>
void print_typename()
{
    std::cout << "typename: " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << "\n";
    std::cout << "typename&: " << boost::typeindex::type_id_with_cvr<T&>().pretty_name() << "\n";
    std::cout << "typename&&: " <<  boost::typeindex::type_id_with_cvr<T&&>().pretty_name() << "\n";
}

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