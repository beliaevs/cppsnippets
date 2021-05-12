#include<iostream>


template<typename T1, typename T2>
void f(T1, T2)
{
    std::cout << "T1, T2\n";
}

template<typename T>
void f(T, T)
{
    std::cout << "equal types\n";
}

void f(int, int)
{
    std::cout << "int version\n";
}


int main()
{
    f(1, 2);
    f(1., 2);
    f(1., 2.);
    return 0;
}