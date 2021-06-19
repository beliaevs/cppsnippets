#include<iostream>
#include<boost/type_index.hpp>

// variadic template for printing sizeof
template<typename T>
void print_sizes()
{
    std::cout << boost::typeindex::type_id<T>().pretty_name() << ": " << sizeof(T) << "\n";
}

template<typename T1, typename T2, typename ... Ts>
void print_sizes()
{
    std::cout << boost::typeindex::type_id<T1>().pretty_name() << ": " << sizeof(T1) << "\n";
    print_sizes<T2, Ts...>();
}

// simple macro for printing sizeof
#define PRINT_SIZE(type) std::cout << #type << ": " << sizeof(type) << "\n"
int main()
{
    PRINT_SIZE(int);
    PRINT_SIZE(long);
    PRINT_SIZE(long long);
    PRINT_SIZE(char*);

    print_sizes<int, long, long long, char*>();
}