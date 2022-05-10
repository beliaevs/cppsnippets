#include<iostream>

void f(const int& n)
{
    if(&n == nullptr)
    {
        std::cout << "nullptr dereferencing\n";
    }
    else
    {
        std::cout << "valid\n";
    }
    return;
}

int main()
{
    int* pn = nullptr;
    f(*pn);
    return 0;
}