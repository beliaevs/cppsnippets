#include<valarray>
#include<iostream>

void valarray_test()
{
    std::cout << "valarray_test:\n";
    std::valarray<int> vals = {423, 621, 21, 1123};

    for(auto a: vals)
        std::cout << a << " ";

    std::cout << "\n";
    vals >>= 1;

    std::cout << "after rshift:\n";
    for(auto a: vals)
        std::cout << a << " ";

    std::cout << "\n";
    vals += 10;

    std::cout << "after +10:\n";
    for(auto a: vals)
        std::cout << a << " ";

    std::cout << "\n";
}