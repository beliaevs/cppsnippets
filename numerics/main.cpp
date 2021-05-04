#include<iostream>
#include<cmath>
#include<boost/type_index.hpp>


int main()
{
    auto a = std::sqrt(2);
    std::cout << boost::typeindex::type_id<decltype(a)>().pretty_name() << ": " << a << "\n";
}