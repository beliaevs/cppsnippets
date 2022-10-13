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

int g(int* p)
{
    return *p;
}

int h(int* p)
{
    int n = *p;
    return p ? *p : 0;
}

int main()
{
    int* pn = nullptr;
    f(*pn);
    return 0;
}