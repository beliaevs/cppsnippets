#include<iostream>
#include<cmath>
#include<boost/type_index.hpp>
#include "all_tests.h"


void run_all()
{
    valarray_test();
}

int main()
{
    auto a = std::sqrt(2);
    std::cout << boost::typeindex::type_id<decltype(a)>().pretty_name() << ": " << a << "\n";
    run_all();
}