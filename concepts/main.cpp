#include<iostream>
#include<concepts>

template <std::default_initializable T>
T make_T() { return T(); }

int main()
{
    auto a = make_T<int>();
    std::cout << a << std::endl;
    return 0;
}