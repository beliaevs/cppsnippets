#include<iostream>
#include<iomanip>
#include<boost/type_index.hpp>

template<typename T>
void print_typeinfo()
{
    std::cout << std::setw(12) << boost::typeindex::type_id<T>().pretty_name() << "\t" << sizeof(T) << "\t" << alignof(T) << "\n";
}

int main()
{
    std::cout << std::setw(12) << "Type Name" << "\tSize\tAlignment\n";
    print_typeinfo<char>();
    print_typeinfo<short>();
    print_typeinfo<int>();
    print_typeinfo<long>();
    print_typeinfo<long long>();
    print_typeinfo<float>();
    print_typeinfo<double>();
    print_typeinfo<long double>();
    print_typeinfo<void*>();
    print_typeinfo<char*>();
    print_typeinfo<int*>();
}