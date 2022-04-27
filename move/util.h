#pragma once

#include<iostream>
#include <boost/type_index.hpp>

template<typename T>
void print_typename()
{
    std::cout << "typename: " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << "\n";
    std::cout << "typename&: " << boost::typeindex::type_id_with_cvr<T&>().pretty_name() << "\n";
    std::cout << "typename&&: " <<  boost::typeindex::type_id_with_cvr<T&&>().pretty_name() << "\n";
}