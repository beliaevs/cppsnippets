#include<iostream>


template<typename T1, typename T2>
void f(T1 t1, T2 t2)
{
    std::cout << "Root template\n";
}

template<typename T>
void f(T t1, T t2)
{
    std::cout << "equal types\n";
}


int main()
{
    f(1, 2);
    f(1., 2);
    return 0;
}